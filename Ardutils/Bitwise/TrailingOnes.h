#pragma once

#include "../NumericTypes.h"
#include "../BitsRequired.h"
#include "../BitSize.h"
#include "LsbMask.h"

namespace Ardutils
{
	template< unsigned Number, typename T = LeastUInt<BitsRequired<Number>::Value> >
	struct TrailingOnes;

	template< unsigned Number, typename T >
	struct TrailingOnes
	{
		TrailingOnes(void) = delete;
		constexpr static const unsigned Value = ((Number & LsbMask<BitSize<T>::Value>::Value) != 0) ? 1 + TrailingOnes<(Number >> 1), T>::Value : 0;
	};

	template< typename T >
	struct TrailingOnes<~0, T>
	{
		TrailingOnes(void) = delete;
		constexpr static const unsigned Value = BitSize<T>::Value;
	};

	template< typename T >
	struct TrailingOnes<0, T>
	{
		TrailingOnes(void) = delete;
		constexpr static const unsigned Value = 0;
	};
}