#ifndef ADRUTILS_COMPILER_DETECT_H
#define ARDUTILS_COMPILER_DETECT_H

//
// Was hoping to not need one of these,
// but since Arduino isn't quite C++17
// and since I don't want extra work later on
// I'm using macros for future-proofing.
//

#include "VersioningStart.h"

#if defined(__GNUC__) && !defined(_MSC_VER) && !defined(__clang__)
#define COMPILER_IS_GCC true

#define USE_IF_COMPILER_IS_GCC(code) code

#include "GCC/CompilerDefines.h"

#else

#define COMPILER_IS_GCC false

#define USE_IF_COMPILER_IS_GCC(code)

#endif


#if defined(_MSC_VER) && !defined(__GNUC__) && !defined(__clang__)
#define COMPILER_IS_MSC true

#define USE_IF_COMPILER_IS_MSC(code) code

#include "MSC/CompilerDefines.h"

// Ref Here: https://msdn.microsoft.com/en-us/library/2bs04eza.aspx
#define HAS_PRAGMA_PUSH_MACRO true
// Ref Here: https://msdn.microsoft.com/en-us/library/hsttss76.aspx
#define HAS_PRAGMA_POP_MACRO true

#else

#define COMPILER_IS_MSC false

#define USE_IF_COMPILER_IS_MSC(code)

#endif

#if !defined(HAS_PRAGMA_PUSH_MACRO)
#define HAS_PRAGMA_PUSH_MACRO false
#endif

#if !defined(HAS_PRAGMA_POP_MACRO)
#define HAS_PRAGMA_POP_MACRO false
#endif

// Purity
#if !defined(HAS_PURE)
#define HAS_PURE false
#define PURE
#endif

#if !defined(HAS_STRICT_PURE)
#define HAS_STRICT_PURE false
#define STRICT_PURE
#endif

// Hot And Cold
#if !defined(HAS_HOTSPOT)
#define HAS_HOTSPOT false
#define HOTSPOT
#endif

#if !defined(HAS_COLDSPOT)
#define HAS_COLDSPOT false
#define COLDSPOT
#endif

// Returning
#if !defined(HAS_NORETURN)
#define HAS_NORETURN false
#define NORETURN
#endif

#if defined(__cplusplus) && CPP_VERSION_AT_LEAST_11
#undef HAS_NORETURN
#undef NORETURN
#define HAS_NORETURN true
#define NORETURN [[noreturn]]
#endif

#if !defined(HAS_WARN_UNUSED_RESULT)
#define HAS_WARN_UNUSED_RESULT false
#define WARN_UNUSED_RESULT
#endif

#if !defined(HAS_MAKES_NO_CALLS)
#define HAS_MAKES_NO_CALLS false
#define MAKES_NO_CALLS
#endif

// Exceptions
#if !defined(NOTHROW)
#define HAS_NOTHROW false
#define NOTHROW
#endif

// Inlining
#if !defined(HAS_ALWAYS_INLINE)
#define HAS_ALWAYS_INLINE false
#define ALWAYS_INLINE
#endif

#if !defined(HAS_NO_INLINE)
#define HAS_NO_INLINE false
#define NO_INLINE
#endif

// Call Errors
#if !defined(HAS_CALL_ERROR)
#define HAS_CALL_ERROR false
#define CALL_ERROR(message)
#endif

#if !defined(HAS_CALL_WARNING)
#define HAS_CALL_WARNING false
#define CALL_WARNING(message)
#endif

// Deprecation
#if !defined(HAS_DEPRECATED)
#define HAS_DEPRECATED false
#define DEPRECATED
#endif

#if defined(__cplusplus) && CPP_VERSION_AT_LEAST_14
#undef HAS_DEPRECATED
#undef DEPRECATED
#define HAS_DEPRECATED true
#define DEPRECATED [[deprecated]]
#endif

#if !defined(HAS_DEPRECATED_MSG)
#define HAS_DEPRECATED_MSG false
#define DEPRECATED_MSG(message)
#endif

#if defined(__cplusplus) && CPP_VERSION_AT_LEAST_14
#undef HAS_DEPRECATED_MSG
#undef DEPRECATED_MSG
#define HAS_DEPRECATED_MSG true
#define DEPRECATED_MSG(message) [[deprecated(message)]]
#endif

// Library Management
#if !defined(HAS_DLLEXPORT)
#define HAS_DLLEXPORT false
#define DLLEXPORT
#endif

#if !defined(HAS_DLLIMPORT)
#define HAS_DLLIMPORT false
#define DLLIMPORT
#endif

#endif
