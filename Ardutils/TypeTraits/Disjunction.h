#pragma once

#include "IntegralConstant.h"
#include "Conditional.h"

//
// Disjunction
//

namespace Ardutils
{
	// C++17
	template< typename... > struct Disjunction : FalseType {};

	template< typename T > struct Disjunction< T > : T {};

	template< typename T, typename... Ts >
	struct Disjunction< T, Ts... >
		: Conditional< bool(T::Value), T, Disjunction< Ts... > >::Type {};

	// C++17
	// C++14 is needed for template variables
#if AT_LEAST_CPP_14

	template< typename... T >
	constexpr bool DisjunctionV = Disjunction< T... >::Value;

#endif
}