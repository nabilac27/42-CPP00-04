<p align="center">
  <img src="https://cdn-icons-png.flaticon.com/512/6132/6132222.png" width="70" alt="C++ Logo">
</p>

<h1 align="center">CPP Module 03</h1>

<h3 align="center">
  Inheritance • Class Hierarchies • Constructor Chaining • Access Control
</h3>

## About

**CPP Module 03** introduces inheritance by building a small hierarchy of combat robots.

Starting from the `ClapTrap` base class, each exercise extends its functionality through derived classes, exploring code reuse, constructor chaining, access control, and class-specific behaviour.

---

## Exercises

| Exercise | Project | Concepts Introduced | Description |
|----------|---------|---------------------|-------------|
| `ex00` | ClapTrap | Classes, Encapsulation, Object State | Implements the `ClapTrap` base class with hit points, energy points, attack damage, and basic combat actions. |
| `ex01` | ScavTrap | Inheritance, Function Overriding | Extends `ClapTrap` through inheritance, customizes its behavior, and introduces `guardGate()`. |
| `ex02` | FragTrap | Inheritance, Specialized Behavior | Adds another derived class with different default statistics and the `highFivesGuys()` ability. |

---

## Program Overview

```bash
  CPP03
  ├── ex00: ClapTrap
  │   ├── Attack
  │   ├── Take damage
  │   ├── Repair
  │   └── Object state
  │
  ├── ex01: ScavTrap
  │   ├── Inherits ClapTrap
  │   ├── Override attack()
  │   └── guardGate()
  │
  └── ex02: FragTrap
      ├── Inherits ClapTrap
      ├── Override attack()
      └── highFivesGuys()
```

---
## Class Hierarchy

```text
                   ┌───────────────┐
                   │   ClapTrap    │
                   │  Base class   │
                   └───────┬───────┘
                           │
                    public inheritance
                           │
               ┌───────────┴───────────┐
               │                       │
        ┌──────▼───────┐        ┌──────▼───────┐
        │   ScavTrap   │        │   FragTrap   │
        │ Derived class│        │ Derived class│
        └──────────────┘        └──────────────┘
```

Both `ScavTrap` and `FragTrap` inherit the common state and behaviour of `ClapTrap`, while adding class-specific characteristics.

---

## Robot Statistics

| Class      | Hit Points | Energy Points | Attack Damage | Special Ability      |
| ---------- | :--------: | :-----------: | :-----------: | -------------------- |
| `ClapTrap` |     10     |       10      |       0       | Basic combat actions |
| `ScavTrap` |     100    |       50      |       20      | `guardGate()`        |
| `FragTrap` |     100    |      100      |       30      | `highFivesGuys()`    |

---

## Core Behaviour

Every robot can perform the following actions:

```cpp
void attack(const std::string& target);
void takeDamage(unsigned int amount);
void beRepaired(unsigned int amount);
```

An action can only be performed when the robot:

* has at least one hit point;
* has enough energy points;
* is still operational.

Attacking and repairing consume energy points, while taking damage reduces hit points.

---

## Concepts

<details>
<summary><strong>Inheritance</strong></summary>

---

Inheritance allows a class to reuse and extend the members of another class.

```cpp
class ScavTrap : public ClapTrap
{
    // ScavTrap inherits accessible members from ClapTrap
};
```

`ClapTrap` is the **base class**, while `ScavTrap` and `FragTrap` are **derived classes**.

This reduces code duplication and creates a logical relationship between related object types.

</details>

<details>
<summary><strong>Public Inheritance</strong></summary>

---

With public inheritance, the public interface of the base class remains public in the derived class.

```cpp
class FragTrap : public ClapTrap
{
};
```

A `FragTrap` can therefore use accessible `ClapTrap` functionality while also defining its own behaviour.

Public inheritance generally represents an **is-a** relationship:

```text
ScavTrap is a ClapTrap
FragTrap is a ClapTrap
```

</details>

<details>
<summary><strong>Protected Members</strong></summary>

---

Protected members can be accessed by the class that declares them and by its derived classes.

