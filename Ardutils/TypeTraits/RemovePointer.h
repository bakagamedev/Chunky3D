#pragma once

//
// RemovePointer
//

namespace Ardutils
{
	// C++11
	template< typename T >
	struct RemovePointer { using Type = T; };

	template< typename T >
	struct RemovePointer<T*> { using Type = T; };

	template< typename T >
	struct RemovePointer<T* const> { using Type = T; };

	template< typename T >
	struct RemovePointer<T* volatile> { using Type = T; };

	template< typename T >
	struct RemovePointer<T* const volatile> { using Type = T; };

	// C++14
	template< typename T >
	using RemovePointerT = typename RemovePointer< T >::Type;
}