#include <string.h>
#include <stdio.h>
#include <ctype.h>
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

WZL_CUTL_PUBLIC(size_t) wzl_strcpy(char* WZL_ATTR_PARAM_RESTRICT dest, size_t destSize, const char* WZL_ATTR_PARAM_RESTRICT src)
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

	char* WZL_ATTR_PARAM_RESTRICT cursor = dest;

	while ( *src && destSize > 1 )
	{
		*(cursor++) = *(src++);
		--destSize;
	}

	*cursor = '\0';

	return cursor - dest;
}

WZL_CUTL_PUBLIC(bool) wzl_strtrimspace(const char* str, const char** begin, const char** end)
{
	if ( !str )
	{
		if ( begin )
		{
			*begin = NULL;
		}

		if ( end )
		{
			*end = NULL;
		}

		return false;
	}

	if ( !(*str) )
	{
		if ( begin )
		{
			*begin = str;
		}

		if ( end )
		{
			*end = str;
		}

		return false;
	}

	bool trimmed = false;
	const char* tempBegin = NULL;
	const char* tempEnd = NULL;

	const char* cursor = str;

	while ( *cursor )
	{
		if ( isspace(*cursor) )
		{
			trimmed = true;
		}
		else
		{
			if ( !tempBegin )
			{
				tempBegin = cursor;
			}

			tempEnd = cursor;
		}

		++cursor;
	}

	if ( begin )
	{
		*begin = tempBegin ? tempBegin : cursor;
	}

	if ( end )
	{
		*end = tempEnd ? (tempEnd + 1) : cursor;
	}

	return trimmed;
}
