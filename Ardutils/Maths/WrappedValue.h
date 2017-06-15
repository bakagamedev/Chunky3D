#pragma once

//
// Declaration
//

namespace Ardutils
{
	template< typename TValue >
	class WrappedValue
	{
	private:
		TValue value;
		TValue minValue;
		TValue maxValue;

	public:
		WrappedValue(const TValue & minValue, const TValue & maxValue);
		WrappedValue(const WrappedValue< TValue > & other);

		TValue GetValue(void) const;
		TValue GetMin(void) const;
		TValue GetMax(void) const;

		operator TValue(void) const;

		WrappedValue< TValue > & operator ++(void);
		WrappedValue< TValue > & operator --(void);

		WrappedValue< TValue > & operator=(const WrappedValue< TValue > & other) noexcept;
	};
}


//
// Definition
//

template< typename TValue >
Ardutils::WrappedValue< TValue >::WrappedValue(const TValue & minValue, const TValue & maxValue)
	: value(minValue), minValue(minValue), maxValue(maxValue)
{
}

template< typename TValue >
Ardutils::WrappedValue< TValue >::WrappedValue(const Ardutils::WrappedValue< TValue > & other)
	: value(other.value), minValue(other.minValue), maxValue(other.maxValue)
{
}

template< typename TValue >
TValue Ardutils::WrappedValue< TValue >::GetValue(void) const
{
	return this->value;
}

template< typename TValue >
TValue Ardutils::WrappedValue< TValue >::GetMin(void) const
{
	return this->minValue;
}

template< typename TValue >
TValue Ardutils::WrappedValue< TValue >::GetMax(void) const
{
	return this->maxValue;
}

template< typename TValue >
Ardutils::WrappedValue< TValue >::operator TValue(void) const
{
	return this->value;
}

template< typename TValue >
Ardutils::WrappedValue< TValue > & Ardutils::WrappedValue< TValue >::operator ++(void)
{
	if (this->value == this->maxValue)
		this->value = this->minValue;
	else
		++this->value;
	return *this;
}

template< typename TValue >
Ardutils::WrappedValue< TValue >  & Ardutils::WrappedValue< TValue >::operator --(void)
{
	if (this->value == this->minValue)
		this->value = this->maxValue;
	else
		--this->value;
	return *this;
}

template< typename TValue >
Ardutils::WrappedValue< TValue > & Ardutils::WrappedValue< TValue >::operator=(const Ardutils::WrappedValue< TValue > & other) noexcept
{
	this->value = other.value;
	this->minValue = other.minValue;
	this->maxValue = other.maxValue;
	return *this;
}
