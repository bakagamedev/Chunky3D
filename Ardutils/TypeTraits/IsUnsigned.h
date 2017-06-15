#pragma once

#include "IntegralConstant.h"
#include "IsArithmetic.h"

#include "../Details/VersioningStart.h"

//
// IsUnsigned
//

namespace Ardutils
{
	namespace Details
	{
		template< typename T, bool = IsArithmetic< T >::Value >
		struct IsUnsigned;

		template< typename T >
		struct IsUnsigned< T, true > : BoolConstant<T(0) < T(-1)> {};

		template< typename T >
		struct IsUnsigned< T, false > : FalseType {};
	}

	// C++11
	template< typename T >
	struct IsUnsigned :
		Details::IsUnsigned< T > {};

	// C++17
	// C++14 is needed for template variables
#if AT_LEAST_CPP_14

	template< typename T >
	constexpr bool IsUnsignedV = IsUnsigned< T >::Value;

#endif
}

#include "../Details/VersioningEnd.h"