<p align="center">
  <img src="https://cdn-icons-png.flaticon.com/512/6132/6132222.png" width="70" alt="C++ Logo">
</p>

<h1 align="center">CPP Module 00</h1>

<h3 align="center">
  Classes • Objects • Member Functions • C++ Streams
</h3>

## About

**CPP Module 00** is the first module of the 42 C++ curriculum and the starting point for learning **Object-Oriented Programming (OOP)**.

The module introduces the fundamental differences between C and C++, including namespaces, input and output streams, strings, classes, objects, member functions, encapsulation, and basic class design.

---

## Exercises

| Exercise | Project              | Description                                                                                                                 |
| -------- | -------------------- | --------------------------------------------------------------------------------------------------------------------------- |
| `ex00`   | Megaphone            | Converts command-line arguments to uppercase and prints them using C++ output streams.                                      |
| `ex01`   | My Awesome PhoneBook | Implements an interactive phone book using classes, objects, encapsulation, arrays, input validation, and formatted output. |

---

## Program Overview

```bash
    CPP00
    ├── ex00: Megaphone
    │   ├── Read command-line arguments
    │   ├── Convert characters to uppercase
    │   └── Print the result
    │
    └── ex01: PhoneBook
        ├── ADD a contact
        ├── SEARCH saved contacts
        └── EXIT the application
```

---

## ex00 — Megaphone

The Megaphone program reads command-line arguments and prints every character in uppercase.

When no arguments are provided, it prints a default loud message.

### Example

```bash
./megaphone hello world
```

Output:

```bash
HELLO WORLD
```

Without arguments:

```bash
./megaphone
```

Output:

```bash
* LOUD AND UNBEARABLE FEEDBACK NOISE *
```

---

## ex01 — My Awesome PhoneBook

The PhoneBook exercise implements a small interactive contact-management application.

The program stores a maximum of **8 contacts** inside a fixed-size array. When the phone book is full, adding a new contact replaces the oldest stored contact.

The application accepts three commands:

| Command  | Description                                             |
| -------- | ------------------------------------------------------- |
| `ADD`    | Creates and stores a new contact                        |
| `SEARCH` | Displays the contact table and shows a selected contact |
| `EXIT`   | Closes the program and discards all contacts            |

Each contact contains:

```text
First Name
Last Name
Nickname
Phone Number
Darkest Secret
```

### Features

* Stores up to 8 contacts
* Replaces the oldest contact when full
* Prevents empty contact fields
* Validates phone-number input
* Displays contacts in an aligned table
* Truncates long fields to fit the table
* Searches contacts by index
* Displays complete contact information

---

## PhoneBook Structure

```text
                 ┌────────────────────┐
                 │     PhoneBook      │
                 │                    │
                 │ Contact contacts[8]│
                 │ Current index      │
                 │ Contact count      │
                 └─────────┬──────────┘
                           │
                           │ contains
                           ▼
                 ┌────────────────────┐
                 │      Contact       │
                 │                    │
                 │ First name         │
                 │ Last name          │
                 │ Nickname           │
                 │ Phone number       │
                 │ Darkest secret     │
                 └────────────────────┘
```

The `PhoneBook` class manages the collection, while each `Contact` object stores the information belonging to one person.

### Example

```bash
cd ../ex01
make
./phonebook
```

```bash
=========================================
                 PHONEBOOK
=========================================

Enter a command (ADD, SEARCH, EXIT):

ADD

First Name     : John
Last Name      : Doe
Nickname       : JD
Phone Number   : 123456789
Darkest Secret : Loves pizza

Contact Added

Enter a command (ADD, SEARCH, EXIT):

SEARCH

-----------------------------------------
            PHONEBOOK SEARCH
-----------------------------------------

     Index|First Name| Last Name|  Nickname
--------------------------------------------
         0|      John|       Doe|        JD

Enter index to view contact information: 0

-----------------------------------------
              CONTACT INFO
-----------------------------------------

First Name     : John
Last Name      : Doe
Nickname       : JD
Phone Number   : 123456789
Darkest Secret : Loves pizza
```

The exact formatting may vary depending on the implementation.

---

## Concepts

<details>
<summary><strong>Namespaces</strong></summary>

---

Namespaces group related identifiers and help prevent naming conflicts.

Components from the C++ Standard Library belong to the `std` namespace.

```cpp
std::cout << "Hello, World!" << std::endl;
```

Here:

* `std::cout` represents the standard output stream.
* `std::endl` inserts a newline and flushes the stream.

