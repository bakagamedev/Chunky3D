#pragma once

#include <stdint.h>

#include "../BitSize.h"

#include "Details.h"

namespace Ardutils
{
	template< unsigned Bits >
	struct FastUIntDef
	{
		static_assert(Bits <= BitSize<uintmax_t>::Value, "No type large enough");
		FastUIntDef(void) = delete;
		using Type = typename Details::LeastType<Bits, uint_fast8_t, uint_fast16_t, uint_fast32_t, uint_fast64_t, uintmax_t>;
	};

	template< unsigned Bits >
	using FastUInt = typename FastUIntDef< Bits >::Type;
}
