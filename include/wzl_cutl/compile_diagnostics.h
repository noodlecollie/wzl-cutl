// File: compile_diagnostics.h
// Defines helper macros for ignoring diagnostics/warnings
// for different compilers.

#ifndef WZL_CUTL_COMPILE_DIAGNOSTICS_H
#define WZL_CUTL_COMPILE_DIAGNOSTICS_H

// Pass on arguments only on certain compilers.
#if defined(_MSC_VER)
#define DO_IF_MSVC(...) __VA_ARGS__
#define DO_IF_GCC(...)
#define DO_IF_CLANG(...)
#define DO_IF_GNU(...)
#elif defined(__clang__)
#define DO_IF_MSVC(...)
#define DO_IF_GCC(...)
#define DO_IF_CLANG(...) __VA_ARGS__
#define DO_IF_GNU(...) DO_IF_CLANG(__VA_ARGS__)
#elif defined(__GNUC__)
#define DO_IF_MSVC(...)
#define DO_IF_GCC(...) __VA_ARGS__
#define DO_IF_CLANG(...)
#define DO_IF_GNU(...) DO_IF_GCC(__VA_ARGS__)
#endif

// Takes the raw tokens passed in and passes them to _Pragma as a string.
#define DO_PRAGMA_WITH(pragmastr) _Pragma(#pragmastr)

// Platform-specific diagnostic macros.
#if defined(_MSC_VER)
#define DIAGNOSTIC_PUSH() DO_PRAGMA_WITH(warning(push))
#define DIAGNOSTIC_POP() DO_PRAGMA_WITH(warning(pop))
#define DIAGNOSTIC_IGNORED(diag) DO_PRAGMA_WITH(warning(disable : diag))
#elif defined(__clang__)
#define DIAGNOSTIC_PUSH() DO_PRAGMA_WITH(clang diagnostic push)
#define DIAGNOSTIC_POP() DO_PRAGMA_WITH(clang diagnostic pop)
#define DIAGNOSTIC_IGNORED(diag) DO_PRAGMA_WITH(clang diagnostic ignored diag)
#elif defined(__GNUC__)
#define DIAGNOSTIC_PUSH() DO_PRAGMA_WITH(GCC diagnostic push)
#define DIAGNOSTIC_POP() DO_PRAGMA_WITH(GCC diagnostic pop)
#define DIAGNOSTIC_IGNORED(diag) DO_PRAGMA_WITH(GCC diagnostic ignored diag)
#endif

// Ignore a diagnostic only if on a specific platform.
#define GCC_DIAGNOSTIC_IGNORED(diag) DO_IF_GCC(DIAGNOSTIC_IGNORED(diag))
#define CLANG_DIAGNOSTIC_IGNORED(diag) DO_IF_CLANG(DIAGNOSTIC_IGNORED(diag))
#define GNU_DIAGNOSTIC_IGNORED(diag) DO_IF_GNU(DIAGNOSTIC_IGNORED(diag))
#define MSVC_DIAGNOSTIC_IGNORED(diag) DO_IF_MSVC(DIAGNOSTIC_IGNORED(diag))

// Push the diagnostic stack only if on a specific platform.
#define GCC_DIAGNOSTIC_PUSH() DO_IF_GCC(DIAGNOSTIC_PUSH())
#define CLANG_DIAGNOSTIC_PUSH() DO_IF_CLANG(DIAGNOSTIC_PUSH())
#define GNU_DIAGNOSTIC_PUSH() DO_IF_GNU(DIAGNOSTIC_PUSH())
#define MSVC_DIAGNOSTIC_PUSH() DO_IF_MSVC(DIAGNOSTIC_PUSH())

// Pop the diagnostic stack only if on a specific platform.
#define GCC_DIAGNOSTIC_POP() DO_IF_GCC(DIAGNOSTIC_POP())
#define CLANG_DIAGNOSTIC_POP() DO_IF_CLANG(DIAGNOSTIC_POP())
#define GNU_DIAGNOSTIC_POP() DO_IF_GNU(DIAGNOSTIC_POP())
#define MSVC_DIAGNOSTIC_POP() DO_IF_MSVC(DIAGNOSTIC_POP())

#endif // WZL_CUTL_COMPILE_DIAGNOSTICS_H
