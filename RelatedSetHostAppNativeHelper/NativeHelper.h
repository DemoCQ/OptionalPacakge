#pragma once
#include "NativeHelper.g.h"
#include "winrt/RelatedSetCommon.h"

namespace winrt::RelatedSetHostAppNativeHelper::implementation
{
    struct NativeHelper : NativeHelperT<NativeHelper>
    {
        NativeHelper() = default;

        hstring LoadDll(hstring const& path);

        hstring AddPlugins(winrt::Windows::UI::Xaml::Controls::StackPanel panel);

    private:
        winrt::RelatedSetCommon::PluginWrapper _pluginWrapper;
    };
}
namespace winrt::RelatedSetHostAppNativeHelper::factory_implementation
{
    struct NativeHelper : NativeHelperT<NativeHelper, implementation::NativeHelper>
    {
    };
}
