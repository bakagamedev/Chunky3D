#pragma once

#include "../Utils.h"

#include "Point2.h"
#include "Vector2.h"

//
// Declaration
//

namespace Ardutils
{
	template< typename TPosition, typename TSize = TPosition >
	class Circle
	{
	public:
		using PositionType = Point2<TPosition>;
		using SizeType = TSize;
		using SquaredRadiusType = decltype(SizeType(0) * SizeType(0));

	public:
		TPosition X;
		TPosition Y;
		PositionType Position;
		TSize Radius;

	public:
		Circle(void);
		Circle(const PositionType & position, const TSize & radius);
		Circle(const TPosition & x, const TPosition & y, const TSize & radius);

		template< typename TOtherPosition, typename TOtherSize >
		Circle(const Point2<TOtherPosition> & position, const TOtherSize & radius);

		template< typename TX, typename TY, typename TRadius >
		Circle(const TX & x, const TY & y, const TRadius & radius);

		TPosition & GetX(void);
		const TPosition & GetX(void) const;
		TPosition & GetY(void);
		const TPosition & GetY(void) const;

		TSize GetDiameter(void) const;
		SquaredRadiusType GetRadiusSquared(void) const;

		TPosition GetLeft(void) const;
		TPosition GetRight(void) const;
		TPosition GetTop(void) const;
		TPosition GetBottom(void) const;

		bool IsEmpty(void) const;

		void Offset(const Vector2<TPosition> & vector);
		void Offset(const TPosition & x, const TPosition & y);

		void ScaleByUnit(const TPosition & r);

		template< typename TValue >
		bool Contains(const Point2<TValue> & point) const;

		template< typename TValue >
		bool Contains(const TValue & x, const TValue & y) const;

		bool Contains(const Circle<TPosition, TSize> & other) const;

		template< typename TOtherPosition, typename TOtherSize >
		operator Circle<TOtherPosition, TOtherSize>(void) const;
	};

	template< typename TPosition, typename TSize = TPosition >
	bool Intersects(const Circle<TPosition, TSize> & left, const Circle<TPosition, TSize> & right);

	template< typename TPosition, typename TSize = TPosition >
	bool operator ==(const Circle<TPosition, TSize> & left, const Circle<TPosition, TSize> & right);

	template< typename TPosition, typename TSize = TPosition >
	bool operator !=(const Circle<TPosition, TSize> & left, const Circle<TPosition, TSize> & right);
}


//
// Definition
//

namespace Ardutils
{
	template< typename TPosition, typename TSize >
	Circle< TPosition, TSize >::Circle(void) :
		Position(), Radius()
	{
	}
	
	template< typename TPosition, typename TSize >
	Circle< TPosition, TSize >::Circle(const PositionType & position, const TSize & radius) :
		Position(position), Radius(radius)
	{
	}

	template< typename TPosition, typename TSize >
	Circle< TPosition, TSize >::Circle(const TPosition & x, const TPosition & y, const TSize & radius) :
		Position(x, y), Radius(radius)
	{
	}

	template< typename TPosition, typename TSize >
	template< typename TOtherPosition, typename TOtherSize >
	Circle< TPosition, TSize >::Circle(const Point2<TOtherPosition> & position, const TOtherSize & radius) :
		Position(position), Radius(radius)
	{
	}

	template< typename TPosition, typename TSize >
	template< typename TX, typename TY, typename TRadius >
	Circle< TPosition, TSize >::Circle(const TX & x, const TY & y, const TRadius & radius) :
		Position(x, y), Radius(radius)
	{
	}

	template< typename TPosition, typename TSize >
	TPosition & Circle< TPosition, TSize >::GetX(void)
	{
		return this->Position.X;
	}

	template< typename TPosition, typename TSize >
	const TPosition & Circle< TPosition, TSize >::GetX(void) const
	{
		return this->Position.X;
	}

	template< typename TPosition, typename TSize >
	TPosition & Circle< TPosition, TSize >::GetY(void)
	{
		return this->Position.Y;
	}

	template< typename TPosition, typename TSize >
	const TPosition & Circle< TPosition, TSize >::GetY(void) const
	{
		return this->Position.Y;
	}

