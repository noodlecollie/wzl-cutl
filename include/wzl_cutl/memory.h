#ifndef WZL_CUTL_MEMORY_H
#define WZL_CUTL_MEMORY_H

#include "wzl_cutl/libexport.h"
#include "wzl_cutl/types.h"

// Struct: wzl_memory_delegates
// Struct holding function pointers which may supply
// overrides for memory allocation functions.
typedef struct wzl_memory_delegates
{
	// Property: malloc_func
	// Pointer to function to be called instead of system malloc().
	wzl_voidptr (*malloc_func)(wzl_size size);

	// Property: free_func
	// Pointer to function to be called instead of system free().
	wzl_void (*free_func)(wzl_voidptr ptr);

	// Pointer: callc_func
	// Pointer to function to be called instead of system calloc().
	wzl_voidptr (*calloc_func)(wzl_size num, wzl_size size);

	// Pointer: realloc_func
	// Pointer to function to be called instead of system realloc().
	wzl_voidptr (*realloc_func)(wzl_voidptr ptr, wzl_size size);
} wzl_memory_delegates;

// Function: wzl_set_memory_delegates
// Sets the static copy of memory delegate functions used internally by the library.
//
// For any delegate in the provided struct, if the function pointer is set
// then this function is called instead of the respective system library function.
// If the function pointer is not set, the system library function is called instead.
//
// Calling this function with a zeroed delegates struct will essentially reset
// all memory function bindings, meaning the system library functions will be
// used instead.
//
// Before the first call to this function, no memory delegates are set
// and the system library functions are used by default.
//
// Parameters:
//
//   delegates - Struct containing delegate function pointers that
//               should be set.
//
// Note:
//
//   This function is not thread-safe.
WZL_CUTL_PUBLIC(wzl_void) wzl_set_memory_delegates(wzl_memory_delegates delegates);

#endif  // WZL_CUTL_MEMORY_H
