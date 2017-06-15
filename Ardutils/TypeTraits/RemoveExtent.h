#pragma once

#include "BasicTypes.h"

//
// RemoveExtent
//

namespace Ardutils
{
	// C++11
	template< typename T >
	struct RemoveExtent { using Type = T; };
	template< typename T >
	struct RemoveExtent< T[] > { using Type = T; };
	template< typename T, SizeT N >
	struct RemoveExtent< T[N] > { using Type = T; };

	// C++14
	template< typename T >
	using RemoveExtentT = typename RemoveExtent< T >::Type;
}
