#pragma once

#include "../NumericTypes.h"

namespace Ardutils
{
	template< unsigned Bits >
	struct LsbMask
	{
		LsbMask(void) = delete;
		constexpr const static LeastUInt<Bits> Value = 1ull;
	};
}