#pragma once

#include "../BitsRequired.h"
#include "../NumericTypes.h"

namespace Ardutils
{
	template< unsigned long long Number >
	struct NextPowerOfTwo
	{
	private:
		constexpr static const auto Bits = BitsRequired<Number>::Value;

	public:
		NextPowerOfTwo(void) = delete;
		constexpr static const LeastUInt<Bits + 1> Value = 1ull << Bits;
	};
}