Using the namespace prefix makes it clear that these components belong to the C++ Standard Library.

</details>

<details>
<summary><strong>Input and Output Streams</strong></summary>

---

C++ uses streams for console input and output.

```cpp
std::cout << "Enter your name: ";
std::getline(std::cin, name);
```

Common streams include:

| Stream      | Purpose         |
| ----------- | --------------- |
| `std::cout` | Standard output |
| `std::cin`  | Standard input  |
| `std::cerr` | Error output    |

Unlike C functions such as `printf` and `scanf`, C++ streams are type-aware and work naturally with objects such as `std::string`.

</details>

<details>
<summary><strong>Command-Line Arguments</strong></summary>

---

Command-line arguments allow information to be passed to a program when it starts.

```cpp
int main(int argc, char **argv)
{
}
```

* `argc` contains the number of arguments.
* `argv` contains the arguments as strings.
* `argv[0]` contains the executable name.
* User-provided arguments begin at `argv[1]`.

Example:

```bash
./megaphone hello world
```

The argument array contains:

```text
argv[0] = "./megaphone"
argv[1] = "hello"
argv[2] = "world"
```

</details>

<details>
<summary><strong>Character Conversion</strong></summary>

---

The Megaphone program converts lowercase characters to uppercase before printing them.

A character can be converted with `std::toupper`:

```cpp
char uppercase = std::toupper(character);
```

Character functions are provided by the `<cctype>` header.

The character should be converted safely through `unsigned char` when necessary:

```cpp
std::toupper(static_cast<unsigned char>(character));
```

</details>

<details>
<summary><strong>Classes and Objects</strong></summary>

---

A class defines a custom type that groups data and behaviour.

```cpp
class Contact
{
private:
    std::string firstName;

public:
    void setFirstName(const std::string& value);
    std::string getFirstName() const;
};
```

An object is an instance of a class:

```cpp
Contact contact;
```

The class describes what a contact contains and what it can do. The object represents one actual contact stored by the application.

</details>

<details>
<summary><strong>Encapsulation</strong></summary>

---

Encapsulation protects an object's internal state by keeping its attributes private.

```cpp
class Contact
{
private:
    std::string phoneNumber;

public:
    void setPhoneNumber(const std::string& value);
    std::string getPhoneNumber() const;
};
```

Outside code cannot directly modify `phoneNumber`.

Instead, the class provides public member functions that control how the value is accessed or changed.

This keeps the object's data organized and reduces accidental misuse.

</details>

<details>
<summary><strong>Access Specifiers</strong></summary>

---

Access specifiers determine where class members can be accessed.

```cpp
class Contact
{
private:
    std::string firstName;

public:
    void setFirstName(const std::string& value);
};
```

| Specifier   | Accessibility                                   |
| ----------- | ----------------------------------------------- |
| `private`   | Accessible only from inside the class           |
| `public`    | Accessible from outside the class               |
| `protected` | Accessible inside the class and derived classes |

CPP00 mainly uses `private` attributes and `public` member functions.

</details>

<details>
<summary><strong>Member Functions</strong></summary>

---

Member functions define the behaviour of a class.

```cpp
void Contact::setFirstName(const std::string& value)
{
    firstName = value;
}
```

The `Contact::` prefix indicates that the function belongs to the `Contact` class.

Member functions can access the private attributes of their own object.

```cpp
contact.setFirstName("John");
```

</details>

<details>
<summary><strong>Getters and Setters</strong></summary>

---

Getters and setters provide controlled access to private attributes.

A setter updates a value:

```cpp
void Contact::setNickname(const std::string& value)
{
    nickname = value;
}
```

A getter returns a value:

```cpp
std::string Contact::getNickname() const
{
    return nickname;
}
```

The `const` keyword indicates that the getter does not modify the object.

</details>

<details>
<summary><strong>Constructors and Destructors</strong></summary>

---

A constructor initializes an object when it is created.

```cpp
Contact::Contact()
{
}
```

A destructor runs automatically when an object is destroyed.

```cpp
Contact::~Contact()
{
}
```

Their names match the class name, while the destructor begins with `~`.

```cpp
Contact contact;
```

When `contact` is created, its constructor runs. When it leaves scope, its destructor runs automatically.

</details>

<details>
<summary><strong>Arrays of Objects</strong></summary>

---

The PhoneBook stores multiple `Contact` objects inside a fixed-size array.

```cpp
Contact contacts[8];
```

Each element is a complete `Contact` object.

