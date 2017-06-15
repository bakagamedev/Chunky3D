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
	class CircularQueue
	{
	public:
		static_assert(Capacity > 0, "Attempt to instantiate CircularQueue with Capacity less than 1");

		using ItemType = T;
		using IndexType = LeastUInt<BitsRequired<Capacity>::Value>;

	private:
		constexpr static const IndexType FirstIndex = 0;
		constexpr static const IndexType LastIndex = Capacity - 1;

	private:
		ItemType items[Capacity];
		IndexType readIndex;
		IndexType writeIndex;
		IndexType count;

	public:
		CircularQueue(void);

		inline bool IsEmpty(void) const; // O(1)
		inline bool IsFull(void) const; // O(1)

		inline IndexType GetCount(void) const; // O(1)
		constexpr inline IndexType GetCapacity(void) const; // O(1)

		const ItemType & Peek(void) const; // O(1)
		bool Enqueue(const ItemType & item); // O(1)
		bool Enqueue(ItemType && item); // O(1)
		ItemType && Dequeue(void); // O(1)
		
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
	CircularQueue< ItemType, Capacity >::CircularQueue(void)
		: items(), readIndex(0), writeIndex(0), count(0)
	{}

	template< typename ItemType, SizeT Capacity >
	inline bool CircularQueue<ItemType, Capacity>::IsEmpty(void) const // O(1)
	{
		return (this->count == 0);
	}

	template< typename ItemType, SizeT Capacity >
	inline bool CircularQueue<ItemType, Capacity>::IsFull(void) const // O(1)
	{
		return (this->IsFull());
	}

	template< typename ItemType, SizeT Capacity >
	inline typename CircularQueue< ItemType, Capacity >::IndexType CircularQueue< ItemType, Capacity >::GetCount(void) const
	{
		return this->count;
	}

	template< typename ItemType, SizeT Capacity >
	constexpr inline typename CircularQueue< ItemType, Capacity >::IndexType CircularQueue< ItemType, Capacity >::GetCapacity(void) const
	{
		return static_cast<IndexType>(Capacity);
	}

	template< typename ItemType, SizeT Capacity >
	const ItemType & CircularQueue< ItemType, Capacity >::Peek(void) const
	{
		DEBUG_ASSERT(this->count > 0);

		return this->items[this->readIndex];
	}

	template< typename ItemType, SizeT Capacity >
	bool CircularQueue< ItemType, Capacity >::Enqueue(const ItemType & item)
	{
		if (this->IsFull())
			return false;

		this->items[this->writeIndex] = item;
		this->writeIndex = (this->writeIndex == LastIndex) ? FirstIndex : this->writeIndex + 1;
		++this->count;

		return true;
	}

	template< typename ItemType, SizeT Capacity >
	bool CircularQueue< ItemType, Capacity >::Enqueue(ItemType && item)
	{
		if (this->IsFull())
			return false;

		this->items[this->writeIndex] = Move(item);
		this->writeIndex = (this->writeIndex == LastIndex) ? FirstIndex : this->writeIndex + 1;
		++this->count;

		return true;
	}

	template< typename ItemType, SizeT Capacity >
	ItemType && CircularQueue< ItemType, Capacity >::Dequeue(void)
	{
		DEBUG_ASSERT(this->count > 0);

		auto resultIndex = readIndex;
		this->readIndex = (this->readIndex == LastIndex) ? FirstIndex : this->readIndex + 1;
		--this->count;

		return Move(this->items[resultIndex]);
	}

	template< typename ItemType, SizeT Capacity >
	void CircularQueue< ItemType, Capacity >::Clear(void)
	{
		if (this->count > 0)
		{
			if (this->readIndex < this->writeIndex)
			{
				for (IndexType i = this->readIndex; i < this->writeIndex; ++i)
					(&this->items[i])->~ItemType();
			}
			else if (this->readIndex > this->writeIndex)
			{
				for (IndexType i = FirstIndex; i < this->writeIndex; ++i)
					(&this->items[i])->~ItemType();
				for (IndexType i = this->readIndex; i < Capacity; ++i)
					(&this->items[i])->~ItemType();
			}
		}

		this->count = 0;
		this->readIndex = FirstIndex;
		this->writeIndex = FirstIndex;
	}

	template< typename ItemType, SizeT Capacity >
	bool CircularQueue< ItemType, Capacity >::Contains(const ItemType & item) const
	{
		if (this->count == 0)
		{
			return false;
		}
		else if (this->readIndex < this->writeIndex)
		{
			for (IndexType i = this->readIndex; i < this->writeIndex; ++i)
				if (this->items[i] == item)
					return true;
			return false;
		}
		else if (this->readIndex > this->writeIndex)
		{
			for (IndexType i = this->readIndex; i < Capacity; ++i)
				if (this->items[i] == item)
					return true;
			for (IndexType i = FirstIndex; i < this->writeIndex; ++i)
				if (this->items[i] == item)
					return true;
			return false;
		}
	}
}