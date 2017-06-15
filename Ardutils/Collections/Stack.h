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
	class Stack
	{
	public:
		static_assert(Capacity > 0, "Attempt to create Stack with Capacity less than 1");

		using ItemType = T;
		using IndexType = LeastUInt<BitsRequired<Capacity>::Value>;
		using IndexOfType = LeastInt<BitsRequired<Capacity>::Value + 1>;

		constexpr static const IndexType FirstIndex = 0;
		constexpr static const IndexType LastIndex = Capacity - 1;

	private:
		ItemType items[Capacity];
		IndexType next;

	public:
		Stack(void);

		inline bool IsEmpty(void) const; // O(1)
		inline bool IsFull(void) const; // O(1)

		inline IndexType GetCount(void) const; // O(1)
		constexpr inline IndexType GetCapacity(void) const; // O(1)

		const ItemType & Peek(void) const; // O(1)
		bool Push(const ItemType & item); // O(1)
		bool Push(ItemType && item); // O(1)
		ItemType && Pop(void); // O(1)

		void Clear(void); // O(n)
		bool Contains(const ItemType & item) const; // O(n)

		// Returns -1 if item not found
		IndexOfType IndexOf(const ItemType & item) const; // O(n)

		ItemType & operator [] (const IndexType index); // O(1)
		const ItemType & operator [] (const IndexType index) const; // O(1)
	};
}


//
// Definition
//

namespace Ardutils
{
	template< typename ItemType, SizeT Capacity >
	Stack< ItemType, Capacity >::Stack(void)
		: items(), next(0)
	{
	}

	template< typename ItemType, SizeT Capacity >
	inline bool Stack< ItemType, Capacity >::IsEmpty(void) const // O(1)
	{
		return (this->next == FirstIndex);
	}

	template< typename ItemType, SizeT Capacity >
	inline bool Stack< ItemType, Capacity >::IsFull(void) const // O(1)
	{
		return (this->next == this->GetCapacity());
	}

	template< typename ItemType, SizeT Capacity >
	inline typename Stack< ItemType, Capacity >::IndexType Stack< ItemType, Capacity >::GetCount(void) const // O(1)
	{
		return this->next;
	}

	template< typename ItemType, SizeT Capacity >
	constexpr inline typename Stack< ItemType, Capacity >::IndexType Stack< ItemType, Capacity >::GetCapacity(void) const // O(1)
	{
		return static_cast<IndexType>(Capacity);
	}

	template< typename ItemType, SizeT Capacity >
	const ItemType & Stack< ItemType, Capacity >::Peek(void) const // O(1)
	{
		DEBUG_ASSERT(this->next > 0);

		return this->items[this->next - 1];
	}

	template< typename ItemType, SizeT Capacity >
	bool Stack< ItemType, Capacity >::Push(const ItemType & item) // O(1)
	{
		if (this->IsFull())
			return false;

		this->items[this->next] = item;
		++this->next;
		return true;
	}

	template< typename ItemType, SizeT Capacity >
	bool Stack< ItemType, Capacity >::Push(ItemType && item) // O(1)
	{
		if (this->IsFull())
			return false;

		this->items[this->next] = Move(item);
		++this->next;
		return true;
	}

	template< typename ItemType, SizeT Capacity >
	ItemType && Stack< ItemType, Capacity >::Pop(void) // O(1)
	{
		DEBUG_ASSERT(this->next > 0);

		--this->next;
		return Move(this->items[this->next]);
	}

	template< typename ItemType, SizeT Capacity >
	void Stack< ItemType, Capacity >::Clear(void) // O(n)
	{
		for (IndexType i = 0; i < this->next; ++i)
			(&this->items[i])->~ItemType();
		this->next = 0;
	}

	template< typename ItemType, SizeT Capacity >
	bool Stack< ItemType, Capacity >::Contains(const ItemType & item) const // O(n)
	{
		return this->indexOf(item) != -1;
	}

	template< typename ItemType, SizeT Capacity >
	typename Stack< ItemType, Capacity >::IndexOfType Stack< ItemType, Capacity >::IndexOf(const ItemType & item) const // O(n)
	{
		for (IndexType i = 0; i < this->next; ++i)
			if (this->items[i] == item)
				return i;
		return -1;
	}

	template< typename ItemType, SizeT Capacity >
	ItemType & Stack< ItemType, Capacity >::operator [] (const typename Stack< ItemType, Capacity >::IndexType index) // O(1)
	{
		DEBUG_ASSERT(index < this->GetCapacity());
		DEBUG_ASSERT(index < this->next);

		return this->items[index];
	}

	template< typename ItemType, SizeT Capacity >
	const ItemType & Stack< ItemType, Capacity >::operator [] (const typename Stack< ItemType, Capacity >::IndexType index) const // O(1)
	{
		DEBUG_ASSERT(index < this->GetCapacity());
		DEBUG_ASSERT(index < this->next);

		return this->items[index];
	}
}

