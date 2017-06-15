#pragma once

#include <stdint.h>

#include "../BitSize.h"

#include "Details.h"

namespace Ardutils
{
	template< unsigned Bits >
	struct LeastUIntDef
	{
		static_assert(Bits <= BitSize<uintmax_t>::Value, "No type large enough");
		LeastUIntDef(void) = delete;
		using Type = typename Details::LeastType<Bits, uint_least8_t, uint_least16_t, uint_least32_t, uint_least64_t, uintmax_t>;
	};

	template< unsigned Bits >
	using LeastUInt = typename LeastUIntDef< Bits >::Type;
}
