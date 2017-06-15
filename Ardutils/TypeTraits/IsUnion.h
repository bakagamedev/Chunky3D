#pragma once

#include "IntegralConstant.h"

#include "../Details/VersioningStart.h"
#include "../Details/CompilerTraitsStart.h"

//
// IsUnion
//

namespace Ardutils
{
#if HAS_COMPILER_TRAIT_IS_UNION

	// C++11
	template< typename T >
	struct IsUnion :
		BoolConstant< COMPILER_TRAIT_IS_UNION(T) > {};

	// C++17
	// C++14 is needed for template variables
#if AT_LEAST_CPP_14

	template< typename T >
	constexpr bool IsUnionV = IsUnion< T >::Value;

#endif
#else
	template< typename T > struct IsUnion : FalseType {};

	#warning "IsUnion not supported for this compiler. IsUnion<T>::Value will always be false."
#endif
}

#include "../Details/CompilerTraitsEnd.h"
#include "../Details/VersioningEnd.h"