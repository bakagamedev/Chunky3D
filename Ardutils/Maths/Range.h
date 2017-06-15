#pragma once

#include "../Debug.h"
#include "../Utils.h"

//
// Declaration
//

namespace Ardutils
{
	template<typename TValue>
	class Range
	{
	private:
		TValue minValue;
		TValue maxValue;

	public:
		Range(const TValue & minValue, const TValue & maxValue);

		TValue GetMin(void) const;
		TValue GetMax(void) const;

		TValue Clamp(const TValue & value) const;
	};
}


//
// Definition
//

template<typename TValue>
Ardutils::Range<TValue>::Range(const TValue & minValue, const TValue & maxValue)
	: minValue(minValue), maxValue(maxValue)
{
	DEBUG_ASSERT(minValue < maxValue);
}

template<typename TValue>
TValue Ardutils::Range<TValue>::GetMin(void) const
{
	return this->minValue;
}

template<typename TValue>
TValue Ardutils::Range<TValue>::GetMax(void) const
{
	return this->maxValue;
}

template<typename TValue>
TValue Ardutils::Range<TValue>::Clamp(const TValue & value) const
{
	return Clamp(value, this->minValue, this->maxValue);
}
