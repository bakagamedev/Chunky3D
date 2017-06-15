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
	class Rectangle
	{
	public:
		using PositionType = Point2<TPosition>;
		using SizeType = Vector2<TSize>;

	public:
		Point2<TPosition> Position;
		Vector2<TSize> Size;

	public:
		Rectangle(void);
		Rectangle(const PositionType & position, const SizeType & size);
		Rectangle(const TPosition & x, const TPosition & y, const TSize & width, const TSize & height);
		
		template< typename TOtherPosition, typename TOtherSize >
		Rectangle(const Point2<TOtherPosition> & position, const Vector2<TOtherSize> & size);

		template< typename TOtherPosition, typename TOtherSize >
		Rectangle(const TOtherPosition & x, const TOtherPosition & y, const TOtherSize & width, const TOtherSize & height);

		TPosition & GetX(void);
		const TPosition & GetX(void) const;
		TPosition & GetY(void);
		const TPosition & GetY(void) const;
		TPosition & GetWidth(void);
		const TPosition & GetWidth(void) const;
		TPosition & GetHeight(void);
		const TPosition & GetHeight(void) const;

		TPosition GetLeft(void) const;
		TPosition GetRight(void) const;
		TPosition GetTop(void) const;
		TPosition GetBottom(void) const;

		Point2<TPosition> GetCentre(void) const;

		bool IsEmpty(void) const;
		TSize GetArea(void) const;
		TSize GetPerimeter(void) const;

		void Offset(const Vector2<TPosition> & vector);
		void Offset(const TPosition & x, const TPosition & y);

		void ScaleByUnit(const Vector2<TPosition> & vector);
		void ScaleByUnit(const TPosition & x, const TPosition & y);

		template< typename TValue >
		bool Contains(const Point2<TValue> & point) const;

		template< typename TValue >
		bool Contains(const TValue & x, const TValue & y) const;

		bool Contains(const Rectangle<TPosition, TSize> & other) const;

		template< typename TOtherPosition, typename TOtherSize >
		operator Rectangle<TOtherPosition, TOtherSize>(void) const;
	};

	template< typename TPosition, typename TSize = TPosition >
	bool Intersects(const Rectangle<TPosition, TSize> & left, const Rectangle<TPosition, TSize> & right);

	template< typename TPosition, typename TSize = TPosition >
	Rectangle<TPosition, TSize> Union(const Rectangle<TPosition, TSize> & left, const Rectangle<TPosition, TSize> & right);
	
	template< typename TPosition, typename TSize = TPosition >
	Rectangle<TPosition, TSize> Intersection(const Rectangle<TPosition, TSize> & left, const Rectangle<TPosition, TSize> & right);

	template< typename TPosition, typename TSize = TPosition >
	bool operator ==(const Rectangle<TPosition, TSize> & left, const Rectangle<TPosition, TSize> & right);

	template< typename TPosition, typename TSize = TPosition >
	bool operator !=(const Rectangle<TPosition, TSize> & left, const Rectangle<TPosition, TSize> & right);
}


//
// Definition
//

namespace Ardutils
{
	template< typename TPosition, typename TSize >
	Rectangle< TPosition, TSize >::Rectangle(void) = default;

	template< typename TPosition, typename TSize >
	Rectangle< TPosition, TSize >::Rectangle(const PositionType & position, const SizeType & size) :
		Position(position), Size(size)
	{
	}
	
	template< typename TPosition, typename TSize >
	Rectangle< TPosition, TSize >::Rectangle(const TPosition & x, const TPosition & y, const TSize & width, const TSize & height) :
		Position(x, y), Size(x, y)
	{
	}

	template< typename TPosition, typename TSize >
	template< typename TOtherPosition, typename TOtherSize >
	Rectangle< TPosition, TSize >::Rectangle(const Point2<TOtherPosition> & position, const Vector2<TOtherSize> & size) :
		Position(position), Size(size)
	{
	}

