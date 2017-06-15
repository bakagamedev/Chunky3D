#pragma once

#include "RemoveConst.h"
#include "RemoveVolatile.h"

//
// RemoveCV
//

namespace Ardutils
{
	// C++11
	template< typename T >
	struct RemoveCV { using Type = typename RemoveConst< typename RemoveVolatile< T >::Type >::Type; };

	// C++14
	template< typename T >
	using RemoveCVT = typename RemoveCV< T >::Type;
}