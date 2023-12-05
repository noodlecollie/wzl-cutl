// File: math.h
// Defines helper definitions and macros for performing
// math-related functions.

#ifndef WZL_CUTL_MATH_H
#define WZL_CUTL_MATH_H

// Macro: WZL_MAX
// Evaluates to the maximum of the two supplied values.
//
// If the first value is greater than the second, the
// the result of the expression is the first value;
// otherwise, the result is the second value.
//
// Parameters:
//
//   a - First value to compare.
//   b - Second value to compare.
#define WZL_MAX(a, b) (((a) > (b)) ? (a) : (b))

// Macro: WZL_MIN
// Evaluates to the minimum of the two supplied values.
//
// If the first value is less than the second, the
// the result of the expression is the first value;
// otherwise, the result is the second value.
//
// Parameters:
//
//   a - First value to compare.
//   b - Second value to compare.
#define WZL_MIN(a, b) (((a) < (b)) ? (a) : (b))

// Macro: WZL_CLAMP
// Evaluates to one of three provided values, depending
// on whether the input value is below the minimum,
// above the maximum, or between the two.
//
// If the value is less than the minimum, the result
// of the expression is the minimum. If the value is
// greater than the maximum, the result of the
// expression is the maximum. Otherwise, the result
// is the original value.
//
// Parameters:
//
//   min - Minimum value of the expression.
//   val - Value to check against min and max.
//   max - Maximum value of the expression.
#define WZL_CLAMP(min, val, max) (WZL_MAX(min, WZL_MIN(val, max)))

#endif  // WZL_CUTL_MATH_H
