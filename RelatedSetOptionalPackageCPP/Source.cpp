#include "pch.h"
#include <winrt/RelatedSetCommon.h>

extern "C" {
	__declspec(dllexport) void Entry(winrt::RelatedSetCommon::IPluginWrapper pluginWrapper)
	{
		// Even if we can export a function from .exe, but after we load it with LoadLibrary, we can not use any extern functions which is imported by the .exe,
		// Since the Import Address Table is not correctly configured, which means that all calls to imported functions will crash.
		// So we can put resouces file in the project RelatedSetOptionalPackageCPP, but for any code we used, we should be better put it into RelatedSetOptionalPackageCppDll.
		// Then we can load RelatedSetOptionalPackageCppDll.dll to use all of our custom user control and code.
		assert(false);
	}
}