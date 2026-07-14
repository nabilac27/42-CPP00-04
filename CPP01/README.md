<p align="center">
  <img src="https://cdn-icons-png.flaticon.com/512/6132/6132222.png" width="70" alt="C++ Logo">
</p>

<h1 align="center">CPP Module 01</h1>

<h3 align="center">
  Memory Allocation • References • Pointers • File Streams • Switch Statements
</h3>

## About

**CPP Module 01** covers memory management, pointers, references, file I/O, function pointers, and `switch` statements through a series of practical C++ exercises.

---

## Exercises

| Exercise | Project | Concepts Introduced | Description |
|----------|---------|---------------------|-------------|
| `ex00` | BraiiiiiiinnnzzzZ | Stack vs Heap, `new` & `delete`, Constructors, Destructors | Create `Zombie` objects on both the stack and heap, introducing dynamic memory allocation and object lifetime. |
| `ex01` | Moar Brainz! | Arrays of Objects, `new[]`, `delete[]` | Allocate an array of `Zombie` objects dynamically, initialize them, and correctly release memory. |
| `ex02` | HI THIS IS BRAIN | Pointers, References, Memory Addresses | Compare pointers and references by demonstrating how both access the same variable while behaving differently. |
| `ex03` | Unnecessary Violence | Composition, References, Pointers, Object Relationships | Implement `Weapon`, `HumanA`, and `HumanB` to explore ownership, references, and nullable pointers. |
| `ex04` | Sed is for Losers | File Streams, String Manipulation | Read a text file, replace every occurrence of a string with another, and write the modified contents to a new file. |
| `ex05` | Harl 2.0 | Member Function Pointers | Implement a complaint system using pointers to member functions for dynamic dispatch. |
| `ex06` | Harl Filter | `switch` Statements, Control Flow | Extend the previous exercise with a `switch` statement to filter and display complaint levels according to user input. |

---

## Program Overview
```bash
  CPP01
  ├── ex00: BraiiiiiiinnnzzzZ
  │   ├── Stack allocation
  │   ├── Heap allocation
  │   └── Object lifetime
  │
  ├── ex01: Moar Brainz!
  │   ├── Dynamic arrays
  │   ├── new[]
  │   └── delete[]
  │
  ├── ex02: HI THIS IS BRAIN
  │   ├── Pointers
  │   ├── References
  │   └── Memory addresses
  │
  ├── ex03: Unnecessary Violence
  │   ├── Weapon
  │   │   ├── Stores weapon type
  │   │   └── Can change type
  │   ├── HumanA
  │   │   ├── Uses Weapon&
  │   │   ├── Always armed
  │   │   └── Reference member
  │   ├── HumanB
  │   │   ├── Uses Weapon*
  │   │   ├── Can be unarmed
  │   │   └── setWeapon()
  │   └── Object relationships
  │
  ├── ex04: Sed is for Losers
  │   ├── File I/O
  │   ├── String replacement
  │   └── Output file
  │
  ├── ex05: Harl 2.0
  │   ├── Member function pointers
  │   └── Complaint dispatcher
  │
  └── ex06: Harl Filter
      ├── switch statement
      └── Log filtering
```
---

## ex00 — BraiiiiiiinnnzzzZ

This exercise introduces the difference between **stack allocation** and **heap allocation** using a `Zombie` class. 

`Zombie` class stores a `name`, has an `announce()` method, and prints a destruction message in the destructor.

Logic
- `newZombie()` allocates a zombie with new and returns a pointer, which means the zombie lives on the heap until you manually delete it.
- `randomChump()` creates a local `Zombie zombie(name)`; and calls `announce()`;, so that zombie lives on the stack and is destroyed automatically when the function ends

Example Input:
```bash
randomChump("Stack Zombie");

Zombie* zombie1 = newZombie("Heap Zombie");
zombie1->announce();
delete (zombie1);
```

Example Output:
```bash
Stack Zombie: BraiiiiiiinnnzzzZ...
Stack Zombie: destroyed

Heap Zombie: BraiiiiiiinnnzzzZ...
Heap Zombie: destroyed
```

## ex01 — Moar Brainz!
This exercise extends the zombie idea by creating a zombie horde with one allocation. The code allocates an array with new `Zombie[N]`, then fills each element using `setZombie(name)`. 

Logic
- `Zombie` class in this exercise has:
    - a default constructor
    - a named constructor
    - `announce()`
    - `setZombie(std::string name)` for assigning the name after array allocation 