	template< typename TPosition, typename TSize >
	template< typename TOtherPosition, typename TOtherSize >
	Rectangle< TPosition, TSize >::Rectangle(const TOtherPosition & x, const TOtherPosition & y, const TOtherSize & width, const TOtherSize & height) :
		Position(x, y), Size(x, y)
	{
	}

	template< typename TPosition, typename TSize >
	TPosition & Rectangle< TPosition, TSize >::GetX(void)
	{
		return this->Position.X;
	}

	template< typename TPosition, typename TSize >
	const TPosition & Rectangle< TPosition, TSize >::GetX(void) const
	{
		return this->Position.X;
	}

	template< typename TPosition, typename TSize >
	TPosition & Rectangle< TPosition, TSize >::GetY(void)
	{
		return this->Position.Y;
	}

	template< typename TPosition, typename TSize >
	const TPosition & Rectangle< TPosition, TSize >::GetY(void) const
	{
		return this->Position.Y;
	}

	template< typename TPosition, typename TSize >
	TPosition & Rectangle< TPosition, TSize >::GetWidth(void)
	{
		return this->Size.X;
	}

	template< typename TPosition, typename TSize >
	const TPosition & Rectangle< TPosition, TSize >::GetWidth(void) const
	{
		return this->Size.X;
	}

	template< typename TPosition, typename TSize >
	TPosition & Rectangle< TPosition, TSize >::GetHeight(void)
	{
		return this->Size.Y;
	}

	template< typename TPosition, typename TSize >
	const TPosition & Rectangle< TPosition, TSize >::GetHeight(void) const
	{
		return this->Size.Y;
	}

	template< typename TPosition, typename TSize >
	TPosition Rectangle< TPosition, TSize >::GetLeft(void) const
	{
		return this->Position.X;
	}

	template< typename TPosition, typename TSize >
	TPosition Rectangle< TPosition, TSize >::GetRight(void) const
	{
		return static_cast<TPosition>(this->Position.X + this->Size.X);
	}

	template< typename TPosition, typename TSize >
	TPosition Rectangle< TPosition, TSize >::GetTop(void) const
	{
		return this->Position.Y;
	}

	template< typename TPosition, typename TSize >
	TPosition Rectangle< TPosition, TSize >::GetBottom(void) const
	{
		return static_cast<TPosition>(this->Position.Y + this->Size.Y);
	}

	template< typename TPosition, typename TSize >
	Point2<TPosition> Rectangle< TPosition, TSize >::GetCentre(void) const
	{
		return PositionType(this->Position.X + (this->Size.X / 2), this->Position.Y + (this->Size.Y / 2));
	}

	template< typename TPosition, typename TSize >
	bool Rectangle< TPosition, TSize >::IsEmpty(void) const
	{
		return (this->X == 0)
			&& (this->Y == 0)
			&& (this->Width == 0)
			&& (this->Height == 0);
	}

	template< typename TPosition, typename TSize >
	TSize Rectangle< TPosition, TSize >::GetArea(void) const
	{
		return this->Size.X * this->Size.Y;
	}

	template< typename TPosition, typename TSize >
	TSize Rectangle< TPosition, TSize >::GetPerimeter(void) const
	{
		return (this->Size.X * this->Size.Y) * 2;
	}

	template< typename TPosition, typename TSize >
	void Rectangle< TPosition, TSize >::Offset(const Vector2<TPosition> & vector)
	{
		this->Position += vector;
	}

	template< typename TPosition, typename TSize >
	void Rectangle< TPosition, TSize >::Offset(const TPosition & x, const TPosition & y)
	{
		this->Position.X += x;
		this->Position.Y += y;
	}

	template< typename TPosition, typename TSize >
	void Rectangle< TPosition, TSize >::ScaleByUnit(const Vector2<TPosition> & vector)
	{
		this->Position.X -= vector.X;
		this->Position.Y -= vector.Y;
		this->Size.X += vector.X * 2;
		this->Size.Y += vector.Y * 2;
	}

