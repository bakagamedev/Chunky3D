#pragma once

#include <stdint.h>

namespace Ardutils
{
	template< typename Unsigned > uint_fast8_t Log2(const Unsigned & value)
	{
		uint_fast8_t count = 0;
		auto val = value;
		while (true)
		{
			val >>= 1;
			if (val != 0)
				++count;
			else
				break;
		}
		return count;
	}
}