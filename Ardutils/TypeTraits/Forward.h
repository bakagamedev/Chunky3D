#pragma once

#include "RemoveReference.h"
#include "IsLValueReference.h"

namespace Ardutils
{
	template< typename T >
	constexpr T&& Forward(typename RemoveReference<T>::Type& value) noexcept
	{
		return (static_cast<T&&>(value));
	}

	template< typename T >
	constexpr T&& Forward(typename RemoveReference<T>::Type&& value) noexcept
	{
		static_assert(!IsLValueReference<T>::Value, "Bad Forward call");
		return (static_cast<T&&>(value));
	}
}