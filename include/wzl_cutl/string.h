// File: string.h
// Defines functions that manipulate strings.

#ifndef WZL_CUTL_STRING_H
#define WZL_CUTL_STRING_H

#include <stdarg.h>
#include "wzl_cutl/libexport.h"

// Function: wzl_duplicate_string
// Given an input string, makes a dynamic copy of this string
// and returns it. Memory is allocated according to the
// currently set memory delegates (see <memory.h>).
//
// The caller takes ownership of the allocated string.
// The string must be freed after use to avoid creating
// a memory leak.
//
// If the input string is NULL, no memory allocation
// takes place and NULL is returned.
//
// Parameters:
//
//   str - Input string to create a duplicate of.
//
// Returns:
//
//   Pointer to allocated memory for the duplicated
//   string, or NULL if the input string was NULL.
WZL_CUTL_PUBLIC(char*) wzl_duplicate_string(const char* str);

// Function: wzl_vsnprintf
// Wrapper around the C vsnprintf function, which always
// ensures that the output buffer is terminated if the
// buffer pointer is not null and the buffer size is
// greater than zero.
//
// Parameters:
//
//   buffer      - Pointer to buffer that the formatted string
//                 is written to.
//   buffer_size - Size of the buffer, including the null terminator.
//   format      - String representing the format of the contents
//                 that will be written to the buffer.
//   args        - Variadic arguments for formatting.
//
// Returns:
//
//   Number of characters that would have been written, disregarding
//   the actual size of the buffer, or a negative number if an error
//   occurs.
WZL_CUTL_PUBLIC(int) wzl_vsnprintf(char* buffer, size_t buffer_size, const char* format, va_list args);

// Function: wzl_snprintf
// Wrapper around the C vsnprintf function, which always
// ensures that the output buffer is terminated if the
// buffer pointer is not null and the buffer size is
// greater than zero.
//
// Parameters:
//
//   buffer      - Pointer to buffer that the formatted string
//                 is written to.
//   buffer_size - Size of the buffer, including the null terminator.
//   format      - String representing the format of the contents
//                 that will be written to the buffer.
//   ...         - Variadic arguments for formatting.
//
// Returns:
//
//   Number of characters that would have been written, disregarding
//   the actual size of the buffer, or a negative number if an error
//   occurs.
static inline int wzl_snprintf(char* buffer, size_t buffer_size, const char* format, ...)
{
	va_list args;

	va_start(args, format);
	const int result = wzl_vsnprintf(buffer, buffer_size, format, args);
	va_end(args);

	return result;
}

#endif  // WZL_CUTL_STRING_H
