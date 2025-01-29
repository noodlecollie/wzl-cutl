// File: attributes.h
// Attributes that can be applied to functions in a cross-platform manner.

#ifndef WZL_CUTL_ATTRIBUTES_H
#define WZL_CUTL_ATTRIBUTES_H

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

// Macro: WZL_ATTR_FORMAT_PRINTF
// Helper macro for printf-style functions.
//
// A user may need to use printf or gnu_printf, depending on the compiler.
// For more info, see https://stackoverflow.com/a/75689271/2054335
#if defined(__clang__)
#define WZL_ATTR_FORMAT_PRINTF(_fmt_argnum, _first_param_num) WZL_ATTR_FORMAT(printf, _fmt_argnum, _first_param_num)
#elif defined(__GNUC__)
#define WZL_ATTR_FORMAT_PRINTF(_fmt_argnum, _first_param_num) WZL_ATTR_FORMAT(gnu_printf, _fmt_argnum, _first_param_num)
#else
#define WZL_ATTR_FORMAT_PRINTF(_fmt_num, _first_param_num)
#endif

// Macro: WZL_ATTR_NODISCARD
// Used to annotate a function's return type to indicate that the
// value returned by the function should not be ignored.
//
// The classic example of this is for functions which return
// dynamically allocated memory. If the returned pointer is
// ignored, this results in a memory leak. Using this attribute
// will generate a compiler warning if the user ignores the
// returned value.
#if defined(__clang__) || defined(__GNUC__)
#define WZL_ATTR_NODISCARD __attribute__((warn_unused_result))
#elif defined(_MSC_VER) && _MSC_VER >= 1700
#define WZL_ATTR_NODISCARD _Check_return_
#else
#define WZL_ATTR_NODISCARD
#endif

#endif  // WZL_CUTL_ATTRIBUTES_H
