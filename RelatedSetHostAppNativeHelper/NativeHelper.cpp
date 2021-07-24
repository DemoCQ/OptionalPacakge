#include "pch.h"
#include "NativeHelper.h"
#include "NativeHelper.g.cpp"
#include <string>
#include <sstream>
#include <winrt/Windows.UI.Xaml.Controls.h>
#include <winrt/Windows.Foundation.Collections.h>

std::wstring GetMessage(HRESULT hr)
{
    LPVOID lpMsgBuf;
    LPVOID lpDisplayBuf;

    FormatMessageW(
        FORMAT_MESSAGE_ALLOCATE_BUFFER |
        FORMAT_MESSAGE_FROM_SYSTEM |
        FORMAT_MESSAGE_IGNORE_INSERTS,
        NULL,
        hr,
        MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
        (LPWSTR)&lpMsgBuf,
        0, NULL);

    auto msg = std::wstring((LPWSTR)lpMsgBuf);
    CoTaskMemFree(lpMsgBuf);
    
    return msg;
}

typedef void (*Entry)(winrt::RelatedSetCommon::IPluginWrapper pluginWrapper);

namespace winrt::RelatedSetHostAppNativeHelper::implementation
{
    hstring NativeHelper::LoadDll(hstring const& path)
    {
        auto handle = LoadPackagedLibrary(path.c_str(), 0);
        if (handle == nullptr)
        {
            return GetMessage(GetLastError()).c_str();
        }
        auto entry = (Entry)GetProcAddress(handle, "Entry");
        if (entry == nullptr)
        {
            return L"Can not find the proc address";
        }

        auto dllHandle = LoadPackagedLibrary(L"RelatedSetOptionalPackageCPPDll.dll", 0);
        entry(_pluginWrapper);

        std::wstringstream ss;
        ss << L"Entry function executed" << std::endl;
        return ss.str().c_str();
    }

    hstring NativeHelper::AddPlugins(winrt::Windows::UI::Xaml::Controls::StackPanel panel)
    {
        for (int i = 0; i < _pluginWrapper.Plugins().Size(); i++)
        {
            auto plugin = _pluginWrapper.Plugins().GetAt(i);
            panel.Children().Append(plugin);
        }

        return L"";
    }
}
