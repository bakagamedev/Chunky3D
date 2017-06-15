#pragma once

#include "IsEnum.h"

#include "../Details/CompilerTraitsStart.h"

//
// UnderlyingType
//

namespace Ardutils
{
#if HAS_COMPILER_TRAIT_UNDERLYING_TYPE
	
	// C++11
	template< typename T >
	struct UnderlyingType
	{
		static_assert(IsEnum<T>::Value, "Cannot get underlying type of non-enum.");
		using Type = COMPILER_TRAIT_UNDERLYING_TYPE(T);
	};
#else
#warning "Compiler does not support UnderlyingType"
#endif
}

#include "../Details/CompilerTraitsEnd.h"