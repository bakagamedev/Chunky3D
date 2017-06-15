#pragma once

#include <stdint.h>

#include "../TypeTraits.h"
#include "../Debug.h"
#include "../NumericTypes.h"
#include "../BitsRequired.h"
#include "../Utility.h"

//
// Declaration
//

namespace Ardutils
{
	template< typename T, SizeT Capacity >
	class CircularDeque
	{
	public:
		static_assert(Capacity > 1, "Attempt to instantiate CircularDeque with Capacity less than 2");

		using ItemType = T;
		using IndexType = LeastUInt<BitsRequired<Capacity>::Value>;

	private:
		constexpr static const IndexType FirstIndex = 0;
		constexpr static const IndexType LastIndex = Capacity - 1;

	private:
		constexpr static const IndexType InitialBackIndex = Capacity / 2;
		constexpr static const IndexType InitialFrontIndex = Capacity / 2 - 1;

	private:
		ItemType items[Capacity];
		IndexType backIndex;
		IndexType frontIndex;
		IndexType count;

	public:
		CircularDeque(void);

		inline bool IsEmpty(void) const; // O(1)
		inline bool IsFull(void) const; // O(1)

		inline IndexType GetCount(void) const; // O(1)
		constexpr inline IndexType GetCapacity(void) const; // O(1)

		bool Append(const ItemType & item); // O(1)
		bool Append(ItemType && item); // O(1)
		bool Prepend(const ItemType & item); // O(1)
		bool Prepend(ItemType && item); // O(1)
		ItemType && Unappend(void); // O(1)
		ItemType && Unprepend(void); // O(1)
		const ItemType & PeekBack(void) const; // O(1)
		const ItemType & PeekFront(void) const; // O(1)

		void Clear(void); // O(n)	
		bool Contains(const ItemType & item) const; // O(n)
	};
}


//
// Definition
//

namespace Ardutils
{
	template< typename ItemType, SizeT Capacity >
	CircularDeque< ItemType, Capacity >::CircularDeque(void)
		: items(), backIndex(InitialBackIndex), frontIndex(InitialFrontIndex), count(0)
	{}

	template< typename ItemType, SizeT Capacity >
	inline bool CircularDeque<ItemType, Capacity>::IsEmpty(void) const // O(1)
	{
		return (this->count == 0);
	}

	template< typename ItemType, SizeT Capacity >
	inline bool CircularDeque<ItemType, Capacity>::IsFull(void) const // O(1)
	{
		return (this->IsFull());
	}

	template< typename ItemType, SizeT Capacity >
	inline typename CircularDeque< ItemType, Capacity >::IndexType CircularDeque< ItemType, Capacity >::GetCount(void) const
	{
		return this->count;
	}

	template< typename ItemType, SizeT Capacity >
	constexpr inline typename CircularDeque< ItemType, Capacity >::IndexType CircularDeque< ItemType, Capacity >::GetCapacity(void) const
	{
		return static_cast<IndexType>(Capacity);
	}

	template< typename ItemType, SizeT Capacity >
	bool CircularDeque< ItemType, Capacity >::Append(const ItemType & item)
	{
		if (this->IsFull())
			return false;

		this->items[this->backIndex] = item;
		this->backIndex = (this->backIndex == LastIndex) ? FirstIndex : this->backIndex + 1;
		++this->count;

		return true;
	}

	template< typename ItemType, SizeT Capacity >
	bool CircularDeque< ItemType, Capacity >::Append(ItemType && item)
	{
		if (this->IsFull())
			return false;

		this->items[this->backIndex] = Move(item);
		this->backIndex = (this->backIndex == LastIndex) ? FirstIndex : this->backIndex + 1;
		++this->count;

		return true;
	}

	template< typename ItemType, SizeT Capacity >
	bool CircularDeque< ItemType, Capacity >::Prepend(const ItemType & item)
	{
		if (this->IsFull())
			return false;

		this->items[this->frontIndex] = item;
		this->frontIndex = (this->frontIndex == FirstIndex) ? LastIndex : this->frontIndex - 1;
		++this->count;

		return true;
	}

	template< typename ItemType, SizeT Capacity >
	bool CircularDeque< ItemType, Capacity >::Prepend(ItemType && item)
	{
		if (this->IsFull())
			return false;

		this->items[this->frontIndex] = Move(item);
		this->frontIndex = (this->frontIndex == FirstIndex) ? LastIndex : this->frontIndex - 1;
		++this->count;

		return true;
	}

	template< typename ItemType, SizeT Capacity >
	ItemType && CircularDeque< ItemType, Capacity >::Unappend(void)
	{
		DEBUG_ASSERT(this->count > 0);

		this->backIndex = (this->backIndex == FirstIndex) ? LastIndex : this->backIndex - 1;
		--this->count;

		return Move(this->items[this->backIndex]);
	}

	template< typename ItemType, SizeT Capacity >
	ItemType && CircularDeque< ItemType, Capacity >::Unprepend(void)
	{
		DEBUG_ASSERT(this->count > 0);

		this->frontIndex = (this->frontIndex == LastIndex) ? FirstIndex : this->frontIndex + 1;
		--this->count;

		return Move(this->items[this->frontIndex]);
	}

	template< typename ItemType, SizeT Capacity >
	const ItemType & CircularDeque< ItemType, Capacity >::PeekBack(void) const
	{
		DEBUG_ASSERT(this->count > 0);

		return this->items[this->backIndex];
	}

	template< typename ItemType, SizeT Capacity >
	const ItemType & CircularDeque< ItemType, Capacity >::PeekFront(void) const
	{
		DEBUG_ASSERT(this->count > 0);

		return this->items[this->frontIndex];
	}

	template< typename ItemType, SizeT Capacity >
	void CircularDeque< ItemType, Capacity >::Clear(void)
	{
		if (this->count > 0)
		{
			if (this->frontIndex < this->backIndex)
			{
				for (IndexType i = this->frontIndex; i < this->backIndex; ++i)
					(&this->items[i])->~ItemType();
			}
			else if (this->frontIndex >= this->backIndex)
			{
				for (IndexType i = FirstIndex; i < this->backIndex; ++i)
					(&this->items[i])->~ItemType();
				for (IndexType i = this->frontIndex; i < Capacity; ++i)
					(&this->items[i])->~ItemType();
			}
		}

		this->count = 0;
		this->backIndex = InitialBackIndex;
		this->frontIndex = InitialFrontIndex;
	}

	template< typename ItemType, SizeT Capacity >
	bool CircularDeque< ItemType, Capacity >::Contains(const ItemType & item) const
	{
		if (this->count == 0)
		{
			return false;
		}
		else if (this->frontIndex < this->backIndex)
		{
			for (IndexType i = this->frontIndex; i < this->backIndex; ++i)
				if (this->items[i] == item)
					return true;
			return false;
		}
		else if (this->frontIndex >= this->backIndex)
		{
			for (IndexType i = this->frontIndex; i < Capacity; ++i)
				if (this->items[i] == item)
					return true;
			for (IndexType i = FirstIndex; i < this->backIndex; ++i)
				if (this->items[i] == item)
					return true;
			return false;
		}
	}
}