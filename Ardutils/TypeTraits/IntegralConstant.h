#pragma once

//
// IntegralConstant
//

namespace Ardutils
{
	// C++11
	template< typename T, T V >
	struct IntegralConstant
	{
		using ValueType = T;
		using Type = IntegralConstant;

		constexpr static const ValueType Value = V;

		constexpr operator ValueType(void) const noexcept
		{
			return Value;
		}

		// C++14
		constexpr ValueType operator()(void) const noexcept
		{
			return Value;
		}
	};

	// C++17
	template< bool B > using BoolConstant = IntegralConstant< bool, B >;
	using TrueType = BoolConstant< true >;
	using FalseType = BoolConstant< false >;
}
