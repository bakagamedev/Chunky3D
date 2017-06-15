#pragma once

#include "BeginDefines.h"

namespace Ardutils
{
	//
	// Logical
	//

	DefineHasUnaryOperatorAll( LogicalNegation, ! )
	DefineHasBinaryOperatorAll( LogicalAnd, && )
	DefineHasBinaryOperatorAll( LogicalOr, || )

	//
	// Comparison
	//

	DefineHasBinaryOperatorAll( EqualTo, == )
	DefineHasBinaryOperatorAll( NotEqualTo, != )
	DefineHasBinaryOperatorAll( LessThan, < )
	DefineHasBinaryOperatorAll( GreaterThan, > )
	DefineHasBinaryOperatorAll( LessThanOrEqualTo, <= )
	DefineHasBinaryOperatorAll( GreaterThanOrEqualTo, >= )

	//
	// Arithmetic
	//

	DefineHasBinaryOperatorAll( Addition, + )
	DefineHasBinaryOperatorAll( Subtraction, - )
	DefineHasBinaryOperatorAll( Multiplication, * )
	DefineHasBinaryOperatorAll( Division, / )
	DefineHasBinaryOperatorAll( Modulo, % )

	//
	// Bitwise
	//

	DefineHasBinaryOperatorAll( BitwiseAnd, & )
	DefineHasBinaryOperatorAll( BitwiseOr, | )
	DefineHasBinaryOperatorAll( BitwiseXor, ^ )
	DefineHasBinaryOperatorAll( BitwiseLeftShift, << )
	DefineHasBinaryOperatorAll( BitwiseRightShift, >> )

	//
	// Compound Assignment
	//

	DefineHasBinaryOperatorAll( AdditionAssignment, += )
	DefineHasBinaryOperatorAll( SubtractionAssignment, -= )
	DefineHasBinaryOperatorAll( MultiplicationAssignment, *= )
	DefineHasBinaryOperatorAll( DivisionAssignment, /= )
	DefineHasBinaryOperatorAll( ModuloAssignment, %= )
	DefineHasBinaryOperatorAll( BitwiseAndAssignment, &= )
	DefineHasBinaryOperatorAll( BitwiseOrAssignment, |= )
	DefineHasBinaryOperatorAll( BitwiseXorAssignment, ^= )
	DefineHasBinaryOperatorAll( BitwiseLeftShiftAssignment, <<= )
	DefineHasBinaryOperatorAll( BitwiseRightShiftAssignment, >>= )

	//
	// Other
	//

	DefineHasUnaryOperatorAll( Indirection, * )
	DefineHasUnaryOperatorAll( AddressOf, & )
	DefineHasUnaryEitherOperator( MemberOfPointer, ->)
	DefineHasUnaryMemberOperator( MemberOfPointer, ->)
	DefineHasBinaryOperatorAll( PointerToMemberOfPointer, ->*)
	DefineHasBracketOperatorAll( Subscript, [, ])
}

#include "EndDefines.h"