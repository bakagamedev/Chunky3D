#pragma once

#include "IntegralConstant.h"
#include "IsArithmetic.h"

#include "../Details/VersioningStart.h"

//
// IsSigned
//

namespace Ardutils
{
	namespace Details
	{
		template< typename T, bool = IsArithmetic< T >::Value >
		struct IsSigned;

		template< typename T >
		struct IsSigned< T, true > : BoolConstant<T(-1) < T(0)> {};
		
		template< typename T >
		struct IsSigned< T, false > : FalseType {};
	}

	// C++11
	template< typename T >
	struct IsSigned :
		Details::IsSigned< T > {};

	// C++17
	// C++14 is needed for template variables
#if AT_LEAST_CPP_14

	template< typename T >
	constexpr bool IsSignedV = IsSigned< T >::Value;

#endif
}

#include "../Details/VersioningEnd.h"