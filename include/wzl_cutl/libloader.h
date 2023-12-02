#ifndef WZL_CUTL_LIBLOADER_H
#define WZL_CUTL_LIBLOADER_H

#include <stdbool.h>
#include "wzl_cutl/libexport.h"

// Typedef: wzl_opaque_funcptr
// Alias for a generic function pointer.
//
// Attempting to cast void* to a function pointer
// when compiling with -pedantic on GCC causes a warning.
// <wzl_opaque_funcptr> is intended to represent a general
// function pointer which can be cast to different function
// pointers without generating warnings.
typedef void (*wzl_opaque_funcptr)(void);

// Function: wzl_load_library
// Attempts to load a library from the system.
//
// If the library cannot be loaded, NULL is returned.
// <wzl_get_last_library_error> can be used to fetch
// a string describing the error that occurred.
//
// Parameters:
//
//   filename - Name of library to load.
//
// Returns:
//
//   Handle to library, or NULL if the library could
//   not be loaded.
void* wzl_load_library(const char* filename);

// Function: wzl_unload_library
// Unloads a library that has previously been loaded.
//
// If the passed handle was not returned from a previous
// call to <wzl_load_library>, behaviour is undefined.
//
// Parameters:
//
//   handle - Handle to a previously loaded library.
bool wzl_unload_library(void* handle);

// Function: wzl_get_last_library_error
// Returns a string representing the last error that
// occurred when calling a library-related function.
//
// Returns:
//
//   Human-readable string describing the last error.
const char* wzl_get_last_library_error(void);

void* wzl_get_library_symbol(void* handle, const char* symbol);

// Function: wzl_get_library_function
// Returns a pointer to the function with the specified
// name within the specified library.
//
// If the function is not able to be looked up, NULL
// is returned. <wzl_get_last_library_error> can be used
// to fetch a string describing the error that occurred.
//
// Parameters:
//
//   handle - Handle to the library which holds the function.
//   name   - Name of the function to look up.
//
// Returns:
//
//   Pointer to the requested function, or NULL if it could not
//   be obtained.
static inline wzl_opaque_funcptr wzl_get_library_function(void* handle, const char* name)
{
#ifndef _MSC_VER
// No way to cast between void* and a function pointer without suppressing -pedantic...
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
#endif // _MSC_VER

	return (wzl_opaque_funcptr)wzl_get_library_symbol(handle, name);

#ifndef _MSC_VER
#pragma GCC diagnostic pop
#endif // _MSC_VER
}

#endif  // WZL_CUTL_LIBLOADER_H
