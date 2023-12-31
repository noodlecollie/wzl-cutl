#include <string.h>
#include <stdio.h>
#include "wzl_cutl/string.h"
#include "wzl_cutl/math.h"
#include "wzl_cutl_/common/memory/memory_impl.h"

WZL_CUTL_PUBLIC(char*) wzl_strdup(const char* str)
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
