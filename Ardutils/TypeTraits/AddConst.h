#pragma once

//
// AddConst
//

namespace Ardutils
{
	// C++11
	template< typename T >
	struct AddConst { using Type = const T; };

	// C++14
	template< typename T >
	using AddConstT = typename AddConst< T >::Type;
}