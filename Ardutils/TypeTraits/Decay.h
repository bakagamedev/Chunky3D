#pragma once

#include "RemoveReference.h"
#include "Conditional.h"
#include "IsArray.h"
#include "RemoveExtent.h"
#include "IsFunction.h"
#include "AddPointer.h"
#include "RemoveCV.h"

//
// Decay
//

namespace Ardutils
{
	// C++11
	template< typename T >
	struct Decay
	{
	private:
		using U = typename RemoveReference<T>::Type;
	public:
		using Type =
			typename Conditional
			<
				IsArray<U>::Value,
				typename RemoveExtent<U>::Type*,
				typename Conditional
				<
					IsFunction<U>::Value,
					typename AddPointer<U>::Type,
					typename RemoveCV<U>::Type
				>::Type
			>::Type;
	};

	// C++14
	template< typename T >
	using DecayT = typename Decay< T >::Type;
}