// File: time.h
// Portable functions for getting time-related data from the system.

#ifndef WZL_CUTL_TIME_H
#define WZL_CUTL_TIME_H

#include <stdint.h>

#include "wzl_cutl/libexport.h"

// Function: wzl_get_milliseconds_modulo
// Returns the number of milliseconds that have elapsed
// since the beginning of the current second on the system.
//
// This is in relation to the realtime (ie. wall) clock.
//
// If the operation fails, the function returns -1 and
// errno is set appropriately.
//
// Returns:
//
//   Number of milliseconds, modulo 1000,
//   or -1 if the operation fails.
WZL_CUTL_PUBLIC(int32_t) wzl_get_milliseconds_modulo(void);

// Function: wzl_get_milliseconds_monotonic
// Returns the number of milliseconds that have elapsed
// since some unspecified epoch in the past. This is
// usually when the system was started, but should not
// be relied upon to represent this.
//
// This function is not meant for measuring absolute time,
// but for measuring the progression of time over
// subsequent calls.
//
// If the operation fails, the function returns 0
// and errno is set appropriately.
//
// Returns:
//
//   Number of milliseconds since the system's
//   monotonic clock epoch, or 0 if the operation fails.
WZL_CUTL_PUBLIC(uint64_t) wzl_get_milliseconds_monotonic(void);

#endif  // WZL_CUTL_TIME_H
