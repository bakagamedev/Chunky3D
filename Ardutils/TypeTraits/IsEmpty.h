#pragma once

#include "IntegralConstant.h"

#include "../Details/VersioningStart.h"
#include "../Details/CompilerTraitsStart.h"

//
// IsEmpty
//

namespace Ardutils
{
#if HAS_COMPILER_TRAIT_IS_EMPTY

	// C++11
	template< typename T >
	struct IsEmpty :
		BoolConstant< COMPILER_TRAIT_IS_EMPTY(T) > {};

	// C++17
	// C++14 is needed for template variables
#if	AT_LEAST_CPP_14

	template< typename T >
	constexpr bool IsEmptyV = IsEmpty< T >::Value;

#endif
#else
	template< typename T > struct IsEmpty : FalseType {};

	#warning "IsEmpty not supported for this compiler. IsEmpty<T>::Value will always be false."
#endif
}

#include "../Details/CompilerTraitsEnd.h"
#include "../Details/VersioningEnd.h"