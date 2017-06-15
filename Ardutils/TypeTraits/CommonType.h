#pragma once

#include "Decay.h"
#include "DeclVal.h"
#include "VoidT.h"

//
// CommonType
//

namespace Ardutils
{
	// C++11
	template< typename... Ts >
	struct CommonType {};

	template< typename T >
	struct CommonType<T>
	{
		using Type = typename Decay<T>::Type;
	};

	template< typename T, typename U >
	struct CommonType< T, U >
	{
		using Type = typename Decay< decltype(false ? DeclVal<T>() : DeclVal<U>()) >::Type;
	};

	template< typename T, typename U, typename... Ts >
	struct CommonType< T, U, Ts... >
	{
		using Type = typename CommonType< typename CommonType< T, U >::Type, Ts... >::Type;
	};

	// C++14
	template< typename... Ts >
	using CommonTypeT = typename CommonType< Ts... >::Type;
}