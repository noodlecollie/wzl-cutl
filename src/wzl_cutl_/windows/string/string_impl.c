#include <stdio.h>
#include "wzl_cutl/string.h"

WZL_CUTL_PUBLIC(int) wzl_vsprintf(char* buffer, size_t numberOfElements, const char* format, va_list argptr)
{
	return vsprintf_s(buffer, numberOfElements, format, argptr);
}
