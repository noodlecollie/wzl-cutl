// File: time.h
// Portable functions for getting time-related data from the system.

#ifndef WZL_CUTL_TIME_H
#define WZL_CUTL_TIME_H

#include <stdint.h>

#include "wzl_cutl/libexport.h"

// Function: wzl_get_milliseconds_modulo
// Returns the number of milliseconds that have elapsed
// since the beginning of the current second on the system.
// If the operation fails, the function returns -1 and
// errno is set appropriately.
//
// Returns:
//
//   Number of milliseconds, modulo 1000,
//   or -1 if the operation fails.
WZL_CUTL_PUBLIC(int32_t) wzl_get_milliseconds_modulo(void);

#endif  // WZL_CUTL_TIME_H
