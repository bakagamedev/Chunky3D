#pragma once

#include "../NumericTypes.h"
#include "../BitsRequired.h"
#include "../BitSize.h"
#include "MsbMask.h"

namespace Ardutils
{
	template< unsigned Number, typename T = LeastUInt<BitsRequired<Number>::Value> >
	struct LeadingZeroes;

	template< unsigned Number, typename T >
	struct LeadingZeroes
	{
		LeadingZeroes(void) = delete;
		constexpr static const unsigned Value = ((Number & MsbMask<BitSize<T>::Value>::Value) == 0) ? 1 + LeadingZeroes<(Number << 1), T>::Value : 0;
	};

	template< typename T >
	struct LeadingZeroes<1, T>
	{
		LeadingZeroes(void) = delete;
		constexpr static const unsigned Value = 0;
	};

	template< typename T >
	struct LeadingZeroes<0, T>
	{
		LeadingZeroes(void) = delete;
		constexpr static const unsigned Value = BitSize<T>::Value;
	};
}