#pragma once

//
// RemoveConst
//

namespace Ardutils
{
	// C++11
	template< typename T >
	struct RemoveConst { using Type = T; };

	template< typename T >
	struct RemoveConst< const T > { using Type = T; };

	// C++14
	template< typename T >
	using RemoveConstT = typename RemoveConst< T >::Type;
}