That setter is important because when allocating new `Zombie[N]`, C++ first default-constructs every element, then loop assigns names one by one:
```bash
Zombie* horde = new Zombie[N];

for (int i = 0; i < N; i++)
    horde[i].setZombie(name);
```

### Example Output
```bash
Test Zombie: BraiiiiiiinnnzzzZ...
Test Zombie: BraiiiiiiinnnzzzZ...
Test Zombie: BraiiiiiiinnnzzzZ...
Test Zombie: BraiiiiiiinnnzzzZ...
Test Zombie: BraiiiiiiinnnzzzZ...
Test Zombie: destroyed
Test Zombie: destroyed
Test Zombie: destroyed
Test Zombie: destroyed
Test Zombie: destroyed
```

## ex02 — HI THIS IS BRAIN

This exercise demonstrates the difference between pointers and references.
The program creates a string and then:
- A pointer pointing to the string
- A reference referring to the same string

Logic
```bash
std::string value = "HI THIS IS BRAIN";
std::string* stringPTR = &value;
std::string& stringREF = value;
```

Then it prints:
- the address of the original string: &value
- the address stored inside the pointer: stringPTR
- the address of the reference target: &stringREF

For values, it prints:
- value
- *stringPTR → this is dereferencing the pointer
- stringREF → this is direct reference syntax, no * needed

So this exercise is a very good place to explain:
- stringPTR stores an address
- *stringPTR accesses the value at that address
- stringREF is an alias for value
- &stringREF gives the same address as &value

### Example Output
```bash
PRINT MEMORY ADDRESS
--------------------
Memory address of string variable : 0x...
Memory address held by PTR : 0x...
Memory address held by REF : 0x...

PRINT VALUE
--------------------
Value of string variable : HI THIS IS BRAIN
Value pointed by PTR : HI THIS IS BRAIN
Value pointed by REF : HI THIS IS BRAIN
```

## ex03 — Unnecessary Violence

This exercise introduces references as class members and explores how object relationships work.

Logic
- `Weapon` stores a type string and exposes:
    - `getType()` returning `const std::string&`
    - `setType()` to modify the weapon type

Two classes are implemented:
* `HumanA` → always has a weapon (reference)
* `HumanB` → may or may not have a weapon (pointer)
Both classes can attack using a Weapon object.
This demonstrates the difference between references and pointers inside classes.

`HumanA` stores `Weapon& weapon`;, so it must receive a weapon in the constructor and is always armed:
```c++
HumanA(const std::string& name, Weapon& weaponA);
```

`HumanB`stores `Weapon* weapon`;, initializes it to NULL, and later receives a weapon through `setWeapon()`:
```c++
HumanB(const std::string& name) : name(name), weapon(NULL) {}
void setWeapon(Weapon& weaponB) { this->weapon = &weaponB; }
```

That means:
- `HumanA` + reference = always has a weapon
- `HumanB` + pointer = may have no weapon yet, so a setter makes sense

 attack() methods also show the syntax difference:

`weapon.getType()` for the reference in `HumanA`
- `weapon.getType()` for the reference in `HumanA`
- `weapon->getType()` for the pointer in `HumanB`


### Example Output
```bash
Bob attacks with their club
Jim attacks with their club
Jim attacks with their crued spiked club
```

## ex04 — Sed Is For Losers

This exercise implements a small file processing program that replaces occurrences of a string within a file.

The program:
* Takes a filename and two strings (s1, s2)
* Reads the file content
* Replaces all occurrences of s1 with s2
* Writes the result into a new file with .replace appended

Logic
- checks for exactly 3 arguments after the executable name
- rejects an empty s1
- opens the input file
- creates filename + ".replace"
- reads line by line with `std::getline`
- finds every occurrence of s1
- replaces it by using `erase()` and `insert()` instead of `std::string::replace()`

Replacement loop is the core logic of the exercise
```c++
index = line.find(s1, index);
line.erase(index, s1.length());
line.insert(index, s2);
index += s2.length();
```

### Input Example
```bash
./replace file.txt hello world
```

### Output Example
- Creates: ```file.txt.replace```
- with all "hello" replaced by "world".

## ex05 — Harl 2.0
This exercise introduces function pointers and structured logging behavior.
A Harl class is implemented that can output different complaint messages depending on a given log level.

### Available levels:
- DEBUG
- INFO
- WARNING
- ERROR

