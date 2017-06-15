#pragma once

#include "../NumericTypes.h"
#include "../BitsRequired.h"
#include "../BitSize.h"
#include "LsbMask.h"

namespace Ardutils
{
	template< unsigned Number, typename T = LeastUInt<BitsRequired<Number>::Value> >
	struct TrailingZeroes;

	template< unsigned Number, typename T >
	struct TrailingZeroes
	{
		TrailingZeroes(void) = delete;
		constexpr static const unsigned Value = ((Number & LsbMask<BitSize<T>::Value>::Value) == 0) ? 1 + TrailingZeroes<(Number >> 1), T>::Value : 0;
	};

	template< typename T >
	struct TrailingZeroes<1, T>
	{
		TrailingZeroes(void) = delete;
		constexpr static const unsigned Value = 0;
	};

	template< typename T >
	struct TrailingZeroes<0, T>
	{
		TrailingZeroes(void) = delete;
		constexpr static const unsigned Value = BitSize<T>::Value;
	};
}