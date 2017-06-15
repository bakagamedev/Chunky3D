#pragma once

#include "Move.h"
#include "../TypeTraits.h"
#include "../BitsRequired.h"
#include "../NumericTypes.h"

namespace Ardutils
{
	template< typename T > void Swap(T& left, T& right) // O(1)
	{
		auto temp = Move(left);
		left = Move(right);
		right = Move(temp);
	}

	template< typename T, SizeT N > void Swap(T (&left)[N], T (&right)[N]) noexcept(noexcept(Swap(*left, *right))) // O(n)
	{
		using IndexType = FastUInt<BitsRequired<N>::Value>; // Favour speed over size
		for (IndexType i = 0; i < N; ++i)
			Swap(left[i], right[i]);
	}
}
