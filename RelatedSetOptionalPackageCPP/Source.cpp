#include "pch.h"
#include "MyPluginControl.h"
#include <winrt/RelatedSetCommon.h>
#include <winrt/RelatedSetOptionalPackageCppDll.h>

extern "C" {
	__declspec(dllexport) void Entry(winrt::RelatedSetCommon::IPluginWrapper pluginWrapper)
	{
		// Create TestControl of RelatedSetOptionalPackageCppDll in RelatedSetOptionalPackageCpp.exe module will throw exceptions.
		// TODO: Find the reason
		assert(false);
		winrt::RelatedSetOptionalPackageCppDll::TestControl control{ nullptr };
		control = winrt::RelatedSetOptionalPackageCppDll::TestControl();
		pluginWrapper.Plugins().Append(control);
	}
}