#pragma once

#include "AddConst.h"
#include "AddVolatile.h"

//
// AddCV
//

namespace Ardutils
{
	// C++11
	template< typename T >
	struct AddCV { using Type = typename AddConst< typename AddVolatile< T >::Type >::Type; };

	// C++14
	template< typename T >
	using AddCVT = typename AddCV< T >::Type;
}