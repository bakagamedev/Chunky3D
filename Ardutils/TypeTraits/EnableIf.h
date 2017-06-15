#pragma once

//
// EnableIf
//

namespace Ardutils
{
	// C++11
	template< bool Condition, typename T = void >
	struct EnableIf;

	template< typename T >
	struct EnableIf< false, T > {};

	template< typename T >
	struct EnableIf< true, T > { using Type = T; };

	// C++14
	template< bool Condition, typename T >
	using EnableIfT = typename EnableIf< Condition, T >::Type;
}