#pragma once

#include "IntegralConstant.h"
#include "Conditional.h"

//
// Conjunction
//

namespace Ardutils
{
	// C++17
	template< typename... > struct Conjunction : TrueType {};

	template< typename T > struct Conjunction< T > : T {};

	template< typename T, typename... Ts >
	struct Conjunction< T, Ts... >
		: Conditional< bool(T::Value), Conjunction< Ts... >, T >::Type {};

	// C++17
	// C++14 is needed for template variables
#if AT_LEAST_CPP_14

	template< typename... T >
	constexpr bool ConjunctionV = Conjunction< T... >::Value;

#endif
}