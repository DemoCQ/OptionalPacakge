#pragma once

#include "winrt/Windows.UI.Xaml.h"
#include "winrt/Windows.UI.Xaml.Markup.h"
#include "winrt/Windows.UI.Xaml.Interop.h"
#include "winrt/Windows.UI.Xaml.Controls.Primitives.h"
#include "MyPluginControl.g.h"

namespace winrt::RelatedSetOptionalPackageCPP::implementation
{
    struct MyPluginControl : MyPluginControlT<MyPluginControl>
    {
        MyPluginControl();
    };
}

namespace winrt::RelatedSetOptionalPackageCPP::factory_implementation
{
    struct MyPluginControl : MyPluginControlT<MyPluginControl, implementation::MyPluginControl>
    {
    };
}
