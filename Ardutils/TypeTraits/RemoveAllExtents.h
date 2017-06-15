#pragma once

#include "BasicTypes.h"

//
// RemoveAllExtents
//

namespace Ardutils
{
	// C++11
	template< typename T >
	struct RemoveAllExtents { using Type = T; };
	template< typename T >
	struct RemoveAllExtents< T[] > { using Type = typename RemoveAllExtents< T >::Type; };
	template< typename T, SizeT N >
	struct RemoveAllExtents< T[N] > { using Type = typename RemoveAllExtents< T >::Type; };

	// C++14
	template< typename T >
	using RemoveAllExtentsT = typename RemoveAllExtents< T >::Type;
}
