#pragma once
#include "NativeHelper.g.h"
#include "PluginWrapper.h"

namespace winrt::RelatedSetHostAppNativeHelper::implementation
{
    struct NativeHelper : NativeHelperT<NativeHelper>
    {
        NativeHelper() = default;

        hstring LoadDll(hstring const& path);

        hstring AddPlugins(winrt::Windows::UI::Xaml::Controls::StackPanel panel);

    private:
        winrt::RelatedSetHostAppNativeHelper::PluginWrapper _pluginWrapper;
    };
}
namespace winrt::RelatedSetHostAppNativeHelper::factory_implementation
{
    struct NativeHelper : NativeHelperT<NativeHelper, implementation::NativeHelper>
    {
    };
}
