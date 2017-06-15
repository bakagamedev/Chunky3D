#pragma once

//
// RemoveReference
//

namespace Ardutils
{
	// C++11
	template< typename T >
	struct RemoveReference { using Type = T; };

	template< typename T >
	struct RemoveReference< T& > { using Type = T; };

	template< typename T >
	struct RemoveReference< T&& > { using Type = T; };

	// C++14
	template< typename T >
	using RemoveReferenceT = typename RemoveReference< T >::Type;
}