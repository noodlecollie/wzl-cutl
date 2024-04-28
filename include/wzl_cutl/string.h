// File: string.h
// Defines functions that manipulate strings.

#ifndef WZL_CUTL_STRING_H
#define WZL_CUTL_STRING_H

#include <stdarg.h>
#include <stddef.h>
#include "wzl_cutl/libexport.h"

// Function: wzl_strdup
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
WZL_CUTL_PUBLIC(char*) wzl_strdup(const char* str);

// Function: wzl_strcpy
// Safer version of the standard library strcpy function,
// which always ensures that the provided buffer is terminated.
//
// Warning:
//
//   This function only ensures that the buffer is terminated,
//   and only if the dest pointer is not null and the dest
//   size is greater than zero. It does not guarantee any more
//   sophisticated safety against string-related vulnerabilities.
//   If you require a better safety guarantee, it is recommended
//   to use a purpose-built third party string library.
//
// Parameters:
//
//   dest     - Destination buffer to copy the source string into.
//   destSize - Maximum size of the destination buffer, in characters.
//   src      - Source string to copy into the buffer. Assumes this is terminated.
//
// Returns:
//
//   Number of characters copied, not including the terminator.
WZL_CUTL_PUBLIC(size_t) wzl_strcpy(char* restrict dest, size_t destSize, const char* restrict src);

// Function: wzl_vsprintf
// Safer version of the standard library vsprintf function,
// which always ensures that the provided buffer is terminated.
//
// On Windows, this function simply calls through to vsprintf_s,
// so will behave according to the Microsoft documentation:
// https://learn.microsoft.com/en-us/cpp/c-runtime-library/reference/vsprintf-s-vsprintf-s-l-vswprintf-s-vswprintf-s-l
//
// Warning:
//
//   This function only ensures that the buffer is terminated,
//   and only if the buffer pointer is not null and the buffer
//   size is greater than zero. It does not guarantee any more
//   sophisticated safety against string-related vulnerabilities.
//   If you require a better safety guarantee, it is recommended
//   to use a purpose-built third party string library.
//
// Parameters:
//
//   buffer     - Buffer which will hold the formatted string.
//   bufferSize - Maximum size of the destination buffer, in characters.
//   format     - String specifying how to format the result.
//   argptr     - Parameters for the formatting operation.
//
// Returns:
//
//   Number of characters written, excluding the null terminator,
//   or a negative value if an error occurs.
WZL_CUTL_PUBLIC(int) wzl_vsprintf(char* buffer, size_t bufferSize, const char* format, va_list argptr);

// Function: wzl_sprintf
// Safer version of the standard library sprintf function,
// which always ensures that the provided buffer is terminated.
//
// This is an inline convenience wrapper for <wzl_vsprintf>.
//
// Warning:
//
//   This function only ensures that the buffer is terminated,
//   and only if the buffer pointer is not null and the buffer
//   size is greater than zero. It does not guarantee any more
//   sophisticated safety against string-related vulnerabilities.
//   If you require a better safety guarantee, it is recommended
//   to use a purpose-built third party string library.
//
// Parameters:
//
//   buffer - Buffer which will hold the formatted string.
//   format - String specifying how to format the result.
//   argptr - Parameters for the formatting operation.
//
// Returns:
//
//   Number of characters written, excluding the null terminator,
//   or a negative value if an error occurs.
static inline int wzl_sprintf(char* buffer, size_t sizeOfBuffer, const char* format, ...)
{
	va_list arglist;
	va_start(arglist, format);

	int returnVal = wzl_vsprintf(buffer, sizeOfBuffer, format, arglist);

	va_end(arglist);
	return returnVal;
}

#endif  // WZL_CUTL_STRING_H
