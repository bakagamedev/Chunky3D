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
	class BinaryMaxHeap
	{
	public:
		static_assert(Capacity > 0, "Attempt to create BinaryMaxHeap with Capacity less than 1");

		using ItemType = T;
		using IndexType = LeastUInt<BitsRequired<Capacity>::Value>;
		using IndexOfType = LeastInt<BitsRequired<Capacity>::Value + 1>;

		constexpr static const IndexType FirstIndex = 0;
		constexpr static const IndexType LastIndex = Capacity - 1;

	private:
		ItemType items[Capacity];
		IndexType next;

	public:
		BinaryMaxHeap(void);

		bool IsEmpty(void) const; // O(1)
		bool IsFull(void) const; // O(1)

		IndexType GetCount(void) const; // O(1)
		constexpr IndexType GetCapacity(void) const; // O(1)

		const ItemType & GetMax(void) const; // O(1)
		const ItemType & GetMin(void) const; // O(2 ^ n + k)

		bool Add(const ItemType & item); // O(log n)
		bool Add(ItemType && item); // O(log n)
		bool Remove(const ItemType & item); // O(n)
		bool RemoveMax(void); // O(log n)
		bool RemoveMin(void); // O(2 ^ n + k)

		void Clear(void); // O(n)
		bool Contains(const ItemType & item) const; // O(n)

	private:
		inline static IndexType GetLeftChildIndex(const IndexType & index);
		inline static IndexType GetRightChildIndex(const IndexType & index);
		inline static IndexType GetParentIndex(const IndexType & index);

		void SiftUp(const IndexType & item);
		void SiftDown(const IndexType & item);
	};
}


//
// Definition
//

namespace Ardutils
{
	template< typename ItemType, SizeT Capacity >
	BinaryMaxHeap< ItemType, Capacity >::BinaryMaxHeap(void)
		: items(), next(0)
	{
	}

	template< typename ItemType, SizeT Capacity >
	bool BinaryMaxHeap< ItemType, Capacity >::IsEmpty(void) const // O(1)
	{
		return (this->next == FirstIndex);
	}

	template< typename ItemType, SizeT Capacity >
	bool BinaryMaxHeap< ItemType, Capacity >::IsFull(void) const // O(1)
	{
		return (this->next == this->GetCapacity());
	}

	template< typename ItemType, SizeT Capacity >
	typename BinaryMaxHeap< ItemType, Capacity >::IndexType BinaryMaxHeap< ItemType, Capacity >::GetCount(void) const // O(1)
	{
		return this->next;
	}

	template< typename ItemType, SizeT Capacity >
	constexpr typename BinaryMaxHeap< ItemType, Capacity >::IndexType BinaryMaxHeap< ItemType, Capacity >::GetCapacity(void) const // O(1)
	{
		return static_cast<IndexType>(Capacity);
	}

	template< typename ItemType, SizeT Capacity >
	const typename BinaryMaxHeap< ItemType, Capacity >::ItemType & BinaryMaxHeap< ItemType, Capacity >::GetMax(void) const // O(1)
	{
		DEBUG_ASSERT(!this->IsEmpty());
		return this->items[0];
	}

	template< typename ItemType, SizeT Capacity >
	const typename BinaryMaxHeap< ItemType, Capacity >::ItemType & BinaryMaxHeap< ItemType, Capacity >::GetMin(void) const  // O(2 ^ n + k)
	{
		DEBUG_ASSERT(!this->IsEmpty());

		IndexType left = 0;

		for (IndexType i = 1; i < this->next; i = GetLeftChildIndex(i))
			left = i;

		IndexType maxIndex = left;
		for (IndexType i = maxIndex; i < this->next; ++i)
			if (this->items[i] < this->items[maxIndex])
				maxIndex = i;

		return this->items[maxIndex];
	}

	template< typename ItemType, SizeT Capacity >
	bool BinaryMaxHeap< ItemType, Capacity >::Add(const ItemType & item) // O(log n)
	{
		if (this->IsFull())
			return false;

		const auto index = this->next;

		this->items[this->next] = item;
		++this->next;

		SiftUp(index);

		return true;
	}

	template< typename ItemType, SizeT Capacity >
	bool BinaryMaxHeap< ItemType, Capacity >::Add(ItemType && item) // O(log n)
	{
		if (this->IsFull())
			return false;

		const auto index = this->next;

		this->items[this->next] = Move(item);
		++this->next;

		SiftUp(index);

		return true;
	}

