#pragma once

#include "../NumericTypes.h"

namespace Ardutils
{
	namespace Details
	{
		template< unsigned Integer, unsigned Fraction >
		class UFixedPointBase
		{
		public:
			using InternalType = LeastUInt<Integer + Fraction>;

			constexpr const static unsigned long long Scale = 1ULL << Fraction;

		protected:
			class RawType
			{
			private:
				const InternalType value;

			public:
				constexpr inline explicit RawType(const InternalType & value) : value(value) {}
				constexpr inline explicit operator InternalType(void) const { return this->value; }
			};

		protected:
			InternalType value;

			constexpr UFixedPointBase(void) : value(0) {}
			constexpr UFixedPointBase(const RawType & value) : value(static_cast<InternalType>(value)) {}

		public:
			constexpr UFixedPointBase(const IntegerLiteral & value) : value(static_cast<InternalType>(value << Fraction)) {}
			constexpr UFixedPointBase(const IntegerLiteralU & value) : value(static_cast<InternalType>(value << Fraction)) {}
			constexpr UFixedPointBase(const IntegerLiteralL & value) : value(static_cast<InternalType>(value << Fraction)) {}
			constexpr UFixedPointBase(const IntegerLiteralLU & value) : value(static_cast<InternalType>(value << Fraction)) {}
			constexpr UFixedPointBase(const IntegerLiteralLL & value) : value(static_cast<InternalType>(value << Fraction)) {}
			constexpr UFixedPointBase(const IntegerLiteralLLU & value) : value(static_cast<InternalType>(value << Fraction)) {}

			constexpr UFixedPointBase(const DecimalLiteral & value) : value(static_cast<InternalType>(value * Scale)) {}
			constexpr UFixedPointBase(const DecimalLiteralF & value) : value(static_cast<InternalType>(value * Scale)) {}
			constexpr UFixedPointBase(const DecimalLiteralL & value) : value(static_cast<InternalType>(value * Scale)) {}
		};
	}
}