#pragma once

#include "IntegralConstant.h"

#include "../Details/VersioningStart.h"

//
// IsLValueReference
//

namespace Ardutils
{
	// C++11
	template< typename T >
	struct IsLValueReference : FalseType {};

	template< typename T >
	struct IsLValueReference<T&> : TrueType {};

	// C++17
	// C++14 is needed for template variables
#if AT_LEAST_CPP_14
	
	template< typename T >
	constexpr bool IsLValueReferenceV = IsLValueReference< T >::Value;
	
#endif
}

#include "../Details/VersioningEnd.h"