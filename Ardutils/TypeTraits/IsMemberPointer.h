#pragma once

#include "IntegralConstant.h"
#include "RemoveCV.h"

#include "../Details/VersioningStart.h"

//
// IsReference
//

namespace Ardutils
{
	namespace Details
	{
		template< typename T >
		struct IsMemberPointer : FalseType {};

		template< typename T, typename U >
		struct IsMemberPointer< T U::* > : TrueType {};
	}

	// C++11
	template< typename T >
	struct IsMemberPointer :
		Details::IsMemberPointer< typename RemoveCV< T >::Type > {};

	// C++17
	// C++14 is needed for template variables
#if AT_LEAST_CPP_14
	
	template< typename T >
	constexpr bool IsMemberPointerV = IsMemberPointer< T >::Value;
	
#endif
}

#include "../Details/VersioningEnd.h"