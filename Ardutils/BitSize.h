#pragma once

#include <limits.h>

namespace Ardutils
{
	template< typename T >
	struct BitSize
	{
		BitSize(void) = delete;
		constexpr static const unsigned Value = sizeof(T) * CHAR_BIT;
	};
}
