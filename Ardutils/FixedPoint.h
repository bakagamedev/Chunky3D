#pragma once

#include <math.h>

#include "Bitwise.h"

//
// Declaration
//

namespace Ardutils
{	
	template< unsigned Integer, unsigned Fraction >
	class FixedPoint
	{
	public:
		static_assert((Integer + Fraction) <= 64, "Attempt to initialise FixedPoint with InternalSize exceeding 64 bits.");

	public:
		constexpr const static unsigned IntegerSize = Integer;
		constexpr const static unsigned FractionSize = Fraction;
		constexpr const static unsigned InternalSize = Integer + Fraction;
		constexpr const static unsigned long long Scale = IdentityMask<FractionSize>::Value + 1;

	public:
		using InternalType = typename LeastType<InternalSize>;
		using IntegerType = typename LeastType<IntegerSize>;
		using FractionType = typename LeastType<FractionSize>;

	private:
		InternalType value;

	public:
		constexpr FixedPoint(const InternalType & value);
		constexpr FixedPoint(const IntegerType & integer, const FractionType & fraction);
		constexpr FixedPoint(const float & value);
		constexpr FixedPoint(const double & value);

		InternalType GetValue(void) const;
		IntegerType GetInteger(void) const;
		FractionType GetFraction(void) const;

		constexpr explicit operator IntegerType(void) const;
		constexpr explicit operator float(void) const;
		constexpr explicit operator double(void) const;

		template< unsigned IntegerOut, unsigned FractionOut >
		explicit operator FixedPoint<IntegerOut, FractionOut>(void) const;

		FixedPoint & operator +=(const FixedPoint & other);
		FixedPoint & operator -=(const FixedPoint & other);
		FixedPoint & operator *=(const FixedPoint & value);
		FixedPoint & operator /=(const FixedPoint & value);
	};

	template< unsigned Integer, unsigned Fraction >
	Ardutils::FixedPoint<Integer, Fraction> Floor(const Ardutils::FixedPoint<Integer, Fraction> & value);

	template< unsigned Integer, unsigned Fraction >
	Ardutils::FixedPoint<Integer, Fraction> Ceil(const Ardutils::FixedPoint<Integer, Fraction> & value);

	template< unsigned Integer, unsigned Fraction >
	Ardutils::FixedPoint<Integer, Fraction> Round(const Ardutils::FixedPoint<Integer, Fraction> & value);
	
	template< unsigned Integer, unsigned Fraction >
	bool operator ==(const Ardutils::FixedPoint<Integer, Fraction> & left, const Ardutils::FixedPoint<Integer, Fraction> & right);

	template< unsigned Integer, unsigned Fraction >
	bool operator !=(const Ardutils::FixedPoint<Integer, Fraction> & left, const Ardutils::FixedPoint<Integer, Fraction> & right);

	template< unsigned Integer, unsigned Fraction >
	bool operator <(const Ardutils::FixedPoint<Integer, Fraction> & left, const Ardutils::FixedPoint<Integer, Fraction> & right);

	template< unsigned Integer, unsigned Fraction >
	bool operator >(const Ardutils::FixedPoint<Integer, Fraction> & left, const Ardutils::FixedPoint<Integer, Fraction> & right);

	template< unsigned Integer, unsigned Fraction >
	bool operator <=(const Ardutils::FixedPoint<Integer, Fraction> & left, const Ardutils::FixedPoint<Integer, Fraction> & right);

	template< unsigned Integer, unsigned Fraction >
	bool operator >=(const Ardutils::FixedPoint<Integer, Fraction> & left, const Ardutils::FixedPoint<Integer, Fraction> & right);

	template< unsigned Integer, unsigned Fraction >
	Ardutils::FixedPoint<Integer, Fraction> operator +(const FixedPoint<Integer, Fraction> & left, const Ardutils::FixedPoint<Integer, Fraction> & right);

	template< unsigned Integer, unsigned Fraction >
	Ardutils::FixedPoint<Integer, Fraction> operator +(const FixedPoint<Integer, Fraction> & left, const typename Ardutils::FixedPoint<Integer, Fraction>::IntegerType & right);

	template< unsigned Integer, unsigned Fraction >
	Ardutils::FixedPoint<Integer, Fraction> operator -(const FixedPoint<Integer, Fraction> & left, const Ardutils::FixedPoint<Integer, Fraction> & right);

