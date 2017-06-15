#pragma once

#include "WrappedValue.h"

//
// Declaration
//

namespace Ardutils
{
	template< typename TValue, TValue Min, TValue Max >
	class StaticWrappedValue
	{
	private:
		TValue value;

	public:
		StaticWrappedValue(void);

		TValue GetValue(void) const;
		TValue GetMin(void) const;
		TValue GetMax(void) const;

		operator TValue(void) const;
		operator WrappedValue<TValue>(void) const;

		StaticWrappedValue< TValue, Min, Max > & operator ++(void);
		StaticWrappedValue< TValue, Min, Max >  & operator --(void);
	};
}


//
// Definition
//

template< typename TValue, TValue Min, TValue Max >
Ardutils::StaticWrappedValue< TValue, Min, Max >::StaticWrappedValue(void)
	: value(Min)
{
}

template< typename TValue, TValue Min, TValue Max >
TValue Ardutils::StaticWrappedValue< TValue, Min, Max >::GetValue(void) const
{
	return this->value;
}

template< typename TValue, TValue Min, TValue Max >
TValue Ardutils::StaticWrappedValue< TValue, Min, Max >::GetMin(void) const
{
	return Min;
}

template< typename TValue, TValue Min, TValue Max >
TValue Ardutils::StaticWrappedValue< TValue, Min, Max >::GetMax(void) const
{
	return Max;
}

template< typename TValue, TValue Min, TValue Max >
Ardutils::StaticWrappedValue< TValue, Min, Max >::operator TValue(void) const
{
	return this->value;
}

template<typename TValue, TValue Min, TValue Max>
Ardutils::StaticWrappedValue<TValue, Min, Max>::operator Ardutils::WrappedValue<TValue>(void) const
{
	return Ardutils::WrappedValue<TValue>(Min, Max);
}

template< typename TValue, TValue Min, TValue Max >
Ardutils::StaticWrappedValue< TValue, Min, Max > & Ardutils::StaticWrappedValue< TValue, Min, Max >::operator ++(void)
{
	if (this->value == Max)
		this->value = Min;
	else
		++this->value;
	return *this;
}

template< typename TValue, TValue Min, TValue Max >
Ardutils::StaticWrappedValue< TValue, Min, Max >  & Ardutils::StaticWrappedValue< TValue, Min, Max >::operator --(void)
{
	if (this->value == Min)
		this->value = Max;
	else
		--this->value;
	return *this;
}
