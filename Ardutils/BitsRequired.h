#pragma once

namespace Ardutils
{
	template< unsigned long long Number >
	struct BitsRequired
	{
		BitsRequired(void) = delete;

		constexpr static const unsigned Value = 1 + BitsRequired<(Number >> 1)>::Value;
	};

	template<>
	struct BitsRequired<0ull>
	{
		BitsRequired(void) = delete;

		constexpr static const unsigned Value = 0u;
	};
}
