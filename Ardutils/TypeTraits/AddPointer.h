#pragma once

#include "IsFunction.h"
#include "RemoveReference.h"

//
// AddPointer
//

namespace Ardutils
{
	namespace Details
	{
		template< typename T, bool IsFunctionType = false >
		struct AddPointer { using Type = typename RemoveReference<T>::Type*; };

		template< typename T >
		struct AddPointer< T, true > { using Type = T; };

		template< typename T, class... Args >
		struct AddPointer<T(Args...), true> { using Type = T(*)(Args...); };

		template< typename T, class... Args >
		struct AddPointer<T(Args..., ...), true> { using Type = T(*)(Args..., ...); };
	}

	template< typename T >
	struct AddPointer : Details::AddPointer<T, IsFunction<T>::Value> {};
}