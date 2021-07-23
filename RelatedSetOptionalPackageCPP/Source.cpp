#include "pch.h"
#include <winrt/RelatedSetHostAppNativeHelper.h>
#include "winrt/RelatedSetOptionalPackageCPP.h"
extern "C" {
	__declspec(dllexport) void Entry(winrt::RelatedSetHostAppNativeHelper::IPluginWrapper pluginWrapper)
	{
		winrt::RelatedSetOptionalPackageCPP::XamlMetaDataProvider provider;
		auto plugin = provider.GetXamlType(winrt::xaml_typename< winrt::RelatedSetOptionalPackageCPP::MyPluginControl>()).ActivateInstance();
		pluginWrapper.Plugins().Append(plugin.as<winrt::Windows::UI::Xaml::Controls::UserControl>());
	}
}