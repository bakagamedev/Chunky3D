#pragma once

//
// AddVolatile
//

namespace Ardutils
{
	// C++11
	template< typename T >
	struct AddVolatile { using Type = volatile T; };

	// C++14
	template< typename T >
	using AddVolatileT = typename AddVolatile< T >::Type;
}