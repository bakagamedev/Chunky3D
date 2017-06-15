#pragma once

#include "IntegralConstant.h"

#include "../Details/VersioningStart.h"

//
// IsRValueReference
//

namespace Ardutils
{
	// C++11
	template< typename T >
	struct IsRValueReference : FalseType {};

	template< typename T >
	struct IsRValueReference<T&&> : TrueType {};

	// C++17
	// C++14 is needed for template variables
#if AT_LEAST_CPP_14

	template< typename T >
	constexpr bool IsRValueReferenceV = IsRValueReference< T >::Value;

#endif
}

#include "../Details/VersioningEnd.h"