Logic
Harl class has four private methods:
- debug()
- info()
- warning()
- error()

The interesting part is `complain(std::string level)` implementation. It uses:
- an array of level strings
- an array of member function pointers:
```c++
  void (Harl::*harl_function[])() = {
    &Harl::debug,
    &Harl::info,
    &Harl::warning,
    &Harl::error
};
```

Then it loops through the levels and calls the matching member function with:
```c++
(this->*harl_function[i])();
```


Example Input
```bash
./harl DEBUG
```

Example Output
```bash
DEBUG : I love having extra sauce for my burger.
I really do!
INFO : I cannot believe adding extra sauce costs more money.
WARNING : I think I deserve to have some extra sauce for free.
ERROR : This is unacceptable! I want to speak to the manager now.
Invalid Level
```

---

## Concepts

<details>
<summary><strong>Stack vs Heap Allocation</strong></summary>

---

Objects created on the stack are destroyed automatically when they leave scope, while heap objects remain alive until explicitly deleted.

```cpp
Zombie stackZombie("Foo");
Zombie* heapZombie = new Zombie("Bar");

delete heapZombie;
```

Choosing between stack and heap allocation determines an object's lifetime.

</details>

<details>
<summary><strong>Dynamic Memory Management</strong></summary>

---

Dynamic memory is allocated with `new` and released with `delete`.

```cpp
Zombie* zombie = new Zombie("Foo");

delete zombie;
```

Arrays allocated with `new[]` must be released using `delete[]`.

```cpp
Zombie* horde = new Zombie[10];

delete[] horde;
```

</details>

<details>
<summary><strong>Pointers & References</strong></summary>

---

Pointers store memory addresses, while references act as aliases to existing objects.

```cpp
std::string str = "Hello";

std::string* ptr = &str;
std::string& ref = str;
```

Pointers can be reassigned or be `NULL`, whereas references must always refer to a valid object.

</details>

<details>
<summary><strong>Composition</strong></summary>

---

Composition models a **has-a** relationship between classes.

```text
HumanA
└── Weapon

HumanB
└── Weapon
```

`HumanA` always owns a valid weapon through a reference, while `HumanB` stores a pointer and may exist without a weapon.

</details>

<details>
<summary><strong>References vs Pointers as Members</strong></summary>

---

References must be initialized during construction, while pointers can be assigned later.

```cpp
class HumanA
{
    Weapon& weapon;
};

class HumanB
{
    Weapon* weapon;
};
```

This demonstrates mandatory versus optional object relationships.

</details>

<details>
<summary><strong>File Streams</strong></summary>

---

The C++ Standard Library provides file streams for reading and writing files.

```cpp
std::ifstream input("file.txt");
std::ofstream output("file.replace");
```

Files are processed using standard stream operations such as `getline()`.

</details>

<details>
<summary><strong>Member Function Pointers</strong></summary>

---

Pointers to member functions allow selecting and invoking class methods dynamically.

```cpp
void (Harl::*functions[])() =
{
    &Harl::debug,
    &Harl::info
};

(this->*functions[i])();
```

Unlike normal function pointers, member function pointers require an object instance.

</details>

<details>
<summary><strong>Switch Statements</strong></summary>

---

The `switch` statement selects one execution path based on an integral value.

```cpp
switch (level)
{
    case DEBUG:
        debug();
        break;
}
```

It provides a cleaner alternative to long chains of `if` / `else if` statements.

</details>

## What I Learned

- Managing object lifetime using stack and heap allocation
- Allocating and releasing dynamic memory safely
- Working with pointers, references, and object ownership
- Designing object relationships using composition
- Reading from and writing to files with file streams
- Using pointers to member functions for dynamic dispatch
- Controlling program flow with `switch` statements

---

## Resources

- https://en.cppreference.com/w/cpp/language/new
- https://en.cppreference.com/w/cpp/language/delete
- https://en.cppreference.com/w/cpp/language/pointer
- https://en.cppreference.com/w/cpp/language/reference
- https://en.cppreference.com/w/cpp/io/basic_ifstream
- https://en.cppreference.com/w/cpp/language/pointer#Pointers_to_members
- https://www.learncpp.com/cpp-tutorial/member-selection-with-pointers-and-references/
- https://www.learncpp.com/cpp-tutorial/introduction-to-file-streams/
- https://www.learncpp.com/cpp-tutorial/switch-statement-basics/

---

<div align="center">

© 2026 Nabila C. All rights reserved.

</div>
