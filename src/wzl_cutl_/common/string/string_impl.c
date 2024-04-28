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

WZL_CUTL_PUBLIC(size_t) wzl_strcpy(char* restrict dest, size_t destSize, const char* restrict src)
{
	if ( !dest || destSize < 1 )
	{
		return 0;
	}

	if ( !src )
	{
		dest[0] = '\0';
		return 0;
	}

	char* restrict cursor = dest;

	while ( *src && destSize > 1 )
	{
		*(cursor++) = *(src++);
		--destSize;
	}

	*cursor = '\0';

	return cursor - dest;
}
