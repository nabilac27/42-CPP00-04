<p align="center">
  <img src="https://cdn-icons-png.flaticon.com/512/6132/6132222.png" width="70" alt="C++ Logo">
</p>

<h1 align="center">CPP Module 02</h1>

<h3 align="center">
  Orthodox Canonical Form • Fixed-Point Numbers • Operator Overloading • Polymorphism
</h3>

## About

**CPP02** introduces important concepts related to **operator overloading, fixed-point arithmetic, and the Orthodox Canonical Form** in C++.

The goal is to understand how classes behave when copied, assigned, or destroyed, and how to properly implement the canonical functions that control object lifecycle.

---

## Exercises

| Exercise | Project | Concepts Introduced | Description |
|----------|---------|---------------------|-------------|
| `ex00` | My First Class in Orthodox Canonical Form | Orthodox Canonical Form, Copy Constructor, Copy Assignment | Implements a `Fixed` class following the Orthodox Canonical Form while managing its internal fixed-point representation. |
| `ex01` | Towards a More Useful Fixed-Point Number Class | Fixed-Point Arithmetic, Type Conversion, Stream Insertion | Extends `Fixed` with integer and floating-point conversions, arithmetic helpers, and formatted output. |
| `ex02` | Now We're Talking | Operator Overloading, Arithmetic, Comparison Operators | Makes `Fixed` behave like a built-in numeric type through overloaded operators and utility functions. |

---

## Program Overview

```bash
CPP02
  ├── ex00: Orthodox Canonical Form
  │   ├── Fixed class
  │   ├── Raw bits
  │   ├── Copy constructor
  │   └── Copy assignment
  │
  ├── ex01: Fixed-Point Numbers
  │   ├── Integer conversion
  │   ├── Floating-point conversion
  │   ├── toFloat()
  │   ├── toInt()
  │   └── operator<<
  │
  └── ex02: Operator Overloading
      ├── Comparison operators
      ├── Arithmetic operators
      ├── Increment / decrement
      └── min() / max()
```
---

## ex00 — My First Canonical Class

This exercise introduces the **Orthodox Canonical Form** in C++.

A Fixed class is created by implementing the four canonical functions:
- Default constructor
- Copy constructor
- Copy assignment operator
- Destructor

The class stores a fixed-point value internally in an `int fixedPointNumber`, with 8 fractional bits stored as a static constant.

### Concepts Used
- Orthodox Canonical Form
- Constructors and destructors
- Copy constructor
- Copy assignment operator
- Encapsulation

### Files
```bash
include/Fixed.hpp
src/Fixed.cpp
main.cpp
```

### Logic
`Fixed` class also provides:
- `getRawBits()` to read the internal raw integer
- `setRawBits()` to modify it manually

The important part of the implementation is how copying works:
- the copy constructor prints a message, then delegates to the assignment operator with `*this = other`;
- the assignment operator copies the internal value using `other.getRawBits()` and protects against self-assignment with `if (this != &other)`

### Example Input
```c++
Fixed a;
Fixed b(a);
Fixed c;
c = b;
```

### Example Output
```bash
Default constructor called
Copy constructor called
Copy assignment operator called
Default constructor called
Copy assignment operator called
getRawBits member function called
0
getRawBits member function called
0
getRawBits member function called
0
Destructor called
Destructor called
Destructor called
```

---

## ex01 — Towards a More Useful Fixed-Point Class

This exercise improves the `Fixed` class by allowing conversion between:
- integers
- floating-point numbers
- fixed-point representation

Two constructors are added to convert int and float values into fixed-point format.

### Concepts Used
- Fixed-point arithmetic
- Type conversion
- toFloat() and toInt() methods
- Operator overloading (<<)

### Files
```bash
include/Fixed.hpp
src/Fixed.cpp
main.cpp
```

### Logic
`Fixed`class adds:
- `Fixed(const int intNumber)`
- `Fixed(const float floatNumber)`
- `toFloat()`
- `toInt()`
- `overloaded operator<<` for easy printing

Integer constructor shifts left by the number of fractional bits
```c++
fixedPointNumber = intNumber << fractionalBitsNumber;
```
That means the integer is stored in fixed-point format.

Float constructor scales the value and rounds it:
```c++
float scaledValue = floatNumber * (1 << fractionalBitsNumber);
fixedPointNumber = roundf(scaledValue);
```

So a float like 42.42f is converted into a fixed-point integer representation.

Then:
- `toFloat()` divides by 1 << fractionalBitsNumber
- `toInt()` shifts right by fractionalBitsNumber
Overloaded << uses `toFloat()`, which is why printing a Fixed object displays the decimal value naturally.

