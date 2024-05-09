#include <stdio.h>
#include "wzl_cutl/string.h"

WZL_CUTL_PUBLIC(int) wzl_vsprintf(char* buffer, size_t numberOfElements, const char* format, va_list argptr)
{
	return vsprintf_s(buffer, numberOfElements, format, argptr);
}

WZL_CUTL_PUBLIC(bool) wzl_strequals(const char* a, const char* b)
{
	if ( a == b )
	{
		return true;
	}

	if ( (a == NULL) != (b == NULL) )
	{
		return false;
	}

	return strcmp(a, b) == 0;
}

WZL_CUTL_PUBLIC(bool) wzl_strnequals(const char* a, const char* b, size_t count)
{
	if ( a == b )
	{
		return true;
	}

	if ( (a == NULL) != (b == NULL) )
	{
		return false;
	}

	return strncmp(a, b, count) == 0;
}

WZL_CUTL_PUBLIC(bool) wzl_strequali(const char* a, const char* b)
{
	if ( a == b )
	{
		return true;
	}

	if ( (a == NULL) != (b == NULL) )
	{
		return false;
	}

	return _stricmp(a, b) == 0;
}

WZL_CUTL_PUBLIC(bool) wzl_strnequali(const char* a, const char* b, size_t count)
{
	if ( a == b )
	{
		return true;
	}

	if ( (a == NULL) != (b == NULL) )
	{
		return false;
	}

	return _strnicmp(a, b, count) == 0;
}
