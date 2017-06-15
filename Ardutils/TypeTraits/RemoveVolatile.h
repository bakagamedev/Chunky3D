#pragma once

//
// RemoveVolatile
//

namespace Ardutils
{
	// C++11
	template< typename T >
	struct RemoveVolatile { using Type = T; };

	template< typename T >
	struct RemoveVolatile< volatile T > { using Type = T; };

	// C++14
	template< typename T >
	using RemoveVolatileT = typename RemoveVolatile< T >::Type;
}