	template< typename TPosition, typename TSize >
	void Rectangle< TPosition, TSize >::ScaleByUnit(const TPosition & x, const TPosition & y)
	{
		this->Position.X -= x;
		this->Position.Y -= y;
		this->Size.X += x * 2;
		this->Size.Y += y * 2;
	}

	template< typename TPosition, typename TSize >
	template< typename TValue >
	bool Rectangle< TPosition, TSize >::Contains(const Point2<TValue> & point) const
	{
		return InRange(point.X, this->GetLeft(), this->GetRight())
			&& InRange(point.Y, this->GetTop(), this->GetBottom());
	}

	template< typename TPosition, typename TSize >
	template< typename TValue >
	bool Rectangle< TPosition, TSize >::Contains(const TValue & x, const TValue & y) const
	{
		return InRange(x, this->GetLeft(), this->GetRight())
			&& InRange(y, this->GetTop(), this->GetBottom());
	}

	template< typename TPosition, typename TSize >
	bool Rectangle< TPosition, TSize >::Contains(const Rectangle<TPosition, TSize> & other) const
	{
		return (other.GetTop() >= this->GetTop())
			&& (other.GetLeft() >= this->GetLeft())
			&& (other.GetRight() <= this->GetRight())
			&& (other.GetBottom() <= this->GetBottom());
	}

	template< typename TPosition, typename TSize >
	template< typename TOtherPosition, typename TOtherSize >
	Rectangle< TPosition, TSize >::operator Rectangle< TOtherPosition, TOtherSize >(void) const
	{
		return Rectangle< TOtherPosition, TOtherSize >
			(
				static_cast<TOtherPosition>(this.Position.X),
				static_cast<TOtherPosition>(this.Position.Y),
				static_cast<TOtherSize>(this.Size.X),
				static_cast<TOtherSize>(this.Size.Y)
			);
	}



	template< typename TPosition, typename TSize >
	bool Intersects(const Rectangle<TPosition, TSize> & left, const Rectangle<TPosition, TSize> & right)
	{
		return !
			(
			(left.GetTop() > right.GetBottom()) ||
			(left.GetLeft() > right.GetRight()) ||
			(left.GetRight() < right.GetLeft()) ||
			(left.GetBottom() < right.GetTop())
			);
	}

	template< typename TPosition, typename TSize >
	Rectangle<TPosition, TSize> Union(const Rectangle<TPosition, TSize> & left, const Rectangle<TPosition, TSize> & right)
	{
		const auto x = Min(left.GetLeft(), right.GetLeft());
		const auto y = Min(left.GetTop(), right.GetTop());
		const auto w = Max(left.GetRight(), right.GetRight()) - x;
		const auto h = Max(left.GetBottom(), right.GetBottom()) - y;
		return Rectangle<TPosition, TSize>(x, y, w, h);
	}

	template< typename TPosition, typename TSize >
	Rectangle<TPosition, TSize> Intersection(const Rectangle<TPosition, TSize> & left, const Rectangle<TPosition, TSize> & right)
	{
		const auto x = Max(left.GetLeft(), right.GetLeft());
		const auto y = Max(left.GetTop(), right.GetTop());
		const auto w = Min(left.GetRight(), right.GetRight()) - x;
		const auto h = Min(left.GetBottom(), right.GetBottom()) - y;
		return Rectangle<TPosition, TSize>(x, y, w, h);
	}

	template< typename TPosition, typename TSize >
	bool operator ==(const Rectangle<TPosition, TSize> & left, const Rectangle<TPosition, TSize> & right)
	{
		return (left.X == right.X)
			&& (left.Y == right.Y)
			&& (left.Width == right.Width)
			&& (left.Height == right.Height);
	}

	template< typename TPosition, typename TSize >
	bool operator !=(const Rectangle<TPosition, TSize> & left, const Rectangle<TPosition, TSize> & right)
	{
		return (left.X != right.X)
			|| (left.Y != right.Y)
			|| (left.Width != right.Width)
			|| (left.Height != right.Height);
	}
}
