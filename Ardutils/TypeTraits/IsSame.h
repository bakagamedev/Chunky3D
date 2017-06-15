#pragma once

#include "IntegralConstant.h"

#include "../Details/VersioningStart.h"

namespace Ardutils
{
	// C++11
	template< typename T, typename U >
	struct IsSame : FalseType {};

	template< typename T >
	struct IsSame< T, T > : TrueType {};

	// C++17
	// C++14 is needed for template variables
#if AT_LEAST_CPP_14
	
	template< typename T, typename U >
	constexpr bool IsSameV = IsSame< T, U >::Value;

#endif
}

#include "../Details/VersioningEnd.h"