#pragma once

#include "IntegralConstant.h"

#include "../Details/VersioningStart.h"

//
// IsFloatingPoint
//

namespace Ardutils
{
	namespace Details
	{
		template< typename T >
		struct IsFloatingPoint : FalseType {};

		template<>
		struct IsFloatingPoint< float > : TrueType {};

		template<>
		struct IsFloatingPoint< double > : TrueType {};

		template<>
		struct IsFloatingPoint< long double > : TrueType {};
	}

	// C++11
	template< typename T >
	struct IsFloatingPoint
		: Details::IsFloatingPoint< typename RemoveCV< T >::Type > {};
	
	// C++17
	// C++14 is needed for template variables
#if AT_LEAST_CPP_14
	
	template< typename T >
	constexpr bool IsFloatingPointV = IsFloatingPoint< T >::Value;

#endif
}

#include "../Details/VersioningEnd.h"