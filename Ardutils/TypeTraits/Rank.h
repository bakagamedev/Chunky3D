#pragma once

#include "IntegralConstant.h"
#include "BasicTypes.h"

#include "../Details/VersioningStart.h"

//
// Rank
//

namespace Ardutils
{
	// C++11
	template< typename T >
	struct Rank : IntegralConstant< SizeT, 0 > {};

	template< typename T >
	struct Rank< T[] > : IntegralConstant< SizeT, Rank< T >::Value + 1 > {};

	template< typename T, SizeT N >
	struct Rank< T[N] > : IntegralConstant< SizeT, Rank< T >::Value + 1 > {};

	// C++17
	// C++14 is needed for template variables
#if	AT_LEAST_CPP_14

	template< typename T >
	constexpr SizeT RankV = Rank< T >::Value;

#endif
}

#include "../Details/VersioningEnd.h"
