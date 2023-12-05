#include <string.h>
#include <stdio.h>
#include "wzl_cutl/string.h"
#include "wzl_cutl/math.h"
#include "wzl_cutl_/common/memory/memory_impl.h"

WZL_CUTL_PUBLIC(char*) wzl_duplicate_string(const char* str)
{
	if ( !str )
	{
		return NULL;
	}

	const size_t size = strlen(str) + 1;
	char* out = wzl_malloc_(size);

	char* cursor = out;

	while ( *str )
	{
		*(cursor++) = *(str++);
	}

	*cursor = '\0';

	return out;
}

WZL_CUTL_PUBLIC(int) wzl_vsnprintf(char* buffer, size_t buffer_size, const char* format, va_list args)
{
	const int result = vsnprintf(buffer, buffer_size, format, args);

	if ( result < 0 )
	{
		// Something went wrong.
		// Make absolutely sure the buffer is terminated.
		if ( buffer && buffer_size > 0 )
		{
			buffer[0] = '\0';
		}

		return result;
	}

	if ( buffer && buffer_size > 0 )
	{
		// Make absolutely sure the buffer is terminated.
		buffer[WZL_MIN(buffer_size - 1, (size_t)result)] = '\0';
	}

	return result;
}
