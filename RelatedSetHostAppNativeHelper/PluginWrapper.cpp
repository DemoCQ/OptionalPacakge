#include "pch.h"
#include "PluginWrapper.h"
#include "PluginWrapper.g.cpp"

namespace winrt::RelatedSetHostAppNativeHelper::implementation
{
    winrt::Windows::Foundation::Collections::IVector<winrt::Windows::UI::Xaml::Controls::UserControl> PluginWrapper::Plugins()
    {
        return _plugins;
    }
}
