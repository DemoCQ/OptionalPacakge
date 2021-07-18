#include "pch.h"
#include "NativeHelper.h"
#include "NativeHelper.g.cpp"
#include <string>
#include <sstream>

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

namespace winrt::RelatedSetHostAppNativeHelper::implementation
{
    typedef int (*Entry)();
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
        std::wstringstream ss;
        ss << L"Entry function result:" << entry() << std::endl;
        return ss.str().c_str();
    }
}
