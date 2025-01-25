// File: string.h
// Defines functions that manipulate strings.

#ifndef WZL_CUTL_STRING_H
#define WZL_CUTL_STRING_H

#include <stdarg.h>
#include <stddef.h>
#include <string.h>
#include <stdbool.h>
#include "wzl_cutl/libexport.h"

// Macro: WZL_ATTR_FORMAT
// Used to annotate a function to indicate that it accepts printf-style
// arguments, which should be validated at compile time against the
// format string.
//
// Note: At the moment, it's unclear what the best solution to this
// would be for MSVC, so this is left out.
#ifndef _MSC_VER
#define WZL_ATTR_FORMAT(...) __attribute__((format(__VA_ARGS__)))
#else
#define WZL_ATTR_FORMAT(...)
#endif

// Macro: WZL_STRINGIFY_HELPER
// Helper for constructing string literals. Do not use
// this macro directly, use <WZL_STRINGIFY> instead.
#define WZL_STRINGIFY_HELPER(arg) #arg

// Macro: WZL_STRINGIFY
// Expands to a string literal form of the argument.
#define WZL_STRINGIFY(arg) WZL_STRINGIFY_HELPER(arg)

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
WZL_CUTL_PUBLIC(int)
wzl_vsprintf(char* buffer, size_t bufferSize, const char* format, va_list argptr) WZL_ATTR_FORMAT(printf, 3, 0);

// Function: wzl_strequals
// Performs a case-sensitive comparison between two strings.
//
// Note
//
//   A null string is never considered equal to a non-null string.
//   Two null strings are always considered equal.
//
// Parameters:
//
//   a - First string to compare.
//   b - Second string to compare.
//
// Returns:
//
//   True if strings are considered equal, or false otherwise.
WZL_CUTL_PUBLIC(bool) wzl_strequals(const char* a, const char* b);

// Function: wzl_strnequals
// Performs a case-sensitive comparison between two strings,
// with a maximum number of characters to compare.
//
// Note
//
//   A null string is never considered equal to a non-null string.
//   Two null strings are always considered equal.
//
// Parameters:
//
//   a     - First string to compare.
//   b     - Second string to compare.
//   count - Maximum number of characters to compare.
//
// Returns:
//
//   True if strings are considered equal, or false otherwise.
WZL_CUTL_PUBLIC(bool) wzl_strnequals(const char* a, const char* b, size_t count);

// Function: wzl_strequali
// Performs a case-insensitive comparison between two strings.
//
// Note
//
//   A null string is never considered equal to a non-null string.
//   Two null strings are always considered equal.
//
// Parameters:
//
//   a - First string to compare.
//   b - Second string to compare.
//
// Returns:
//
//   True if strings are considered equal, or false otherwise.
WZL_CUTL_PUBLIC(bool) wzl_strequali(const char* a, const char* b);

// Function: wzl_strnequali
// Performs a case-insensitive comparison between two strings,
// with a maximum number of characters to compare.
//
// Note
//
//   A null string is never considered equal to a non-null string.
//   Two null strings are always considered equal.
//
// Parameters:
//
//   a     - First string to compare.
//   b     - Second string to compare.
//   count - Maximum number of characters to compare.
//
// Returns:
//
//   True if strings are considered equal, or false otherwise.
WZL_CUTL_PUBLIC(bool) wzl_strnequali(const char* a, const char* b, size_t count);

// Function: wzl_strtrimspace
// Given a string, obtains pointers to the first and last non-whitespace characters.
//
// Whitespace is determined using the standard library's isspace() function.
//
// Note:
//
//   If either begin or end are non-null, their values will always be set regardless
//   of whether the input string is valid or not. If the input string is null,
//   begin and end will be set to null. If the input string is empty, begin and end
//   will be set to point to the terminator character.
//
// Parameters:
//
//   str   - String to trim.
//   begin - Address of begin pointer. If provided, will be set to point to
//           the first non-whitespace character in the string. If there are no
//           non-whitespace characters, will be set to point to the terminator.
//   end  -  Address of end pointer. If provided, will be set to point to
//           the character *after* the last non-whitespace character in the string.
//           If there are no non-whitespace characters, will be set to point to
//           the terminator.
//
// Returns:
//
//   True if the string was trimmed at all (ie. it contained any leading or
//   trailing whitespace), or false otherwise.
WZL_CUTL_PUBLIC(bool) wzl_strtrimspace(const char* str, const char** begin, const char** end);

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
} WZL_ATTR_FORMAT(printf, 3, 4)

#endif  // WZL_CUTL_STRING_H
