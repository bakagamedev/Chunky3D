#pragma once

#include <stdint.h>
#include "../BitSize.h"
#include "MsbMask.h"

namespace Ardutils
{
	template< typename T > uint_fast8_t CountLeadingOnes(const T & value)
	{
		constexpr const auto bitCount = BitSize<T>::Value;
		constexpr const auto msbMask = MsbMask<bitCount>::Value;

		if (value == static_cast<T>(~0))
			return bitCount;

		uint_fast8_t count = 0;
		for (T val = value; (val & msbMask) != 0; val <<= 1)
			++count;

		return count;
	}
}