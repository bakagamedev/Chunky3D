#pragma once

#include "IsSame.h"
#include "RemoveCV.h"

#include "../Details/VersioningStart.h"

//
// IsVoid
//


namespace Ardutils
{
	// C++11
	template< typename T >
	struct IsVoid :
		IsSame< void, typename RemoveCV< T >::Type > {};

	// C++17
	// C++14 is needed for template variables
#if AT_LEAST_CPP_14
	
	template< typename T >
	constexpr bool IsVoidV = IsVoid< T >::Value;

#endif
}

#include "../Details/VersioningEnd.h"