### Example Input
```bash
Fixed a;
Fixed const b(10);
Fixed const c(42.42f);
Fixed const d(b);
a = Fixed(1234.4321f);
```

### Example Output
```bash
a is 1234.43
b is 10
c is 42.4219
d is 10

a is 1234 as integer
b is 10 as integer
c is 42 as integer
d is 10 as integer
```

## ex02 — Now We're Talking

This exercise expands the `Fixed` class by adding:
- comparison operators
- arithmetic operators
- increment/decrement operators
- min() and max() utility functions

Arithmetic and comparison operators are added so that fixed-point numbers behave like normal numeric types.

### Concepts Used
- Operator overloading
- Arithmetic operations
- Increment / decrement operators
- Static member functions

### Files
```bash
include/Fixed.hpp
src/Fixed.cpp
main.cpp
```

## Example Input
```bash
Fixed a;
Fixed const b(Fixed(5.05f) * Fixed(2));

std::cout << a << std::endl;
std::cout << ++a << std::endl;
std::cout << a << std::endl;
std::cout << a++ << std::endl;
std::cout << a << std::endl;
std::cout << b << std::endl;
std::cout << Fixed::max(a, b) << std::endl;
```

### Example Output
```bash
0
0.00390625
0.00390625
0.00390625
0
10.1016
10.1016
```

---

## Concepts

<details>
<summary><strong>Orthodox Canonical Form</strong></summary>

---

The Orthodox Canonical Form defines the four special member functions responsible for an object's lifecycle.

```cpp
Fixed();
Fixed(const Fixed&);
Fixed& operator=(const Fixed&);
~Fixed();
```

Implementing these functions ensures objects can be copied, assigned, and destroyed safely.

</details>

<details>
<summary><strong>Fixed-Point Arithmetic</strong></summary>

---

Fixed-point numbers store fractional values using an integer and a fixed number of fractional bits.

```cpp
fixedPointNumber = value << fractionalBits;
```

Compared to floating-point numbers, fixed-point arithmetic provides predictable precision for a fixed range.

</details>

<details>
<summary><strong>Type Conversion</strong></summary>

---

Constructors and conversion functions translate between integers, floating-point values, and the internal fixed-point representation.

```cpp
Fixed a(42);
Fixed b(42.42f);

a.toFloat();
a.toInt();
```

These conversions make the class easier to use while hiding its internal representation.

</details>

<details>
<summary><strong>Operator Overloading</strong></summary>

---

Operators can be overloaded so user-defined types behave like built-in types.

```cpp
Fixed a;
Fixed b;

Fixed c = a + b;
```

Arithmetic, comparison, increment, and decrement operators allow `Fixed` objects to be manipulated naturally.

</details>

<details>
<summary><strong>Stream Insertion Operator</strong></summary>

---

Overloading `operator<<` allows objects to be printed using standard output streams.

```cpp
std::cout << fixed << std::endl;
```

Internally, the operator converts the fixed-point value into a floating-point representation before printing.

</details>

<details>
<summary><strong>Copy Semantics</strong></summary>

---

Copy constructors and copy-assignment operators determine how objects duplicate their internal state.

```cpp
Fixed a;
Fixed b(a);

b = a;
```

Proper copy semantics ensure every object maintains a consistent value after copying.

</details>

<details>
<summary><strong>Static Member Functions</strong></summary>

---

Static member functions belong to the class rather than an individual object.

```cpp
Fixed::min(a, b);
Fixed::max(a, b);
```

Since they don't operate on a specific instance, they can be called without creating an object.

</details>

---

## What I Learned

- Implementing the Orthodox Canonical Form
- Understanding object copy and assignment semantics
- Representing decimal values with fixed-point arithmetic
- Converting between integer, floating-point, and fixed-point representations
- Overloading operators to build intuitive numeric classes
- Using static member functions for utility operations
- Designing user-defined types that behave like built-in types

---

## Resources

- https://en.cppreference.com/w/cpp/language/operators
- https://en.cppreference.com/w/cpp/language/copy_constructor
- https://en.cppreference.com/w/cpp/language/as_operator
- https://en.cppreference.com/w/cpp/language/rule_of_three
- https://www.learncpp.com/cpp-tutorial/introduction-to-overloading-the-i-o-operators/
- https://www.learncpp.com/cpp-tutorial/overloading-the-arithmetic-operators-using-friend-functions/
- https://www.learncpp.com/cpp-tutorial/static-member-functions/
- https://en.wikipedia.org/wiki/Fixed-point_arithmetic

---

<div align="center">


© 2026 Nabila C. All rights reserved.

</div>
