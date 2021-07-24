#pragma once

#include "winrt/Windows.UI.Xaml.h"
#include "winrt/Windows.UI.Xaml.Markup.h"
#include "winrt/Windows.UI.Xaml.Interop.h"
#include "winrt/Windows.UI.Xaml.Controls.Primitives.h"
#include "TestControl.g.h"

namespace winrt::RelatedSetOptionalPackageCppDll::implementation
{
    struct TestControl : TestControlT<TestControl>
    {
        TestControl();
    };
}

namespace winrt::RelatedSetOptionalPackageCppDll::factory_implementation
{
    struct TestControl : TestControlT<TestControl, implementation::TestControl>
    {
    };
}
