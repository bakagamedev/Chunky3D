#pragma once

#include "../NumericTypes.h"

namespace Ardutils
{
	template< unsigned Bits >
	struct IdentityMask
	{
		IdentityMask(void) = delete;
		constexpr const static LeastUInt<Bits> Value = 1 | (IdentityMask<Bits - 1>::Value << 1);
	};

	template<>
	struct IdentityMask<0>
	{
		IdentityMask(void) = delete;
		constexpr const static LeastUInt<0> Value = 0;
	};
}
