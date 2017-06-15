#pragma once

#include "IntegralConstant.h"

#include "../Details/VersioningStart.h"

//
// IsConst
//

namespace Ardutils
{
	// C++11
	template< typename T >
	struct IsConst : FalseType {};

	template< typename T >
	struct IsConst< const T > : TrueType {};

	// C++17
	// C++14 is needed for template variables
#if AT_LEAST_CPP_14

	template< typename T >
	constexpr bool IsConstV = IsConst< T >::Value;

#endif
}

#include "../Details/VersioningEnd.h"