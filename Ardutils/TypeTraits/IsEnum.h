#pragma once

#include "IntegralConstant.h"

#include "../Details/VersioningStart.h"
#include "../Details/CompilerTraitsStart.h"

//
// IsEnum
//

namespace Ardutils
{
#if HAS_COMPILER_TRAIT_IS_ENUM

	// C++11
	template< typename T >
	struct IsEnum :
		BoolConstant< COMPILER_TRAIT_IS_ENUM(T) > {};

	// C++17
	// C++14 is needed for template variables
#if	AT_LEAST_CPP_14
	
	template< typename T >
	constexpr bool IsEnumV = IsEnum< T >::Value;
	
#endif
#else
	template< typename T > struct IsEnum : FalseType {};

	#warning "IsEnum not supported for this compiler. IsEnum<T>::Value will always be false."
#endif
}

#include "../Details/CompilerTraitsEnd.h"
#include "../Details/VersioningEnd.h"