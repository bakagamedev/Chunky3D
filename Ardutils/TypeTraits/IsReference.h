#pragma once

#include "IntegralConstant.h"

#include "../Details/VersioningStart.h"

//
// IsReference
//

namespace Ardutils
{
	// C++11
	template< typename T >
	struct IsReference : FalseType {};

	template< typename T >
	struct IsReference< T& > : TrueType {};

	template< typename T >
	struct IsReference< T&& > : TrueType {};

	// C++17
	// C++14 is needed for template variables
#if AT_LEAST_CPP_14
	
	template< typename T >
	constexpr bool IsReferenceV = IsReference< T >::Value;
	
#endif
}

#include "../Details/VersioningEnd.h"