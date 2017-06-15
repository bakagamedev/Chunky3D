#pragma once

namespace Ardutils
{
	template< typename T, typename U = T >
	constexpr U Sign(const T & value) noexcept
	{
		return (value < static_cast<T>(0))
			? static_cast<U>(-1)
			: (value > static_cast<T>(0))
			? static_cast<U>(1)
			: static_cast<U>(0);
	}

	template< typename T, T Value, typename U = T >
	constexpr U Sign(void) noexcept
	{
		return (Value < static_cast<T>(0))
			? static_cast<U>(-1)
			: (Value > static_cast<T>(0))
			? static_cast<U>(1)
			: static_cast<U>(0);
	}

	template< typename T >
	constexpr bool IsOdd(const T & value) noexcept
	{
		return ((value % static_cast<T>(2)) != 0);
	}

	template< typename T, T Value >
	constexpr bool IsOdd(void) noexcept
	{
		return ((Value % static_cast<T>(2)) != 0);
	}

	template< typename T >
	constexpr bool IsEven(const T & value) noexcept
	{
		return ((value % static_cast<T>(2)) == 0);
	}

	template< typename T, T Value >
	constexpr bool IsEven(void) noexcept
	{
		return ((Value % static_cast<T>(2)) == 0);
	}
}