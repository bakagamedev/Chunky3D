#pragma once

#include "IntegralConstant.h"
#include "BasicTypes.h"

#include "../Details/VersioningStart.h"

//
// Extent
//

namespace Ardutils
{
	// C++11
	template< typename T, unsigned N = 0 >
	struct Extent : IntegralConstant< SizeT, 0 > {};

	template< typename T >
	struct Extent< T[], 0 > : IntegralConstant< SizeT, 0 > {};

	template< typename T, unsigned N >
	struct Extent< T[], N > : Extent< T, N - 1 > {};

	template< typename T, SizeT I >
	struct Extent< T[I], 0 > : IntegralConstant< SizeT, 0 > {};

	template< typename T, SizeT I, unsigned N >
	struct Extent< T[I], N > : Extent< T, N - 1 > {};

	// C++17
	// C++14 is needed for template variables
#if	AT_LEAST_CPP_14

	template< typename T, unsigned N = 0 >
	constexpr SizeT ExtentV = Extent< T, N >::Value;

#endif
}

#include "../Details/VersioningEnd.h"
