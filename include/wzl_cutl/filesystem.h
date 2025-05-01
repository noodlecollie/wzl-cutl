// File: filesystem.h
// Defines helper functions for accessing the filesystem.

#ifndef WZL_CUTL_FILESYSTEM_H
#define WZL_CUTL_FILESYSTEM_H

#include <stdbool.h>
#include "wzl_cutl/libexport.h"

// Function: wzl_get_cwd
// Copies the absolute path of the current working directory
// into the provided buffer. The buffer is always terminated.
//
// If the buffer is null, an allocated buffer is returned
// that is at least buffer_size characters in length. This
// allocated buffer must be freed later by the caller.
//
// Parameters:
//
//   buffer      - Buffer to copy into.
//   buffer_size - Size of the buffer, including the null terminator.
//
// Returns:
//
//   NULL if a valid buffer pointer was passed to the function, or
//   an allocated buffer if NULL was passed instead.
WZL_CUTL_PUBLIC(char*) wzl_get_cwd(char* buffer, size_t buffer_size);

// Function: wzl_get_executable_path
// Copies the absolute path to the current executable into
// the provided buffer. The buffer is always terminated.
//
// If the buffer is null, an allocated buffer is returned
// that is at least buffer_size characters in length. This
// allocated buffer must be freed later by the caller.
//
// Parameters:
//
//   buffer      - Buffer to copy into.
//   buffer_size - Size of the buffer, including the null terminator.
//
// Returns:
//
//   NULL if a valid buffer pointer was passed to the function, or
//   an allocated buffer if NULL was passed instead.
WZL_CUTL_PUBLIC(char*) wzl_get_executable_path(char* buffer, size_t buffer_size);

// Function: wzl_file_exists
// Returns whether a file exists at the specified path.
//
// If relative, the path is evaluated relative to the
// current working directory.
//
// Note:
//
//   Beware that the status of a file may change between this
//   function being called and a subsequent attempt to load
//   the file. If the aim is to check for a file's existence
//   in order to open it, it is usually better to simply
//   attempt to open the desired file and check whether this
//   completes successfully.
//
// Parameters:
//
//   native_path - Path to check. Must be in native format for the
//                 current platform.
//
// Returns:
//
//   True if a file exists at the specified path,
//   or false otherwise.
WZL_CUTL_PUBLIC(bool) wzl_file_exists(const char* native_path);

// Function: wzl_directory_exists
// Returns whether a directory exists at the specified path.
//
// If relative, the path is evaluated relative to the
// current working directory.
//
// Note:
//
//   Beware that the status of a directory may change between
//   this function being called and a subsequent attempt to access
//   the directory. If the aim is to check for a file's existence
//   in order to open it, it is usually better to simply
//   attempt to open the desired file and check whether this
//   completes successfully.
//
// Parameters:
//
//   native_path - Path to check. Must be in native format for the
//                 current platform.
//
// Returns:
//
//   True if a directory exists at the specified path,
//   or false otherwise.
WZL_CUTL_PUBLIC(bool) wzl_directory_exists(const char* native_path);

#endif  // WZL_CUTL_FILESYSTEM_H
