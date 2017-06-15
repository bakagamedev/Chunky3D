#pragma once

// Required for use of sqrt
#include <math.h>

#include "../TypeTraits.h"
#include "Vector2.h"

//
// Declaration
//

namespace Ardutils
{
	template< typename TValue >
	class Point2
	{
	public:
		using ValueType = TValue;
		using SquareDistanceType = decltype((ValueType() * ValueType()) + (ValueType() * ValueType()));

	private:
		using SqrtInputType = typename
			Conditional<
				IsIntegral<SquareDistanceType>::Value | IsFloatingPoint<SquareDistanceType>::Value,
				SquareDistanceType,
				float
			>::Type;

	public:
		using DistanceType = decltype(sqrt(static_cast<SqrtInputType>(SquareDistanceType())));

	public:
		TValue X;
		TValue Y;

		constexpr inline Point2(void);
		constexpr inline Point2(const TValue & x, const TValue & y);

		template< typename TOther >
		constexpr inline Point2(const TOther & x, const TOther & y);

		template< typename TOther >
		constexpr inline operator Point2<TOther>(void) const;

		Point2 & operator +=(const Vector2<TValue> & vector);
		Point2 & operator -=(const Vector2<TValue> & vector);
	};

	template< typename TValue >
	typename Point2<TValue>::DistanceType Distance(const Point2<TValue> & left, const Point2<TValue> & right);

	template< typename TValue >
	typename Point2<TValue>::SquareDistanceType DistanceSquared(const Point2<TValue> & left, const Point2<TValue> & right);

	template< typename TValue >
	bool operator ==(const Point2<TValue> & left, const Point2<TValue> & right);

	template< typename TValue >
	bool operator !=(const Point2<TValue> & left, const Point2<TValue> & right);

	template< typename TValue >
	Point2<TValue> operator +(Point2<TValue> left, const Vector2<TValue> & right);

	template< typename TValue >
	Point2<TValue> operator -(Point2<TValue> left, const Vector2<TValue> & right);
}


//
// Definition
//

namespace Ardutils
{
	template< typename TValue >
	constexpr inline Point2<TValue>::Point2() : X(), Y()
	{
	}

	template< typename TValue >
	constexpr inline Point2<TValue>::Point2(const TValue & x, const TValue & y) : X(x), Y(y)
	{
	}

	template< typename TValue >
	template< typename TOther >
	constexpr inline Point2<TValue>::Point2(const TOther & x, const TOther & y) : X(x), Y(y)
	{
	}

	template< typename TValue >
	template< typename TOther >
	constexpr inline Point2<TValue>::operator Point2<TOther>(void) const
	{
		return Point2<TOther>(static_cast<TOther>(this->X), static_cast<TOther>(this->Y));
	}

	template< typename TValue >
	Point2<TValue> & Point2<TValue>::operator+=(const Vector2<TValue> & vector)
	{
		this->X += vector.X;
		this->Y += vector.Y;
		return *this;
	}

	template< typename TValue >
	Point2<TValue> & Point2<TValue>::operator-=(const Vector2<TValue> & vector)
	{
		this->X -= vector.X;
		this->Y -= vector.Y;
		return *this;
	}



	template< typename TValue >
	typename Point2<TValue>::DistanceType Distance(const Point2<TValue> & left, const Point2<TValue> & right)
	{
		return sqrt(static_cast<typename Point2<TValue>::SqrtInputType>(DistanceSquared(left, right)));
	}

	template< typename TValue >
	typename Point2<TValue>::SquareDistanceType DistanceSquared(const Point2<TValue> & left, const Point2<TValue> & right)
	{
		TValue x = left.X - right.X;
		TValue y = left.Y - right.Y;
		return (x * x) + (y * y);
	}

	template< typename TValue >
	bool operator ==(const Point2<TValue> & left, const Point2<TValue> & right)
	{
		return (left.X == right.X) && (left.Y == right.Y);
	}

	template< typename TValue >
	bool operator !=(const Point2<TValue> & left, const Point2<TValue> & right)
	{
		return (left.X != right.X) || (left.Y != right.Y);
	}

	template< typename TValue >
	Point2<TValue> operator +(Point2<TValue> left, const Vector2<TValue> & right)
	{
		return left += right;
	}

	template< typename TValue >
	Point2<TValue> operator -(Point2<TValue> left, const Vector2<TValue> & right)
	{
		return left -= right;
	}
}
