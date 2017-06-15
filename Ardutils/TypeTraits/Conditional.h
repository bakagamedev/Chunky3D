#pragma once

//
// Conditional
//

namespace Ardutils
{
	// C++11
	template< bool Condition, typename TTrue, typename TFalse >
	struct Conditional;

	template< typename TTrue, typename TFalse >
	struct Conditional< true, TTrue, TFalse > { using Type = TTrue; };

	template< typename TTrue, typename TFalse >
	struct Conditional< false, TTrue, TFalse > { using Type = TFalse; };

	// C++14
	template< bool Condition, typename TTrue, typename TFalse >
	using ConditionalT = typename Conditional< Condition, TTrue, TFalse >::Type;
}