#pragma once

#include "IntegralConstant.h"

#include "../Details/VersioningStart.h"
#include "../Details/CompilerTraitsStart.h"

//
// IsClass
//

namespace Ardutils
{
#if HAS_COMPILER_TRAIT_IS_CLASS

	// C++11
	template< typename T >
	struct IsClass :
		BoolConstant< COMPILER_TRAIT_IS_CLASS(T) > {};

	// C++17
	// C++14 is needed for template variables
#if AT_LEAST_CPP_14
	
	template< typename T >
	constexpr bool IsClassV = IsClass< T >::Value;

#endif
#else

#if HAS_COMPILER_TRAIT_IS_UNION
	#include "IsUnion.h"
#else
	#warning "IsClass will be true for all union types because this compiler does not support IsUnion."
#endif

	namespace Details
	{
		template< typename T >
		TrueType IsClassF(int T::*);

		template< typename T >
		FalseType IsClassF(...);

		template< typename T >
		using IsClass = decltype(IsClassF<T>(0));
	}

	template< typename T >
	struct IsClass :
		BoolConstant<Details::IsClass<T>::Value && !IsUnion<T>::Value> {};

	// C++17
	// C++14 is needed for template variables
#if AT_LEAST_CPP_14

	template< typename T >
	constexpr bool IsClassV = IsClass< T >::Value;

#endif
#endif
}

#include "../Details/CompilerDetectEnd.h"
#include "../Details/VersioningEnd.h"