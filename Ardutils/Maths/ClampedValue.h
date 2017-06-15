#pragma once

#include "../Debug.h"
#include "../Utils.h"

//
// Declaration
//

namespace Ardutils
{
	template<typename TValue>
	class ClampedValue
	{
	private:
		TValue value;
		TValue minValue;
		TValue maxValue;

	public:
		ClampedValue(const TValue & value, const TValue & minValue, const TValue & maxValue);

		TValue GetValue(void) const;
		TValue GetMin(void) const;
		TValue GetMax(void) const;

		void SetValue(const TValue & value);
		void SetMin(const TValue & value);
		void SetMax(const TValue & value);

		operator TValue(void) const;

		ClampedValue<TValue> & operator =(const TValue & value);
		
		ClampedValue<TValue> & operator +=(const TValue & value);
		ClampedValue<TValue> & operator -=(const TValue & value);

		ClampedValue<TValue> & operator ++(void);
		ClampedValue<TValue> & operator --(void);
	};
}


//
// Definition
//

template<typename TValue>
Ardutils::ClampedValue<TValue>::ClampedValue(const TValue & value, const TValue & minValue, const TValue & maxValue)
	: minValue(minValue), maxValue(maxValue)
{
	this->value = Clamp(value, minValue, maxValue);
}

template<typename TValue>
TValue Ardutils::ClampedValue<TValue>::GetValue(void) const
{
	return this->value;
}

template<typename TValue>
TValue Ardutils::ClampedValue<TValue>::GetMin(void) const
{
	return this->minValue;
}

template<typename TValue>
TValue Ardutils::ClampedValue<TValue>::GetMax(void) const
{
	return this->maxValue;
}

template<typename TValue>
void Ardutils::ClampedValue<TValue>::SetValue(const TValue & value)
{
	this->value = Clamp(this->value, this->minValue, this->maxValue);
}

template<typename TValue>
void Ardutils::ClampedValue<TValue>::SetMin(const TValue & value)
{
	DEBUG_ASSERT(value <= this->maxValue);

	this->minValue = value;
	this->value = Max(this->value, this->minValue);
}

template<typename TValue>
void Ardutils::ClampedValue<TValue>::SetMax(const TValue & value)
{
	DEBUG_ASSERT(value >= this->minValue);

	this->maxValue = value;
	this->value = Min(this->value, this->maxValue);
}

template<typename TValue>
Ardutils::ClampedValue<TValue>::operator TValue(void) const
{
	return this->value;
}

template<typename TValue>
Ardutils::ClampedValue<TValue> & Ardutils::ClampedValue<TValue>::operator =(const TValue & value)
{
	this->value = Clamp(this->value, this->minValue, this->maxValue);
	return *this;
}

template<typename TValue>
Ardutils::ClampedValue<TValue> & Ardutils::ClampedValue<TValue>::operator +=(const TValue & value)
{
	// Explicit type required on Clamp because of integer promotion rules
	this->value = Clamp<TValue>(this->value + value, this->minValue, this->maxValue);
	return *this;
}

template<typename TValue>
Ardutils::ClampedValue<TValue> & Ardutils::ClampedValue<TValue>::operator -=(const TValue & value)
{
	// Explicit type required on Clamp because of integer promotion rules
	this->value = Clamp<TValue>(this->value - value, this->minValue, this->maxValue);
	return *this;
}

template<typename TValue>
Ardutils::ClampedValue<TValue> & Ardutils::ClampedValue<TValue>::operator ++(void)
{
	// Explicit type required on Min because of integer promotion rules
	this->value = Min<TValue>(this->value + 1, this->maxValue);
	return *this;
}

template<typename TValue>
Ardutils::ClampedValue<TValue> & Ardutils::ClampedValue<TValue>::operator --(void)
{
	// Explicit type required on Max because of integer promotion rules
	this->value = Max<TValue>(this->value - 1, this->minValue);
	return *this;
}
