#pragma once

#include "../TypeTraits.h"

namespace Ardutils
{
	template< typename T > constexpr inline typename RemoveReference<T>::Type && Move(T&& value)
	{
		return static_cast<typename RemoveReference<T>::Type&&>(value);
	}
}