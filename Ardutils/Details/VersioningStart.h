#ifndef ADRUTILS_VERSIONING_H
#define ARDUTILS_VERSIONING_H

//
// Was hoping to not need one of these,
// but since Arduino isn't quite C++17
// and since I don't want extra work later on
// I'm using macros for future-proofing.
//

#define CPP_VERSION_COMPILER __cplusplus

#define CPP_VERSION_IS(version) (CPP_VERSION_COMPILER == CPP_##version)
#define CPP_VERSION_AT_LEAST(version) (CPP_VERSION_COMPILER >= CPP_##version)

//
// C++ 98
//

#define CPP_98 197711L

#define CPP_VERSION_IS_98 CPP_VERSION_IS(98)
#define CPP_VERSION_AT_LEAST_98 CPP_VERSION_AT_LEAST(98)

#if CPP_VERSION_IS_98
#define USE_IF_CPP_98(code) code
#else
#define USE_IF_CPP_98(code)
#endif

#if CPP_VERSION_AT_LEAST_98
#define USE_IF_AT_LEAST_CPP_98(code) code
#else
#define USE_IF_AT_LEAST_CPP_98(code)
#endif

//
// C++ 11
//

#define CPP_11 201103L

#define CPP_VERSION_IS_11 CPP_VERSION_IS(11)
#define CPP_VERSION_AT_LEAST_11 CPP_VERSION_AT_LEAST(11)

#if CPP_VERSION_IS_11
#define USE_IF_CPP_11(code) code
#else
#define USE_IF_CPP_11(code)
#endif

#if CPP_VERSION_AT_LEAST_11
#define USE_IF_AT_LEAST_CPP_11(code) code
#else
#define USE_IF_AT_LEAST_CPP_11(code)
#endif

//
// C++ 14
//

#define CPP_14 201402L

#define CPP_VERSION_IS_14 CPP_VERSION_IS(14)
#define CPP_VERSION_AT_LEAST_14 CPP_VERSION_AT_LEAST(14)

#if CPP_VERSION_IS_14
#define USE_IF_CPP_14(code) code
#else
#define USE_IF_CPP_14(code)
#endif

#if CPP_VERSION_AT_LEAST_14
#define USE_IF_AT_LEAST_CPP_14(code) code
#else
#define USE_IF_AT_LEAST_CPP_14(code)
#endif

//
// C++17
//

#define CPP_17 201703L

#define CPP_VERSION_IS_17 CPP_VERSION_IS(17)
#define CPP_VERSION_AT_LEAST_17 CPP_VERSION_AT_LEAST(17)

#if CPP_VERSION_IS_17
#define USE_IF_CPP_17(code) code
#else
#define USE_IF_CPP_17(code)
#endif

#if CPP_VERSION_AT_LEAST_17
#define USE_IF_AT_LEAST_CPP_17(code) code
#else
#define USE_IF_AT_LEAST_CPP_17(code)
#endif

#endif

