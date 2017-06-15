#pragma once

#include "../TypeTraits.h"

namespace Ardutils
{
	template< typename T > constexpr typename AddConst<T>::Type AsConst(T & value) noexcept // O(1)
	{
		return value;
	}

	template< typename T > void AsConst(const T && t) = delete;
}