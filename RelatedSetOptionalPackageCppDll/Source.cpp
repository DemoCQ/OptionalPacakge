#include "pch.h"
#include <winrt/RelatedSetCommon.h>
#include "TestControl.h"

extern "C" {
	__declspec(dllexport) void Entry(winrt::RelatedSetCommon::IPluginWrapper pluginWrapper)
	{
		winrt::RelatedSetOptionalPackageCppDll::TestControl control;
		pluginWrapper.Plugins().Append(control);
	}
}