#include <string.h>
#include "wzl_cutl/string.h"
#include "wzl_cutl_/memory/memory_impl.h"

WZL_CUTL_PUBLIC(wzl_size) wzl_strlen(wzl_char* str)
{
	return str ? strlen(str) : 0;
}

WZL_CUTL_PUBLIC(wzl_char*) wzl_duplicate_string(wzl_char* str)
{
	if ( !str )
	{
		return WZL_NULLPTR;
	}

	const size_t size = wzl_strlen(str) + 1;
	wzl_char* out = wzl_malloc_(size);

	char* cursor = out;

	while ( *str )
	{
		*(cursor++) = *(str++);
	}

	*cursor = '\0';

	return out;
}
