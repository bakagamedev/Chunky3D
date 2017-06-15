#pragma once

#include "FixedPoint.h"

namespace Ardutils
{
	using Q4x4 = FixedPoint<4, 4>;
	using Q8x8 = FixedPoint<8, 8>;
	using Q16x16 = FixedPoint<16, 16>;
	using Q32x32 = FixedPoint<32, 32>;

	using Q1x7 = FixedPoint<1, 7>;
	using Q1x15 = FixedPoint<1, 15>;
	using Q1x31 = FixedPoint<1, 31>;
	using Q1x63 = FixedPoint<1, 63>;
}