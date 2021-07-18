#pragma once
#include "NativeHelper.g.h"

namespace winrt::RelatedSetHostAppNativeHelper::implementation
{
    struct NativeHelper : NativeHelperT<NativeHelper>
    {
        NativeHelper() = default;

        hstring LoadDll(hstring const& path);
    };
}
namespace winrt::RelatedSetHostAppNativeHelper::factory_implementation
{
    struct NativeHelper : NativeHelperT<NativeHelper, implementation::NativeHelper>
    {
    };
}