```text
contacts[0]
contacts[1]
contacts[2]
...
contacts[7]
```

This allows the application to store exactly eight contacts without dynamic memory allocation.

</details>

<details>
<summary><strong>Circular Replacement</strong></summary>

---

When the PhoneBook reaches its eight-contact limit, new contacts replace the oldest entries.

The insertion index can be updated using modulo:

```cpp
index = (index + 1) % 8;
```

The index moves through the array like this:

```text
0 → 1 → 2 → 3 → 4 → 5 → 6 → 7 → 0
```

This creates a circular buffer without shifting the entire array.

</details>

<details>
<summary><strong>String Input with std::getline</strong></summary>

---

`std::getline` reads an entire line, including spaces.

```cpp
std::getline(std::cin, input);
```

This is important for contact fields such as:

```text
Mary Jane
Loves pineapple pizza
```

Using `std::cin >> input` would stop reading at the first space, while `std::getline` captures the complete value.

</details>

<details>
<summary><strong>Input Validation</strong></summary>

---

Input validation ensures that saved contact information follows the program's rules.

For example, an empty field can be rejected:

```cpp
if (input.empty())
{
    std::cout << "Field cannot be empty." << std::endl;
}
```

Phone numbers can be checked character by character:

```cpp
for (std::size_t i = 0; i < phoneNumber.length(); ++i)
{
    if (!std::isdigit(phoneNumber[i]))
        return false;
}
```

Validation prevents incomplete or malformed contacts from being stored.

</details>

<details>
<summary><strong>Formatted Output</strong></summary>

---

The PhoneBook search table uses `<iomanip>` manipulators to align its columns.

```cpp
std::cout << std::setw(10) << value;
```

Each field is displayed using a width of ten characters.

```text
     Index|First Name| Last Name|  Nickname
         0|      John|       Doe|        JD
```

If a value is longer than ten characters, it is shortened and its final displayed character is replaced with a period.

```text
Alexand...
```

This keeps the table aligned and readable.

</details>

<details>
<summary><strong>const Member Functions</strong></summary>

---

A member function marked with `const` promises not to modify the object.

```cpp
std::string Contact::getFirstName() const
{
    return firstName;
}
```

This allows the function to be called on constant objects and clearly communicates that it only reads data.

</details>

<details>
<summary><strong>Header and Source Separation</strong></summary>

---

Class declarations are placed in header files:

```text
contact.hpp
phonebook.hpp
```

Member-function implementations are placed in source files:

```text
contact.cpp
phonebook.cpp
```

Example declaration:

```cpp
class PhoneBook
{
public:
    void addContact();
    void searchContact();
};
```

Example implementation:

```cpp
void PhoneBook::addContact()
{
}
```

Separating declarations from implementations improves organization, readability, and maintainability.

</details>

<details>
<summary><strong>Header Guards</strong></summary>

---

Header guards prevent the same header file from being included more than once.

```cpp
#ifndef CONTACT_HPP
#define CONTACT_HPP

class Contact
{
};

#endif
```

Without header guards, repeated inclusions could cause redefinition errors.

</details>

---

## What I Learned

* Understanding the basic structure of a C++ program
* Using namespaces and Standard Library components
* Working with `std::cout`, `std::cin`, and `std::getline`
* Reading and processing command-line arguments
* Manipulating characters and strings
* Creating classes and objects
* Separating private data from public behaviour
* Implementing constructors and destructors
* Writing getters, setters, and member functions
* Storing objects inside fixed-size arrays
* Managing a circular replacement index
* Validating terminal input
* Formatting table output with `std::setw`
* Separating class declarations and implementations

---

## Resources

* [C++ Classes and Objects](https://www.geeksforgeeks.org/cpp/c-classes-and-objects/)
* [Object-Oriented Programming in C++](https://www.geeksforgeeks.org/cpp/object-oriented-programming-in-cpp/)
* [C++ Input and Output](https://cplusplus.com/doc/tutorial/basic_io/)
* [std::string](https://cplusplus.com/reference/string/string/)
* [std::getline](https://cplusplus.com/reference/string/string/getline/)
* [std::toupper](https://cplusplus.com/reference/cctype/toupper/)
* [std::setw](https://cplusplus.com/reference/iomanip/setw/)
* [Header Guards](https://www.learncpp.com/cpp-tutorial/header-guards/)
* [Learn C++](https://www.learncpp.com/)

---

<div align="center">


© 2026 Nabila C. All rights reserved.

</div>

