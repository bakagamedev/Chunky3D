//
// Cleanup all the defines
// because they're implementation details
// that the users shouldn't have to
// care about or know about.
//

#include "VersioningEnd.h"

#ifdef ADRUTILS_COMPILER_DETECT_H
#undef ARDUTILS_COMPILER_DETECT_H
#endif

#undef COMPILER_IS_MSC
#undef USE_IF_COMPILER_IS_MSC

#undef COMPILER_IS_GCC
#undef USE_IF_COMPILER_IS_GCC

#undef HAS_PRAGMA_PUSH_MACRO
#undef HAS_PRAGMA_POP_MACRO


// Purity
#undef HAS_PURE
#undef PURE

#undef HAS_STRICT_PURE
#undef STRICT_PURE

// Hot And Cold
#undef HAS_HOTSPOT
#undef HOTSPOT

#undef HAS_COLDSPOT
#undef COLDSPOT

// Returning
#undef HAS_NORETURN
#undef NORETURN

#undef HAS_NORETURN
#undef NORETURN

#undef HAS_WARN_UNUSED_RESULT
#undef WARN_UNUSED_RESULT

#undef HAS_MAKES_NO_CALLS
#undef MAKES_NO_CALLS

// Exceptions
#undef HAS_NOTHROW
#undef NOTHROW

// Inlining
#undef HAS_ALWAYS_INLINE
#undef ALWAYS_INLINE

#undef HAS_NO_INLINE
#undef NO_INLINE

// Call Errors
#undef HAS_CALL_ERROR
#undef CALL_ERROR

#undef HAS_CALL_WARNING
#undef CALL_WARNING

// Deprecation
#undef HAS_DEPRECATED
#undef DEPRECATED

#undef HAS_DEPRECATED_MSG
#undef DEPRECATED_MSG

// Library Management
#undef HAS_DLLEXPORT
#undef DLLEXPORT

#undef HAS_DLLIMPORT
#undef DLLIMPORT
