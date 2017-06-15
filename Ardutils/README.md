# Ardutils
A simple lightweight utility library intended for use with Arduino and Arduboy projects.

**_Work In Progress_**
(i.e. Please don't complain if a change breaks your code)

**May not be compiling**
(It's not at the testing stage yet, so things might be broken for some compilers... or most compilers... or all compilers...)

## About

This library provides highly generic utilities to that should be suitable for all kinds of programs.
Most of the classes and functions provided are templated so that they're only instantiated as required.
Many classes are also designed to favour size over speed as they are designed for embedded environments.

## Aims

- Code should feature primarily general purpose utilities rather than domain-specific utilities.
- Compiled code should be as small as possible so that the library is lightweight.
- Code should be templated to provide flexibility and genericity.
- All code should be const correct.
- Code should follow [these style rules](https://github.com/Pharap/CppCodingConventions/blob/master/Conventions.md).

## Notices

- **Only include headers in the top level folder.**
- **Do not include headers from any sub-folders.**
- **Especially do not touch the things in the Details folder.**

# APIs

### Common:
- **Utils.h** - Utility functions
- **Bitwise.h** - Bit-level hacks
- **Collections.h** - Collection classes
- **Geometry.h** - Points, vectors and shapes
- **Maths.h** - Mathematical values
- **FixedPoint.h** - Fixed point types

### Uncommon
- **Debug.h** - Debugging facilities (e.g debug-assert macro)
- **BitSize.h** - Numeric types based on bit size and literals
- **BitsRequired.h** - Numeric types based on bit size and literals
- **NumericTypes.h** - Numeric types based on bit size and literals
- **Constraints.h** - Templates for checking properties of types (e.g. presence of operators)

### Stdlib-based:
- **TypeTraits.h** - Pascal-cased subset of stdlib's `<type_traits>`
- **Utility.h** - Pascal-cased subset of stdlib's `<utility>`

## Planned Features

- Maybe/Optional type
- Angle types
- Fixed point trigonometry
- Maths constants (e.g. Pi, Tau, E, Phi)
- Priority Queue

## To Do

- Remove Rectangle's Offset function?

