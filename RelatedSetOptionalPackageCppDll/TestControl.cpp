#include "pch.h"
#include "TestControl.h"
#if __has_include("TestControl.g.cpp")
#include "TestControl.g.cpp"
#endif

using namespace winrt;
using namespace Windows::UI::Xaml;
using Application = ::winrt::Windows::UI::Xaml::Application;
using ComponentResourceLocation = ::winrt::Windows::UI::Xaml::Controls::Primitives::ComponentResourceLocation;
using Uri = ::winrt::Windows::Foundation::Uri;

namespace winrt::RelatedSetOptionalPackageCppDll::implementation
{
    TestControl::TestControl()
    {
        Uri resourceLocator{ L"ms-appx://RelatedSetOptionalPackageCPP/RelatedSetOptionalPackageCppDll/TestControl.xaml" };
        Application::LoadComponent(*this, resourceLocator, ComponentResourceLocation::Application);
    }
}
