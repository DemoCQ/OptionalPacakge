#pragma once
#include "PluginWrapper.g.h"

namespace winrt::RelatedSetHostAppNativeHelper::implementation
{
    struct PluginWrapper : PluginWrapperT<PluginWrapper>
    {
        PluginWrapper() = default;

        winrt::Windows::Foundation::Collections::IVector<winrt::Windows::UI::Xaml::Controls::UserControl> Plugins();

    private:
        winrt::Windows::Foundation::Collections::IVector<winrt::Windows::UI::Xaml::Controls::UserControl> _plugins{ winrt::single_threaded_vector<winrt::Windows::UI::Xaml::Controls::UserControl>() };
    };
}
namespace winrt::RelatedSetHostAppNativeHelper::factory_implementation
{
    struct PluginWrapper : PluginWrapperT<PluginWrapper, implementation::PluginWrapper>
    {
    };
}