	template< typename TPosition, typename TSize >
	TSize Circle< TPosition, TSize >::GetDiameter(void) const
	{
		return this->Radius + this->Radius;
	}

	template< typename TPosition, typename TSize >
	typename Circle< TPosition, TSize >::SquaredRadiusType Circle< TPosition, TSize >::GetRadiusSquared(void) const
	{
		return this->Radius * this->Radius;
	}

	template< typename TPosition, typename TSize >
	TPosition Circle< TPosition, TSize >::GetLeft(void) const
	{
		return static_cast<TPosition>(this->Position.X - this->Radius);
	}

	template< typename TPosition, typename TSize >
	TPosition Circle< TPosition, TSize >::GetRight(void) const
	{
		return static_cast<TPosition>(this->Position.X + this->Radius);
	}

	template< typename TPosition, typename TSize >
	TPosition Circle< TPosition, TSize >::GetTop(void) const
	{
		return static_cast<TPosition>(this->Position.Y - this->Radius);
	}

	template< typename TPosition, typename TSize >
	TPosition Circle< TPosition, TSize >::GetBottom(void) const
	{
		return static_cast<TPosition>(this->Position.Y + this->Radius);
	}

	template< typename TPosition, typename TSize >
	bool Circle< TPosition, TSize >::IsEmpty(void) const
	{
		return (this->Position.X == 0)
			&& (this->Position.Y == 0)
			&& (this->Radius == 0);
	}

	template< typename TPosition, typename TSize >
	void Circle< TPosition, TSize >::Offset(const Vector2<TPosition> & vector)
	{
		this->Position += vector;
	}

	template< typename TPosition, typename TSize >
	void Circle< TPosition, TSize >::Offset(const TPosition & x, const TPosition & y)
	{
		this->Position.X += x;
		this->Position.Y += y;
	}

	template< typename TPosition, typename TSize >
	void Circle< TPosition, TSize >::ScaleByUnit(const TPosition & r)
	{
		this->Radius += (r + r);
	}

	template< typename TPosition, typename TSize >
	template< typename TValue >
	bool Circle< TPosition, TSize >::Contains(const Point2<TValue> & point) const
	{
		return DistanceSquared(point, this->Position) <= this->GetRadiusSquared();
	}

	template< typename TPosition, typename TSize >
	template< typename TValue >
	bool Circle< TPosition, TSize >::Contains(const TValue & x, const TValue & y) const
	{
		return DistanceSquared(Point2<TValue>(x, y), this->Position) <= this->GetRadiusSquared();
	}

	template< typename TPosition, typename TSize >
	bool Circle< TPosition, TSize >::Contains(const Circle<TPosition, TSize> & other) const
	{
		return (Distance(this->Position, other.Position) + other.Radius) < this->Radius;
	}

	template< typename TPosition, typename TSize >
	template< typename TOtherPosition, typename TOtherSize >
	Circle< TPosition, TSize >::operator Circle< TOtherPosition, TOtherSize >(void) const
	{
		return Circle< TOtherPosition, TOtherSize >
			(
				static_cast<TOtherPosition>(this->Position.X),
				static_cast<TOtherPosition>(this->Position.Y),
				static_cast<TOtherSize>(this->Radius)
			);
	}



	template< typename TPosition, typename TSize >
	bool Intersects(const Circle<TPosition, TSize> & left, const Circle<TPosition, TSize> & right)
	{
		const auto sum = left.Radius + right.Radius;
		return DistanceSquared(left.Position, right.Position) < (sum * sum);
	}

	template< typename TPosition, typename TSize >
	bool operator ==(const Circle<TPosition, TSize> & left, const Circle<TPosition, TSize> & right)
	{
		return (left.Position.X == right.Position.X)
			&& (left.Position.Y == right.Position.Y)
			&& (left.Radius == right.Radius);
	}

	template< typename TPosition, typename TSize >
	bool operator !=(const Circle<TPosition, TSize> & left, const Circle<TPosition, TSize> & right)
	{
		return (left.Position.X != right.Position.X)
			|| (left.Position.Y != right.Position.Y)
			|| (left.Radius != right.Radius);
	}
}