	template< unsigned Integer, unsigned Fraction >
	Ardutils::FixedPoint<Integer, Fraction> operator -(const FixedPoint<Integer, Fraction> & left, const typename Ardutils::FixedPoint<Integer, Fraction>::IntegerType & right);
	
	template< unsigned Integer, unsigned Fraction >
	Ardutils::FixedPoint<Integer, Fraction> operator *(const Ardutils::FixedPoint<Integer, Fraction> & left, const Ardutils::FixedPoint<Integer, Fraction> & right);

	template< unsigned Integer, unsigned Fraction >
	Ardutils::FixedPoint<Integer, Fraction> operator *(const Ardutils::FixedPoint<Integer, Fraction> & left, const typename Ardutils::FixedPoint<Integer, Fraction>::IntegerType & right);

	template< unsigned Integer, unsigned Fraction >
	Ardutils::FixedPoint<Integer, Fraction> operator /(const Ardutils::FixedPoint<Integer, Fraction> & left, const Ardutils::FixedPoint<Integer, Fraction> & right);

	template< unsigned Integer, unsigned Fraction >
	Ardutils::FixedPoint<Integer, Fraction> operator /(const Ardutils::FixedPoint<Integer, Fraction> & left, const typename Ardutils::FixedPoint<Integer, Fraction>::IntegerType & right);

	template< unsigned Integer, unsigned Fraction >
	Ardutils::FixedPoint<Integer * 2, Fraction * 2> Multiply(const Ardutils::FixedPoint<Integer, Fraction> & left, const Ardutils::FixedPoint<Integer, Fraction> & right);
}


//
// Definition
//

template< unsigned Integer, unsigned Fraction >
constexpr Ardutils::FixedPoint<Integer, Fraction>::FixedPoint(const InternalType & value)
	: value(value)
{
}

template< unsigned Integer, unsigned Fraction >
constexpr Ardutils::FixedPoint<Integer, Fraction>::FixedPoint(const IntegerType & integer, const FractionType & fraction)
	: value(static_cast<InternalType>((integer << FractionSize) | fraction))
{
}

template< unsigned Integer, unsigned Fraction >
constexpr Ardutils::FixedPoint<Integer, Fraction>::FixedPoint(const float & value)
	: value(static_cast<InternalType>(value * Scale))
{
}

template< unsigned Integer, unsigned Fraction >
constexpr Ardutils::FixedPoint<Integer, Fraction>::FixedPoint(const double & value)
	: value(static_cast<InternalType>(value * Scale))
{
}

template< unsigned Integer, unsigned Fraction >
typename Ardutils::FixedPoint<Integer, Fraction>::InternalType Ardutils::FixedPoint<Integer, Fraction>::GetValue(void) const
{
	return this->value;
}

template< unsigned Integer, unsigned Fraction >
typename Ardutils::FixedPoint<Integer, Fraction>::IntegerType Ardutils::FixedPoint<Integer, Fraction>::GetInteger(void) const
{
	return static_cast<IntegerType>((this->value >> FractionSize) & IdentityMask<IntegerSize>::Value);
}

template< unsigned Integer, unsigned Fraction >
typename Ardutils::FixedPoint<Integer, Fraction>::FractionType Ardutils::FixedPoint<Integer, Fraction>::GetFraction(void) const
{
	return static_cast<FractionType>(this->value & IdentityMask<FractionSize>::Value);
}

template< unsigned Integer, unsigned Fraction >
constexpr Ardutils::FixedPoint<Integer, Fraction>::operator IntegerType(void) const
{
	return this->GetInteger();
}

template< unsigned Integer, unsigned Fraction >
constexpr Ardutils::FixedPoint<Integer, Fraction>::operator float(void) const
{
	return (this->value * (1.0f / Scale));
}

template< unsigned Integer, unsigned Fraction >
constexpr Ardutils::FixedPoint<Integer, Fraction>::operator double(void) const
{
	return (this->value * (1.0 / Scale));
}

