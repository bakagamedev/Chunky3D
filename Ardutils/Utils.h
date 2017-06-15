#pragma once

namespace Ardutils
{
	template< typename T, typename U = T >
	constexpr auto Min(const T & left, const U & right) noexcept ->
		decltype((left < right) ? left : right)
	{
		return (left < right) ? left : right;
	}

	template< typename T, typename U = T, U Other >
	constexpr auto Min(const T & value) noexcept ->
		decltype((value < Other) ? value : Other)
	{
		return (value < Other) ? value : Other;
	}

	template< typename T, T Left, typename U = T, U Right >
	constexpr auto Min(void) noexcept ->
		decltype((Left < Right) ? Left : Right)
	{
		return (Left < Right) ? Left : Right;
	}

	template< typename T, typename U = T >
	constexpr auto Max(const T & left, const U & right) noexcept ->
		decltype((left > right) ? left : right)
	{
		return (left > right) ? left : right;
	}

	template< typename T, typename U = T, U Other >
	constexpr auto Max(const T & value) noexcept ->
		decltype((value > Other) ? value : Other)
	{
		return (value > Other) ? value : Other;
	}

	template< typename T, T Left, typename U = T, U Right >
	constexpr auto Max(void) noexcept ->
		decltype((Left > Right) ? Left : Right)
	{
		return (Left > Right) ? Left : Right;
	}

	template< typename T, typename TMin = T, typename TMax = TMin>
	constexpr auto Clamp(const T & value, const TMin & min, const TMax & max) noexcept ->
		decltype((value < min) ? min : (value > max) ? max : value)
	{
		return (value < min) ? min : (value > max) ? max : value;
	}

	template< typename T, T Min, T Max >
	constexpr T Clamp(const T & value) noexcept
	{
		return (value < Min) ? Min : (value > Max) ? Max : value;
	}

	template< typename T, T Value, T Min, T Max >
	constexpr T Clamp(void) noexcept
	{
		return (Value < Min) ? Min : (Value > Max) ? Max : Value;
	}

	template< typename T, typename U = T>
	constexpr bool InRange(const T & value, const U & min, const U & max) noexcept
	{
		return (value >= min) && (value <= max);
	}

	template< typename T, typename U = T, U Min, U Max >
	constexpr bool InRange(const T & value) noexcept
	{
		return (value >= Min) && (value <= Max);
	}

	template< typename T, T Value, typename U = T, U Min, U Max >
	constexpr bool InRange(void) noexcept
	{
		return (Value >= Min) && (Value <= Max);
	}
}


