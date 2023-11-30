#ifndef WZL_CUTL_STRING_H
#define WZL_CUTL_STRING_H

#include "wzl_cutl/libexport.h"
#include "wzl_cutl/types.h"

// Function: wzl_strlen
// Given an input string, returns the length of the string
// not including the null terminator.
//
// If the input string is null, 0 is returned.
//
// Parameters:
//
//   str - String to evaluate the length of.
//
// Returns:
//
//   Number of non-null characters in the string,
//   or 0 if the string pointer is null.
WZL_CUTL_PUBLIC(wzl_size) wzl_strlen(wzl_char* str);

// Function: wzl_duplicate_string
// Given an input string, makes a dynamic copy of this string
// and returns it. Memory is allocated according to the
// currently set memory delegates.
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
WZL_CUTL_PUBLIC(wzl_char*) wzl_duplicate_string(wzl_char* str);

#endif  // WZL_CUTL_STRING_H
