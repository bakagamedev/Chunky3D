#pragma once

#include "IntegralConstant.h"
#include "RemoveCV.h"
#include "IsPointer.h"

#include "../Details/VersioningStart.h"

//
// IsPointer
//

namespace Ardutils
{
	namespace Details
	{
		template< typename T >
		struct IsPointer : FalseType {};

		template< typename T >
		struct IsPointer<T*> : FalseType {};
	}

	// C++11
	template< typename T >
	struct IsPointer :
		Details::IsPointer< typename RemoveCV<T>::Type > {};

	// C++17
	// C++14 is needed for template variables
#if AT_LEAST_CPP_14

	template< typename T >
	constexpr bool IsPointerV = IsPointer< T >::Value;

#endif
}

#include "../Details/VersioningEnd.h"