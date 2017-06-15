#pragma once

#include "../NumericTypes.h"
#include "../BitsRequired.h"
#include "../BitSize.h"
#include "MsbMask.h"

namespace Ardutils
{
	template< unsigned Number, typename T = LeastUInt<BitsRequired<Number>::Value> >
	struct LeadingOnes;

	template< unsigned Number, typename T >
	struct LeadingOnes
	{
		LeadingOnes(void) = delete;
		constexpr static const unsigned Value = ((Number & MsbMask<BitSize<T>::Value>::Value) != 0) ? 1 + LeadingOnes<(Number << 1), T>::Value : 0;
	};

	template< typename T >
	struct LeadingOnes<~0, T>
	{
		LeadingOnes(void) = delete;
		constexpr static const unsigned Value = BitSize<T>::Value;
	};

	template< typename T >
	struct LeadingOnes<0, T>
	{
		LeadingOnes(void) = delete;
		constexpr static const unsigned Value = 0;
	};
}