template< unsigned Integer, unsigned Fraction >
template< unsigned IntegerOut, unsigned FractionOut >
Ardutils::FixedPoint<Integer, Fraction>::operator FixedPoint<IntegerOut, FractionOut>(void) const
{
	static_assert(IntegerOut + FractionOut <= 64, "Cannot convert, resulting type is too large.");

	using Output = FixedPoint<IntegerOut, FractionOut>;

	if (FractionOut > Fraction)
	{
		constexpr const auto Difference = FractionOut - Fraction;
		return Output(static_cast<Output::InternalType>(this->value << Difference));
	}
	else
	{
		constexpr const auto Difference = Fraction - FractionOut;
		return Output(static_cast<Output::InternalType>(this->value >> Difference));
	}
}

template< unsigned Integer, unsigned Fraction >
Ardutils::FixedPoint<Integer, Fraction> & Ardutils::FixedPoint<Integer, Fraction>::operator +=(const Ardutils::FixedPoint<Integer, Fraction> &  other)
{
	this->value += other.value;
	return *this;
}

template< unsigned Integer, unsigned Fraction >
Ardutils::FixedPoint<Integer, Fraction> & Ardutils::FixedPoint<Integer, Fraction>::operator -=(const Ardutils::FixedPoint<Integer, Fraction> &  other)
{
	this->value -= other.value;
	return *this;
}

template< unsigned Integer, unsigned Fraction >
Ardutils::FixedPoint<Integer, Fraction> & Ardutils::FixedPoint<Integer, Fraction>::operator *=(const Ardutils::FixedPoint<Integer, Fraction> &  other)
{
	this->value *= other.value;
	this->value >>= Fraction;
	return *this;
}

template< unsigned Integer, unsigned Fraction >
Ardutils::FixedPoint<Integer, Fraction> & Ardutils::FixedPoint<Integer, Fraction>::operator /=(const Ardutils::FixedPoint<Integer, Fraction> &  other)
{
	this->value <<= Fraction;
	this->value /= other.value;
	return *this;
}

template< unsigned Integer, unsigned Fraction >
Ardutils::FixedPoint<Integer, Fraction> Ardutils::Floor(const Ardutils::FixedPoint<Integer, Fraction> & value)
{
	using OutputType = Ardutils::FixedPoint<Integer, Fraction>;
	using InternalType = OutputType::InternalType;
	return OutputType(static_cast<InternalType>(value.GetValue() & ~IdentityMask<Fraction>::Value));
}

template< unsigned Integer, unsigned Fraction >
Ardutils::FixedPoint<Integer, Fraction> Ardutils::Ceil(const Ardutils::FixedPoint<Integer, Fraction> & value)
{
	using OutputType = Ardutils::FixedPoint<Integer, Fraction>;
	using InternalType = OutputType::InternalType;
	return OutputType(static_cast<InternalType>((value.GetValue() & ~IdentityMask<Fraction>::Value) + (1 << Fraction)));
}

template< unsigned Integer, unsigned Fraction >
Ardutils::FixedPoint<Integer, Fraction> Ardutils::Round(const Ardutils::FixedPoint<Integer, Fraction> & value)
{
	return (value & MsbMask<Fraction>::Value) != 0 ? Ceil(value) : Floor(value);
}

template< unsigned Integer, unsigned Fraction >
bool Ardutils::operator ==(const Ardutils::FixedPoint<Integer, Fraction> & left, const Ardutils::FixedPoint<Integer, Fraction> & right)
{
	return (left.GetValue() == right.GetValue());
}

template< unsigned Integer, unsigned Fraction >
bool Ardutils::operator !=(const Ardutils::FixedPoint<Integer, Fraction> & left, const Ardutils::FixedPoint<Integer, Fraction> & right)
{
	return (left.GetValue() != right.GetValue());
}

template< unsigned Integer, unsigned Fraction >
bool Ardutils::operator <(const Ardutils::FixedPoint<Integer, Fraction> & left, const Ardutils::FixedPoint<Integer, Fraction> & right)
{
	return (left.GetValue() < right.GetValue());
}

template< unsigned Integer, unsigned Fraction >
bool Ardutils::operator >=(const Ardutils::FixedPoint<Integer, Fraction> & left, const Ardutils::FixedPoint<Integer, Fraction> & right)
{
	return (left.GetValue() >= right.GetValue());
}

template< unsigned Integer, unsigned Fraction >
bool Ardutils::operator <=(const Ardutils::FixedPoint<Integer, Fraction> & left, const Ardutils::FixedPoint<Integer, Fraction> & right)
{
	return (left.GetValue() <= right.GetValue());
}

