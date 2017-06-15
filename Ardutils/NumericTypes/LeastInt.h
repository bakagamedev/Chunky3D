#pragma once

#include <stdint.h>

#include "../BitSize.h"

#include "Details.h"

namespace Ardutils
{
	template< unsigned Bits >
	struct LeastIntDef
	{
		static_assert(Bits <= BitSize<intmax_t>::Value, "No type large enough");
		LeastIntDef(void) = delete;
		using Type = typename Details::LeastType<Bits, int_least8_t, int_least16_t, int_least32_t, int_least64_t, intmax_t>;
	};

	template< unsigned Bits >
	using LeastInt = typename LeastIntDef< Bits >::Type;
}