```cpp
class ClapTrap
{
protected:
    std::string  name;
    unsigned int hitPoints;
    unsigned int energyPoints;
    unsigned int attackDamage;
};
```

Unlike private members, protected members allow derived classes to adjust inherited state directly.

They still remain inaccessible from unrelated code outside the class hierarchy.

</details>

<details>
<summary><strong>Constructor Chaining</strong></summary>

---

When a derived object is created, the base-class constructor runs first.

```cpp
ScavTrap::ScavTrap(const std::string& name)
    : ClapTrap(name)
{
}
```

Construction order:

```text
ClapTrap constructor
        ↓
ScavTrap or FragTrap constructor
```

This ensures that the base portion of the object is initialized before the derived portion.

</details>

<details>
<summary><strong>Destructor Order</strong></summary>

---

Destruction happens in the reverse order of construction.

```text
ScavTrap or FragTrap destructor
        ↓
ClapTrap destructor
```

The derived part is cleaned up first, followed by the inherited base part.

Constructor and destructor messages make this lifecycle visible while running the exercises.

</details>

<details>
<summary><strong>Function Overriding</strong></summary>

---

A derived class can provide its own implementation of an inherited function.

```cpp
void ClapTrap::attack(const std::string& target);
void ScavTrap::attack(const std::string& target);
```

Although both functions share the same name and parameters, `ScavTrap` defines behaviour specific to its own robot type.

> CPP03 focuses on inheritance and class-specific implementations. Full runtime polymorphism with virtual functions is explored more deeply in later modules.

</details>

<details>
<summary><strong>Member Initializer Lists</strong></summary>

---

Initializer lists construct data members before the constructor body executes.

```cpp
ClapTrap::ClapTrap(const std::string& name)
    : name(name),
      hitPoints(10),
      energyPoints(10),
      attackDamage(0)
{
}
```

They are the preferred way to initialize class members and are required when calling a non-default base-class constructor.

</details>

<details>
<summary><strong>Orthodox Canonical Form</strong></summary>

---

Each class follows the Orthodox Canonical Form:

```cpp
ClapTrap();
ClapTrap(const std::string& name);
ClapTrap(const ClapTrap& other);
ClapTrap& operator=(const ClapTrap& other);
~ClapTrap();
```

It defines how objects are:

1. constructed;
2. copied;
3. assigned;
4. destroyed.

Derived classes implement the same lifecycle while correctly invoking their base-class operations.

</details>

<details>
<summary><strong>Code Reuse</strong></summary>

---

Without inheritance, every robot class would need to redefine the same state and combat functions.

Inheritance centralizes shared behaviour inside `ClapTrap`:

```text
ClapTrap
├── name
├── hit points
├── energy points
├── attack damage
├── attack()
├── takeDamage()
└── beRepaired()
```

Derived classes can then focus on what makes them different:

```text
ScavTrap
└── guardGate()

FragTrap
└── highFivesGuys()
```

This makes the hierarchy easier to maintain and extend.

</details>

---

## What I Learned

* Creating base and derived classes
* Applying public inheritance
* Controlling access with `private`, `protected`, and `public`
* Reusing inherited state and behaviour
* Calling base-class constructors from derived classes
* Understanding constructor and destructor order
* Implementing class-specific attack behaviour
* Maintaining the Orthodox Canonical Form across a class hierarchy
* Designing cleaner class relationships without repeating code

---

## Resources

* [Inheritance in C++](https://www.geeksforgeeks.org/cpp/inheritance-in-c/)
* [C++ Derived Classes](https://cplusplus.com/doc/tutorial/inheritance/)
* [Constructors and Initialization of Derived Classes](https://www.learncpp.com/cpp-tutorial/constructors-and-initialization-of-derived-classes/)
* [Order of Construction of Derived Classes](https://www.learncpp.com/cpp-tutorial/order-of-construction-of-derived-classes/)
* [Access Specifiers in C++](https://www.geeksforgeeks.org/cpp/access-modifiers-in-c/)
* [Orthodox Canonical Class Form](https://en.wikipedia.org/wiki/Rule_of_three_%28C%2B%2B_programming%29)

---

<div align="center">

© 2026 Nabila C. All rights reserved.

</div>