template< unsigned Integer, unsigned Fraction >
bool Ardutils::operator >(const Ardutils::FixedPoint<Integer, Fraction> & left, const Ardutils::FixedPoint<Integer, Fraction> & right)
{
	return (left.GetValue() > right.GetValue());
}

template< unsigned Integer, unsigned Fraction >
Ardutils::FixedPoint<Integer, Fraction> Ardutils::operator +(const Ardutils::FixedPoint<Integer, Fraction> & left, const Ardutils::FixedPoint<Integer, Fraction> & right)
{
	using InternalType = FixedPoint<Integer, Fraction>::InternalType;
	return FixedPoint<Integer, Fraction>(static_cast<InternalType>(left.GetValue() + right.GetValue()));
}

template< unsigned Integer, unsigned Fraction >
Ardutils::FixedPoint<Integer, Fraction> Ardutils::operator +(const Ardutils::FixedPoint<Integer, Fraction> & left, const typename Ardutils::FixedPoint<Integer, Fraction>::IntegerType & right)
{
	return left + (FixedPoint<Integer, Fraction>(right, 0));
}

template< unsigned Integer, unsigned Fraction >
Ardutils::FixedPoint<Integer, Fraction> Ardutils::operator -(const Ardutils::FixedPoint<Integer, Fraction> & left, const Ardutils::FixedPoint<Integer, Fraction> & right)
{
	using InternalType = FixedPoint<Integer, Fraction>::InternalType;
	return FixedPoint<Integer, Fraction>(static_cast<InternalType>(left.GetValue() - right.GetValue()));
}

template< unsigned Integer, unsigned Fraction >
Ardutils::FixedPoint<Integer, Fraction> Ardutils::operator -(const Ardutils::FixedPoint<Integer, Fraction> & left, const typename Ardutils::FixedPoint<Integer, Fraction>::IntegerType & right)
{
	return left - (FixedPoint<Integer, Fraction>(right, 0));
}

template< unsigned Integer, unsigned Fraction >
Ardutils::FixedPoint<Integer, Fraction> Ardutils::operator *(const Ardutils::FixedPoint<Integer, Fraction> & left, const Ardutils::FixedPoint<Integer, Fraction> & right)
{
	using InternalType = FixedPoint<Integer, Fraction>::InternalType;
	return FixedPoint<Integer, Fraction>(static_cast<InternalType>((left.GetValue() * right.GetValue()) >> Fraction));
}

template< unsigned Integer, unsigned Fraction >
Ardutils::FixedPoint<Integer, Fraction> Ardutils::operator *(const Ardutils::FixedPoint<Integer, Fraction> & left, const typename Ardutils::FixedPoint<Integer, Fraction>::IntegerType & right)
{
	return left * (FixedPoint<Integer, Fraction>(right, 0));
}

template< unsigned Integer, unsigned Fraction >
Ardutils::FixedPoint<Integer, Fraction> Ardutils::operator /(const Ardutils::FixedPoint<Integer, Fraction> & left, const Ardutils::FixedPoint<Integer, Fraction> & right)
{
	using InternalType = FixedPoint<Integer, Fraction>::InternalType;
	return FixedPoint<Integer, Fraction>(static_cast<InternalType>((left.GetValue() << Fraction) / right.GetValue()));
}

template< unsigned Integer, unsigned Fraction >
Ardutils::FixedPoint<Integer, Fraction> Ardutils::operator /(const Ardutils::FixedPoint<Integer, Fraction> & left, const typename Ardutils::FixedPoint<Integer, Fraction>::IntegerType & right)
{
	return left / (FixedPoint<Integer, Fraction>(right, 0));
}

template< unsigned Integer, unsigned Fraction >
Ardutils::FixedPoint<Integer * 2, Fraction * 2> Ardutils::Multiply(const Ardutils::FixedPoint<Integer, Fraction> & left, const Ardutils::FixedPoint<Integer, Fraction> & right)
{
	using ResultType = FixedPoint<Integer * 2, Fraction * 2>;
	using InternalType = ResultType::InternalType;
	return ResultType(static_cast<InternalType>(left.GetValue() * right.GetValue()));
}
