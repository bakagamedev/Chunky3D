#pragma once

//
// AddLValueReference
//

namespace Ardutils
{
	// C++11
	template< typename T >
	struct AddLValueReference { using Type = T&; };

	template< typename T >
	struct AddLValueReference< T& > { using Type = T&; };

	template< typename T >
	struct AddLValueReference< T&& > { using Type = T&; };

	// C++14
	template< typename T >
	using AddLValueReferenceT = typename AddLValueReference< T >::Type;
}