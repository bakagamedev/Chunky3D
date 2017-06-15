#pragma once

#include "../Utils.h"

#include "Range.h"

//
// Declaration
//

namespace Ardutils
{
	template<typename TValue, TValue Min, TValue Max>
	class StaticRange
	{
	public:
		TValue GetMin(void) const;
		TValue GetMax(void) const;

		operator Range<TValue>(void) const;

		TValue Clamp(const TValue & value) const;
	};
}


//
// Definition
//

template<typename TValue, TValue Min, TValue Max>
TValue Ardutils::StaticRange<TValue, Min, Max>::GetMin(void) const
{
	return Min;
}

template<typename TValue, TValue Min, TValue Max>
TValue Ardutils::StaticRange<TValue, Min, Max>::GetMax(void) const
{
	return Max;
}

template<typename TValue, TValue Min, TValue Max>
Ardutils::StaticRange<TValue, Min, Max>::operator Ardutils::Range<TValue>(void) const
{
	return Ardutils::Range<TValue>(Min, Max);
}

template<typename TValue, TValue Min, TValue Max>
TValue Ardutils::StaticRange<TValue, Min, Max>::Clamp(const TValue & value) const
{
	return Ardutils::Clamp<TValue, Min, Max>(value);
}
