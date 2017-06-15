#pragma once

// Required for sqrt
#include <math.h>

#include "../TypeTraits.h"

//
// Declaration
//

namespace Ardutils
{
	template< typename TValue >
	class Vector2
	{
	public:
		using ValueType = TValue;
		using SquareMagnitudeType = decltype((ValueType() * ValueType()) + (ValueType() * ValueType()));

	private:
		using SqrtInputType = typename
			Conditional<
			IsIntegral<SquareMagnitudeType>::Value | IsFloatingPoint<SquareMagnitudeType>::Value,
			SquareMagnitudeType,
			float
			>::Type;

	public:
		using MagnitudeType = decltype(sqrt(static_cast<SqrtInputType>(SquareMagnitudeType())));

	public:
		TValue X;
		TValue Y;

		constexpr inline Vector2(void);
		constexpr inline Vector2(const TValue & x, const TValue & y);

		template< typename TOther >
		constexpr inline Vector2(const TOther & x, const TOther & y);

		MagnitudeType Magnitude(void) const;
		SquareMagnitudeType MagnitudeSquared(void) const;

		template< typename TOther >
		constexpr inline operator Vector2<TOther>(void) const;

		Vector2 & operator +=(const Vector2 & other);
		Vector2 & operator -=(const Vector2 & other);
		Vector2 & operator *=(const TValue & value);
	};

	template< typename TValue >
	bool operator ==(const Ardutils::Vector2<TValue> & left, const Ardutils::Vector2<TValue> & right);

	template< typename TValue >
	bool operator !=(const Ardutils::Vector2<TValue> & left, const Ardutils::Vector2<TValue> & right);

	template< typename TValue >
	Ardutils::Vector2<TValue> operator +(Ardutils::Vector2<TValue> left, const Ardutils::Vector2<TValue> & right);

	template< typename TValue >
	Ardutils::Vector2<TValue> operator -(Ardutils::Vector2<TValue> left, const Ardutils::Vector2<TValue> & right);

	template< typename TValue >
	Ardutils::Vector2<TValue> operator *(Ardutils::Vector2<TValue> left, const TValue right);

	template< typename TValue >
	Ardutils::Vector2<TValue> operator *(const TValue left, Ardutils::Vector2<TValue> right);
}


//
// Definition
//

namespace Ardutils
{
	template< typename TValue >
	constexpr inline Vector2<TValue>::Vector2(void) : X(), Y()
	{
	}

	template< typename TValue >
	constexpr inline Vector2<TValue>::Vector2(const TValue & x, const TValue & y) : X(x), Y(y)
	{
	}

	template< typename TValue >
	template< typename TOther >
	constexpr inline Vector2<TValue>::Vector2(const TOther & x, const TOther & y) : X(x), Y(y)
	{
	}

	template< typename TValue >
	typename Vector2<TValue>::MagnitudeType Vector2<TValue>::Magnitude(void) const
	{
		return sqrt(static_cast<SqrtInputType>(this->MagnitudeSquared()));
	}

	template< typename TValue >
	typename Vector2<TValue>::SquareMagnitudeType Vector2<TValue>::MagnitudeSquared(void) const
	{
		return (this->X * this->X) + (this->Y + this->Y);
	}

	template< typename TValue >
	template< typename TOther >
	constexpr inline Vector2<TValue>::operator Vector2<TOther>(void) const
	{
		return Vector2<TOther>(static_cast<TOther>(this->X), static_cast<TOther>(this->Y));
	}

	template< typename TValue >
	Vector2<TValue> & Vector2<TValue>::operator+=(const Vector2<TValue> & other)
	{
		this->X += other.X;
		this->Y += other.Y;
		return *this;
	}

	template< typename TValue >
	Vector2<TValue> & Vector2<TValue>::operator-=(const Vector2<TValue> & other)
	{
		this->X -= other.X;
		this->Y -= other.Y;
		return *this;
	}

	template< typename TValue >
	Vector2<TValue> & Vector2<TValue>::operator*=(const TValue & value)
	{
		this->X *= value;
		this->Y *= value;
		return *this;
	}



	template< typename TValue >
	bool operator==(const Vector2<TValue> & left, const Vector2<TValue> & right)
	{
		return (left.X == right.X) && (left.Y == right.Y);
	}

	template< typename TValue >
	bool operator!=(const Vector2<TValue> & left, const Vector2<TValue> & right)
	{
		return (left.X != right.X) || (left.Y != right.Y);
	}

	template< typename TValue >
	Vector2<TValue> operator+(Vector2<TValue> left, const Vector2<TValue> &right)
	{
		return left += right;
	}

	template< typename TValue >
	Vector2<TValue> operator-(Vector2<TValue> left, const Vector2<TValue> &right)
	{
		return left -= right;
	}

	template< typename TValue >
	Vector2<TValue> operator*(Vector2<TValue> left, const TValue right)
	{
		return left *= right;
	}

	template< typename TValue >
	Vector2<TValue> operator *(const TValue left, Vector2<TValue> right)
	{
		return right *= left;
	}
}
