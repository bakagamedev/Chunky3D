#pragma once

//
// AddRValueReference
//

namespace Ardutils
{
	// C++11
	template< typename T >
	struct AddRValueReference { using Type = T&&; };

	template< typename T >
	struct AddRValueReference< T& > { using Type = T&; };

	template< typename T >
	struct AddRValueReference< T&& > { using Type = T&&; };

	// C++14
	template< typename T >
	using AddRValueReferenceT = typename AddRValueReference< T >::Type;
}