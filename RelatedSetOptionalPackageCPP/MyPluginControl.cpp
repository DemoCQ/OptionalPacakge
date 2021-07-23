#include "pch.h"
#include "MyPluginControl.h"
#if __has_include("MyPluginControl.g.cpp")
#include "MyPluginControl.g.cpp"
#endif

using namespace winrt;
using namespace Windows::UI::Xaml;

using Application = ::winrt::Windows::UI::Xaml::Application;
using ComponentResourceLocation = ::winrt::Windows::UI::Xaml::Controls::Primitives::ComponentResourceLocation;
using Uri = ::winrt::Windows::Foundation::Uri;

namespace winrt::RelatedSetOptionalPackageCPP::implementation
{
    MyPluginControl::MyPluginControl()
    {
        Uri resourceLocator{ L"ms-appx://RelatedSetOptionalPackageCPP/MyPluginControl.xaml" };
        Application::LoadComponent(*this, resourceLocator, ComponentResourceLocation::Application);
    }
}
