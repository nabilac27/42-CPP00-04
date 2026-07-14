<p align="center">
  <img src="https://cdn-icons-png.flaticon.com/512/6132/6132222.png" width="70" alt="C++ Logo">
</p>

<h1 align="center">CPP Module 04</h1>

<h3 align="center">
  Polymorphism • Abstract Classes • Interfaces • Deep Copy
</h3>

## About

**CPP04** explores runtime polymorphism, deep-copy semantics, and abstract classes through an inheritance hierarchy of animals.

The module introduces virtual functions, resource ownership, and pure virtual functions while emphasizing safe memory management and proper object-oriented design.

---

## Exercises

| Exercise | Project | Concepts Introduced | Description |
|----------|---------|---------------------|-------------|
| `ex00` | Polymorphism | Virtual Functions, Runtime Polymorphism | Builds an inheritance hierarchy using `Animal`, `Dog`, `Cat`, and `WrongAnimal` to demonstrate the importance of virtual functions and dynamic dispatch. |
| `ex01` | Brain | Deep Copy, Resource Ownership | Extends `Dog` and `Cat` with dynamically allocated `Brain` objects, implementing safe deep-copy semantics and proper memory management. |
| `ex02` | Abstract Animal | Abstract Classes, Pure Virtual Functions | Converts `Animal` into an abstract base class using pure virtual functions, enforcing a common interface for all derived animals. |

---

## Program Overview

```bash
  CPP04
  ├── ex00: Polymorphism
  │   ├── Animal
  │   ├── Dog
  │   ├── Cat
  │   ├── WrongAnimal
  │   ├── WrongCat
  │   └── Virtual functions
  │
  ├── ex01: Brain
  │   ├── Brain
  │   ├── Deep copy
  │   ├── Copy constructor
  │   ├── Copy assignment
  │   └── Resource ownership
  │
  └── ex02: Abstract Animal
      ├── Pure virtual functions
      ├── Abstract Animal
      ├── Runtime polymorphism
      └── Virtual destructor
```
---

## Class Hierarchy

```text
                    Animal
            (abstract base class)
        ┌─────────────────────────┐
        │ protected: type         │
        │ virtual makeSound() = 0 │
        │ virtual destructor      │
        └────────────┬────────────┘
                     │
          ┌──────────┴──────────┐
          │                     │
        Dog                   Cat
          │                     │
     owns Brain*           owns Brain*
          │                     │
          └──────────┬──────────┘
                     │
                   Brain
              ideas[100]
```

### Relationships

```text
Animal
  ├── Dog
  └── Cat
  
  Dog ──owns──> Brain
  Cat ──owns──> Brain
```

* `Animal` is an abstract base class because `makeSound()` is pure virtual.
* `Dog` and `Cat` inherit publicly from `Animal`.
* Both derived classes override `makeSound()`.
* Each `Dog` and `Cat` dynamically allocates and owns a `Brain`.
* `Brain` stores 100 ideas in a fixed-size array.
* Copy constructors and copy-assignment operators must perform a deep copy so every animal owns an independent `Brain`.
* The virtual destructor in `Animal` ensures the correct derived destructor runs when deleting through an `Animal*`.

### Runtime Polymorphism

```cpp
const Animal* animal = new Dog();

animal->makeSound();

delete animal;
```

Although the pointer type is `Animal*`, the object is a `Dog`, so `Dog::makeSound()` is called at runtime.

The following does not compile:

```cpp
Animal animal;
```

`Animal` cannot be instantiated because it contains a pure virtual function:

```cpp
virtual void makeSound() const = 0;
```

---
## ex00 — Polymorphism

- Base class: `Animal`
- Derived classes: `Dog`, `Cat`
- `makeSound()` is **virtual**

### Example

```cpp
Animal* a = new Dog();
a->makeSound(); // Dog sound
```

Wrong Example
- WrongAnimal shows behavior without virtual
- Calls wrong function when using base pointer

---

## ex01 — Deep Copy
Added 
```cpp
class: Brain
```

