#include <stdio.h>
#include <string.h>
#include "wzl_cutl/string.h"

WZL_CUTL_PUBLIC(int) wzl_vsprintf(char* buffer, size_t numberOfElements, const char* format, va_list argptr)
{
	int returnVal = vsnprintf(buffer, numberOfElements, format, argptr);

	if ( buffer && numberOfElements > 0 )
	{
		if ( returnVal > 0 )
		{
			size_t numChars = (size_t)returnVal;

			if ( numChars >= numberOfElements )
			{
				buffer[numberOfElements - 1] = '\0';
			}
		}
		else
		{
			buffer[0] = '\0';
		}
	}

	return returnVal;
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

	return strcasecmp(a, b) == 0;
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

	return strncasecmp(a, b, count) == 0;
}
