#pragma once

#include "../TypeTraits.h"
#include "../BitSize.h"

namespace Ardutils
{
	namespace Details
	{
		template< unsigned Bits, typename... Ts >
		struct LeastTypeHelper;

		template< unsigned Bits, typename T, typename... Ts >
		struct LeastTypeHelper<Bits, T, Ts... >
		{
			using Type = typename Conditional<(Bits <= BitSize<T>::Value), T, typename LeastTypeHelper<Bits, Ts...>::Type>::Type;
		};

		template< unsigned Bits >
		struct LeastTypeHelper<Bits>
		{
			using Type = void;
		};

		template< unsigned Bits, typename... Ts >
		using LeastType = typename LeastTypeHelper<Bits, Ts...>::Type;
	}
}
