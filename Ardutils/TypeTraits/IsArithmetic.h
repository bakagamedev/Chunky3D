#pragma once

#include "IntegralConstant.h"
#include "IsIntegral.h"
#include "IsFloatingPoint.h"

#include "../Details/VersioningStart.h"

//
// IsArithmetic
//

namespace Ardutils
{

	// C++11
	template< typename T >
	struct IsArithmetic :
		BoolConstant<
		IsIntegral< T >::Value ||
		IsFloatingPoint< T >::Value
		> {};

	// C++17
	// C++14 is needed for template variables
#if AT_LEAST_CPP_14
	
	template< typename T >
	constexpr bool IsArithmeticV = IsArithmetic< T >::Value;

#endif
}

#include "../Details/VersioningEnd.h"