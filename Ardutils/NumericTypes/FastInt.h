#pragma once

#include <stdint.h>

#include "../BitSize.h"

#include "Details.h"

namespace Ardutils
{
	template< unsigned Bits >
	struct FastIntDef
	{
		static_assert(Bits <= BitSize<intmax_t>::Value, "No type large enough");
		FastIntDef(void) = delete;
		using Type = typename Details::LeastType<Bits, int_fast8_t, int_fast16_t, int_fast32_t, int_fast64_t, intmax_t>;
	};

	template< unsigned Bits >
	using FastInt = typename FastIntDef< Bits >::Type;
}
