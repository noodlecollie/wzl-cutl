#ifndef WZL_CUTL_MEMORY_MEMORY_IMPL_H
#define WZL_CUTL_MEMORY_MEMORY_IMPL_H

#include <stdlib.h>
#include "wzl_cutl/memory.h"

extern wzl_memory_delegates g_memory_delegates;

static inline wzl_voidptr wzl_malloc_(wzl_size size)
{
	return g_memory_delegates.malloc_func ? g_memory_delegates.malloc_func(size) : malloc(size);
}

static inline wzl_void wzl_free_(wzl_voidptr ptr)
{
	return g_memory_delegates.free_func ? g_memory_delegates.free_func(ptr) : free(ptr);
}

static inline wzl_voidptr wzl_calloc_(wzl_size num, wzl_size size)
{
	return g_memory_delegates.calloc_func ? g_memory_delegates.calloc_func(num, size) : calloc(num, size);
}

static inline wzl_voidptr wzl_realloc_(wzl_voidptr ptr, wzl_size size)
{
	return g_memory_delegates.realloc_func ? g_memory_delegates.realloc_func(ptr, size) : realloc(ptr, size);
}

#define WZL_MALLOC_STRUCT(typeName) ((typeName)wzl_malloc_(sizeof(typeName)))
#define WZL_CALLOC_STRUCT(typeName) ((typeName)wzl_calloc_(1, sizeof(typeName)))

#endif  // WZL_CUTL_MEMORY_MEMORY_IMPL_H
