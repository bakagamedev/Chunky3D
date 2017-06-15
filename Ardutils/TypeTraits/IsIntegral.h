#pragma once

#include "IntegralConstant.h"
#include "RemoveCV.h"

#include "../Details/VersioningStart.h"

//
// IsIntegral
//

namespace Ardutils
{
	namespace Details
	{
		template< typename T >
		struct IsIntegral : FalseType {};

		template<> struct IsIntegral< bool > : TrueType {};

		template<> struct IsIntegral< char > : TrueType {};

		template<> struct IsIntegral< char16_t > : TrueType {};

		template<> struct IsIntegral< char32_t > : TrueType {};

		template<> struct IsIntegral< wchar_t > : TrueType {};

		template<> struct IsIntegral< signed char > : TrueType {};

		template<> struct IsIntegral< unsigned char > : TrueType {};

		template<> struct IsIntegral< signed short > : TrueType {};

		template<> struct IsIntegral< unsigned short > : TrueType {};

		template<> struct IsIntegral< signed int > : TrueType {};

		template<> struct IsIntegral< unsigned int > : TrueType {};

		template<> struct IsIntegral< signed long > : TrueType {};

		template<> struct IsIntegral< unsigned long > : TrueType {};

		template<> struct IsIntegral< signed long long > : TrueType {};

		template<> struct IsIntegral< unsigned long long > : TrueType {};
	}

	// C++11
	template< typename T >
	struct IsIntegral :
		Details::IsIntegral< typename RemoveCV< T >::Type > {};

	// C++17
	// C++14 is needed for template variables
#if AT_LEAST_CPP_14
	
	template< typename T >
	constexpr bool IsIntegralV = IsIntegral<T>::Value;
	
#endif
}

#include "../Details/VersioningEnd.h"