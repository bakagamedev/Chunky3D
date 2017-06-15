#pragma once

#include "IntegralConstant.h"

//
// Negation
//

namespace Ardutils
{
	// C++17
	template< typename T >
	struct Negation : BoolConstant< !bool(T::Value) > {};

	// C++17
	// C++14 is needed for template variables
#if AT_LEAST_CPP_14

	template< typename T >
	constexpr bool NegationV = Negation< T >::Value;

#endif
}