	template< typename ItemType, SizeT Capacity >
	bool BinaryMaxHeap< ItemType, Capacity >::Remove(const ItemType & item) // O(log n)
	{
		for (IndexType i = 0; i < this->next; ++i)
			if (this->items[i] == item)
			{
				--this->next;
				this->items[i] = this->items[this->next];
				(&this->items[this->next])->~ItemType();
				SiftDown(i);
				return true;
			}
		return false;
	}

	template< typename ItemType, SizeT Capacity >
	bool BinaryMaxHeap< ItemType, Capacity >::RemoveMax(void) // O(log n)
	{
		if (this->IsEmpty())
			return false;

		--this->next;
		this->items[0] = this->items[this->next];
		(&this->items[this->next])->~ItemType();

		SiftDown(0);

		return true;
	}

	template< typename ItemType, SizeT Capacity >
	bool BinaryMaxHeap< ItemType, Capacity >::RemoveMin(void) // O(2 ^ n + k)
	{
		if (this->IsEmpty())
			return false;

		IndexType left = 0;

		for (IndexType i = 1; i < this->next; i = GetLeftChildIndex(i))
			left = i;

		IndexType maxIndex = left;
		for (IndexType i = maxIndex; i < this->next; ++i)
			if (this->items[i] < this->items[maxIndex])
				maxIndex = i;

		--this->next;
		for (IndexType i = maxIndex; i < this->next; ++i)
			this->items[i] = Move(this->items[i + 1]);
		(&this->items[this->next])->~ItemType();

		return true;
	}

	template< typename ItemType, SizeT Capacity >
	void BinaryMaxHeap< ItemType, Capacity >::Clear(void) // O(n)
	{
		for (IndexType i = 0; i < this->next; ++i)
			(&this->items[i])->~ItemType();
		this->next = 0;
	}

	template< typename ItemType, SizeT Capacity >
	bool BinaryMaxHeap< ItemType, Capacity >::Contains(const ItemType & item) const // O(n)
	{
		for (IndexType i = 0; i < this->next; ++i)
			if (this->items[i] == item)
				return true;
		return false;
	}

	template< typename ItemType, SizeT Capacity >
	inline typename BinaryMaxHeap< ItemType, Capacity >::IndexType BinaryMaxHeap< ItemType, Capacity >::GetLeftChildIndex(const typename BinaryMaxHeap< ItemType, Capacity >::IndexType & index) // O(n)
	{
		return (index * 2) + 1;
	}

	template< typename ItemType, SizeT Capacity >
	inline typename BinaryMaxHeap< ItemType, Capacity >::IndexType BinaryMaxHeap< ItemType, Capacity >::GetRightChildIndex(const typename BinaryMaxHeap< ItemType, Capacity >::IndexType & index) // O(n)
	{
		return (index * 2) + 2;
	}

	template< typename ItemType, SizeT Capacity >
	inline typename BinaryMaxHeap< ItemType, Capacity >::IndexType BinaryMaxHeap< ItemType, Capacity >::GetParentIndex(const typename BinaryMaxHeap< ItemType, Capacity >::IndexType & index) // O(n)
	{
		return (index - 1) / 2;
	}

	template< typename ItemType, SizeT Capacity >
	void BinaryMaxHeap< ItemType, Capacity >::SiftUp(const typename BinaryMaxHeap< ItemType, Capacity >::IndexType & index) // O(n)
	{
		auto nodeIndex = index;
		while (nodeIndex != 0)
		{
			const auto parentIndex = GetParentIndex(nodeIndex);
			if (this->items[parentIndex] > this->items[nodeIndex])
				return;

			Swap(this->items[nodeIndex], this->items[parentIndex]);
			nodeIndex = parentIndex;
		}
	}

	template< typename ItemType, SizeT Capacity >
	void BinaryMaxHeap< ItemType, Capacity >::SiftDown(const typename BinaryMaxHeap< ItemType, Capacity >::IndexType & index) // O(n)
	{
		auto nodeIndex = index;
		while (true)
		{
			const auto leftIndex = GetLeftChildIndex(nodeIndex);
			const auto rightIndex = GetRightChildIndex(nodeIndex);

			if (leftIndex >= this->GetCount())
				return;

			auto minIndex = nodeIndex;

			if (this->items[leftIndex] > this->items[minIndex])
				minIndex = leftIndex;

			if (rightIndex < this->GetCount())
				if (this->items[rightIndex] > this->items[minIndex])
					minIndex = rightIndex;

			if (minIndex != nodeIndex)
			{
				Swap(this->items[minIndex], this->items[nodeIndex]);
				nodeIndex = minIndex;
			}
			else
				return;
		}
	}
}