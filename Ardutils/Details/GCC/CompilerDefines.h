#if defined(__GNUC__) && !defined(_MSC_VER) && !defined(__clang__)
#define COMPILER_IS_GCC true

#define USE_IF_COMPILER_IS_GCC(code) code

//
// Pragmas
//

// Ref Here: https://gcc.gnu.org/onlinedocs/gcc-4.4.1/gcc/Push_002fPop-Macro-Pragmas.html
#define HAS_PRAGMA_PUSH_MACRO true
#define HAS_PRAGMA_POP_MACRO true

//
// Attributes
//

// Purity
#if (__GNUC__ >= 2) && (__GNUC_MINOR__ >= 96)
#define HAS_PURE true
#define PURE __attribute__((pure))
#endif
#if (__GNUC__ >= 2) && (__GNUC_MINOR__ >= 5)
#define HAS_STRICT_PURE true
#define STRICT_PURE __attribute__((const))
#endif

// Hot And Cold
#if (__GNUC__ >= 4) && (__GNUC_MINOR__ >= 3)
#define HAS_HOTSPOT true
#define HOTSPOT __attribute__((hot))
#endif
#if (__GNUC__ >= 4) && (__GNUC_MINOR__ >= 3)
#define HAS_COLDSPOT true
#define COLDSPOT __attribute__((cold))
#endif

// Returning
#define HAS_NORETURN true
#define NORETURN __attribute__((noreturn))

#define HAS_WARN_UNUSED_RESULT true
#define WARN_UNUSED_RESULT __attribute__((warn_unused_result))

#define HAS_MAKES_NO_CALLS true
#define MAKES_NO_CALLS __attribute__((leaf))

// Exceptions
#define HAS_NOTHROW true
#define NOTHROW __attribute__((nothrow))

// Inlining
#define HAS_ALWAYS_INLINE true
#define ALWAYS_INLINE __attribute__((always_inline))

#define HAS_NO_INLINE true
#define NO_INLINE __attribute__((noinline))

// Call Errors
#define HAS_CALL_ERROR true
#define CALL_ERROR(message) __attribute__((error(#message)))

#define HAS_CALL_WARNING true
#define CALL_WARNING(message) __attribute__((warning(#message)))

// Deprecation
#define HAS_DEPRECATED true
#define DEPRECATED __attribute__((deprecated))

#define HAS_DEPRECATED_MSG true
#define DEPRECATED_MSG(message) __attribute__((deprecated(#message)))

// Library Management
#define HAS_DLLEXPORT true
#define DLLEXPORT __attribute__((dllexport))

#define HAS_DLLIMPORT true
#define DLLIMPORT __attribute__((dllimport))

#else

#define COMPILER_IS_GCC false

#define USE_IF_COMPILER_IS_GCC(code)

#endif