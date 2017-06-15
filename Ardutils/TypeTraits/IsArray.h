#pragma once

#include "IntegralConstant.h"
#include "BasicTypes.h"

#include "../Details/VersioningStart.h"
#include "../Details/CompilerTraitsStart.h"

//
// IsArray
//

namespace Ardutils
{
	// C++11
	template< typename T >
	struct IsArray : FalseType {};

	template< typename T >
	struct IsArray< T[] > : TrueType {};

	template< typename T, SizeT N>
	struct IsArray< T[N] > : TrueType {};

	// C++17
	// C++14 is needed for template variables
#if	AT_LEAST_CPP_14

	template< typename T >
	constexpr bool IsArrayV = IsArray< T >::Value;

#endif
}

#include "../Details/CompilerTraitsEnd.h"
#include "../Details/VersioningEnd.h"
