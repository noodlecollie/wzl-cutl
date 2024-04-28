#include <stdio.h>
#include <string.h>
#include "wzl_cutl/string.h"

WZL_CUTL_PUBLIC(int) wzl_vsprintf(char* buffer, size_t numberOfElements, const char* format, va_list argptr)
{
	int returnVal = vsnprintf(buffer, numberOfElements, format, argptr);

	if ( buffer && numberOfElements > 0 )
	{
		if ( returnVal >= 0 )
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
