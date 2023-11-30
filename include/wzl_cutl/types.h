#ifndef WZL_CUTL_TYPES_H
#define WZL_CUTL_TYPES_H

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include "wzl_cutl/platform_defs.h"

// Typedef: wzl_char
// Type alias for a single-byte (narrow) text character.
typedef char wzl_char;

// Typedef: wzl_int8
// Type alias for a signed 8-bit number.
typedef int8_t wzl_int8;

// Typedef: wzl_uint8
// Type alias for an unsigned 8-bit number.
typedef uint8_t wzl_uint8;

// Typedef: wzl_int16
// Type alias for a signed 16-bit number.
typedef int16_t wzl_int16;

// Typedef: wzl_uint16
// Type alias for an unsigned 16-bit number.
typedef uint16_t wzl_uint16;

// Typedef: wzl_int32
// Type alias for a signed 32-bit number.
typedef int32_t wzl_int32;

// Typedef: wzl_uint32
// Type alias for an unsigned 32-bit number.
typedef uint32_t wzl_uint32;

// Typedef: wzl_int64
// Type alias for a signed 64-bit number.
typedef int64_t wzl_int64;

// Typedef: wzl_uint64
// Type alias for an unsigned 64-bit number.
typedef uint64_t wzl_uint64;

// Typedef: wzl_void
// Alias for the "void" type indicating no value.
typedef void wzl_void;

// Typedef: wzl_voidptr
// Alias for an opaque pointer to arbitrary data.
typedef void* wzl_voidptr;

// Typedef: wzl_size
// Alias for an unsigned type that may hold the maximum
// representable value in a single system word.
#if WZL_IS_64BIT()
typedef wzl_uint64 wzl_size;
#elif WZL_IS_32BIT()
typedef wzl_uint32 wzl_size;
#else
#error Unsupported system architecture
#endif

// Constant: WZL_NULLPTR
// Alias for a null pointer value.
#define WZL_NULLPTR NULL

#endif  // WZL_CUTL_TYPES_H
