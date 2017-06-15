#pragma once

#include "../NumericTypes.h"

namespace Ardutils
{
	template< unsigned Bits >
	struct MsbMask
	{
		MsbMask(void) = delete;
		constexpr const static LeastUInt<Bits> Value = (1ull << (Bits - 1));
	};
}