#pragma once

#include "IntegralConstant.h"
#include "IsSame.h"
#include "RemoveCV.h"

#include "../Details/VersioningStart.h"

//
// IsNullPointer
//

namespace Ardutils
{
	// C++11
	template< typename T >
	struct IsNullPointer :
		IsSame< decltype(nullptr), typename RemoveCV< T >::Type > {};

	// C++17
	// C++14 is needed for template variables
#if AT_LEAST_CPP_14
	
	template< typename T >
	constexpr bool IsNullPointerV = IsNullPointer< T >::Value;

#endif
}

#include "../Details/VersioningEnd.h"