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
	class List
	{
	public:
		static_assert(Capacity > 0, "Attempt to create List with Capacity less than 1");

		using ItemType = T;
		using IndexType = LeastUInt<BitsRequired<Capacity>::Value>;
		using IndexOfType = LeastInt<BitsRequired<Capacity>::Value + 1>;

		using ValueType = T;
		using Reference = ValueType&;
		using ConstReference = const ValueType&;

		constexpr static const IndexType FirstIndex = 0;
		constexpr static const IndexType LastIndex = Capacity - 1;

	private:
		ItemType items[Capacity];
		IndexType next;

	public:
		List(void);

		inline bool IsEmpty(void) const; // O(1)
		inline bool IsFull(void) const; // O(1)

		inline IndexType GetCount(void) const; // O(1)
		constexpr inline IndexType GetCapacity(void) const; // O(1)

		bool Add(ItemType && item); // O(1)
		bool Add(const ItemType & item); // O(1)
		bool Remove(const ItemType & item); // O(n)
		void RemoveAt(const IndexType & index); // O(n)
		bool Insert(const IndexType & index, const ItemType & item); // O(n)
		
		void Clear(void); // O(n)
		bool Contains(const ItemType & item) const; // O(n)

		// Returns -1 if item not found
		IndexOfType IndexOf(const ItemType & item) const; // O(n)

		ItemType & operator [] (const IndexType & index); // O(1)
		const ItemType & operator [] (const IndexType & index) const; // O(1)
	};
}


//
// Definition
//

namespace Ardutils
{
	template< typename ItemType, SizeT Capacity >
	List< ItemType, Capacity >::List(void)
		: items(), next(0)
	{
	}

	template< typename ItemType, SizeT Capacity >
	inline bool List< ItemType, Capacity >::IsEmpty(void) const // O(1)
	{
		return (this->next == FirstIndex);
	}

	template< typename ItemType, SizeT Capacity >
	inline bool List< ItemType, Capacity >::IsFull(void) const // O(1)
	{
		return (this->next == this->GetCapacity());
	}

	template< typename ItemType, SizeT Capacity >
	inline typename List< ItemType, Capacity >::IndexType List< ItemType, Capacity >::GetCount(void) const // O(1)
	{
		return this->next;
	}

	template< typename ItemType, SizeT Capacity >
	constexpr inline typename List< ItemType, Capacity >::IndexType List< ItemType, Capacity >::GetCapacity(void) const // O(1)
	{
		return static_cast<IndexType>(Capacity);
	}

	template< typename ItemType, SizeT Capacity >
	bool List< ItemType, Capacity >::Add(ItemType && item) // O(1)
	{
		if (this->IsFull())
			return false;

		this->items[this->next] = Move(item);
		++this->next;
		return true;
	}

	template< typename ItemType, SizeT Capacity >
	bool List< ItemType, Capacity >::Add(const ItemType & item) // O(1)
	{
		if (this->IsFull())
			return false;

		this->items[this->next] = item;
		++this->next;
		return true;
	}

	template< typename ItemType, SizeT Capacity >
	bool List< ItemType, Capacity >::Remove(const ItemType & item) // O(n)
	{
		for(IndexType i = 0; i < this->next; ++i)
			if (this->items[i] == item)
			{
				--this->next;
				while (i < this->next)
				{
					this->items[i] = Move(this->items[i + 1]);
					++i;
				}
				(&this->items[this->next])->~ItemType();
				return true;
			}
		return false;
	}

	template< typename ItemType, SizeT Capacity >
	void List< ItemType, Capacity >::RemoveAt(const typename List< ItemType, Capacity >::IndexType & index) // O(n)
	{
		DEBUG_ASSERT(index < this->GetCapacity());
		DEBUG_ASSERT(index < this->next);

		--this->next;
		for (IndexType i = index; i < this->next; ++i)
				this->items[i] = Move(this->items[i + 1]);
		(&this->items[this->next])->~ItemType();
	}

	template< typename ItemType, SizeT Capacity >
	bool List< ItemType, Capacity >::Insert(const typename List< ItemType, Capacity >::IndexType & index, const ItemType & item) // O(n)
	{
		DEBUG_ASSERT(index < this->GetCapacity());
		DEBUG_ASSERT(index < this->next);

		if (this->IsFull())
			return false;

		++this->next;
		for (IndexType i = index + 1; i < this->next; ++i)
			this->items[i] = Move(this->items[i - 1]);
		this->items[index] = item;
		return true;
	}

	template< typename ItemType, SizeT Capacity >
	void List< ItemType, Capacity >::Clear(void) // O(n)
	{
		for (IndexType i = 0; i < this->next; ++i)
			(&this->items[i])->~ItemType();
		this->next = 0;
	}

	template< typename ItemType, SizeT Capacity >
	bool List< ItemType, Capacity >::Contains(const ItemType & item) const // O(n)
	{
		return this->indexOf(item) != -1;
	}

	template< typename ItemType, SizeT Capacity >
	typename List< ItemType, Capacity >::IndexOfType List< ItemType, Capacity >::IndexOf(const ItemType & item) const // O(n)
	{
		for (IndexType i = 0; i < this->next; ++i)
			if (this->items[i] == item)
				return i;
		return -1;
	}

	template< typename ItemType, SizeT Capacity >
	ItemType & List< ItemType, Capacity >::operator [] (const typename List< ItemType, Capacity >::IndexType & index) // O(1)
	{
		DEBUG_ASSERT(index < this->GetCapacity());
		DEBUG_ASSERT(index < this->next);

		return this->items[index];
	}

	template< typename ItemType, SizeT Capacity >
	const ItemType & List< ItemType, Capacity >::operator [] (const typename List< ItemType, Capacity >::IndexType & index) const // O(1)
	{
		DEBUG_ASSERT(index < this->GetCapacity());
		DEBUG_ASSERT(index < this->next);

		return this->items[index];
	}
}