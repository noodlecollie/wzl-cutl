#include "wzl_cutl_/common/memory/memory_impl.h"
#include "wzl_cutl/memory.h"
#include "wzl_cutl/string.h"

wzl_memory_delegates g_memory_delegates;

WZL_CUTL_PUBLIC(void) wzl_set_memory_delegates(wzl_memory_delegates delegates)
{
	g_memory_delegates = delegates;
}

char* wzl_strdup_if_delegated(char* str)
{
	if ( !str || !wzl_has_custom_malloc() )
	{
		return str;
	}

	char* out = wzl_strdup(str);
	free(str);
	return out;
}

void* wzl_duplicate_if_delegated(void* data, size_t length)
{
	if ( !data || !wzl_has_custom_malloc() )
	{
		return data;
	}

	void* out = length > 0 ? wzl_malloc_(length) : NULL;

	if ( length > 0 )
	{
		memcpy(out, data, length);
	}

	free(data);
	return out;
}