Dog and Cat contain:
```cpp
Brain* brain;
```

Shallow Copy (Wrong)
```cpp
brain = other.brain;
```

Deep Copy (Correct)
```cpp
brain = new Brain(*other.brain);   // copy constructor
*brain = *other.brain;             // assignment operator
```

Each object must have its own Brain to avoid:
- shared memory
- double delete
- bugs

---

## ex02 — Abstract Class

Animal becomes abstract:

```cpp
virtual void makeSound() const = 0;
Result
Animal a;              // ❌ not allowed
Animal* a = new Dog(); // ✅
```

Key Concepts
- Polymorphism
    Same function call, different behavior depending on object type.

- Deep Copy
    Copy the data, not the pointer.

- Virtual Destructor
    Ensures correct destruction of derived objects.
```cpp
Animal* a = new Dog();
delete a;
```

- Abstract Class
    A class with at least one pure virtual function (= 0).

----

## Compilation
```bash
make
./animal
```

---

## Concepts

<details>
<summary><strong>Runtime Polymorphism</strong></summary>

---

Virtual functions allow the same interface to behave differently depending on the object's actual type.

```cpp
Animal* animal = new Dog();
animal->makeSound();
```

The call is resolved at runtime.

</details>

<details>
<summary><strong>Virtual Functions & Dynamic Dispatch</strong></summary>

---

Declaring a function `virtual` allows derived classes to override it.

```cpp
virtual void makeSound() const;
```

When accessed through a base-class pointer or reference, C++ automatically calls the correct derived implementation.

</details>

<details>
<summary><strong>Virtual Destructors</strong></summary>

---

Base classes should declare virtual destructors.

```cpp
virtual ~Animal();
```

This guarantees the derived destructor executes correctly when deleting through a base pointer.

</details>

<details>
<summary><strong>Abstract Classes & Pure Virtual Functions</strong></summary>

---

An abstract class cannot be instantiated directly.

```cpp
virtual void makeSound() const = 0;
```

Derived classes must implement every pure virtual function.

</details>

<details>
<summary><strong>Deep Copy vs Shallow Copy</strong></summary>

---

Objects owning dynamic memory require a **deep copy**.

```cpp
Dog a;
Dog b(a);
```

Each `Dog` owns its own `Brain`, preventing shared pointers and double deletion.
</details>

<details>
<summary><strong>Composition & Resource Ownership</strong></summary>

---

A `Dog` owns a `Brain`.

```text
Dog
└── Brain
```

The owning object is responsible for creating, copying, and destroying its resources.

</details>

<details>
<summary><strong>Orthodox Canonical Form</strong></summary>

---

Classes managing resources implement:

```cpp
Class();
Class(const Class&);
Class& operator=(const Class&);
~Class();
```

This ensures copying and destruction are performed safely.

</details>

---

## What I Learned

- Implementing runtime polymorphism with virtual functions
- Managing dynamic resources through deep copies
- Designing abstract base classes with pure virtual functions
- Understanding resource ownership and composition
- Preventing object slicing through pointers and references
- Applying the Orthodox Canonical Form to resource-owning classes

---

## Resources

* [Learn C++ - Abstract Classes and Interfaces](https://www.learncpp.com/cpp-tutorial/pure-virtual-functions-abstract-base-classes-and-interface-classes/)
* [Learn C++ - Object Slicing](https://www.learncpp.com/cpp-tutorial/object-slicing/)
* [cppreference - Virtual Functions](https://en.cppreference.com/w/cpp/language/virtual)
* [cppreference - Inheritance](https://en.cppreference.com/w/cpp/language/derived_class)
* [GeeksforGeeks - Virtual Function in C++](https://www.geeksforgeeks.org/cpp/virtual-function-cpp/)
* [GeeksforGeeks - Abstract Classes in C++](https://www.geeksforgeeks.org/cpp/pure-virtual-functions-and-abstract-classes/)

---

<div align="center">

© 2026 Nabila C. All rights reserved.

</div>

