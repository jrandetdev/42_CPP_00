# CPP Module 00 - My Learning Journey

**Author:** [Your Name]  
**Date Completed:** [Date]  
**Status:** ✅ Completed

## Introduction

This is my first module in the 42 C++ curriculum. Coming from C, this module was my introduction to object-oriented programming concepts, C++ syntax, and the standard library. This README documents what I learned and how I implemented each exercise.

---

## What I Learned

### Core Concepts

**1. C++ vs C Syntax**
- Using `std::cout` instead of `printf()` for output
- `std::string` class instead of character arrays
- References (`&`) as an alternative to pointers
- The `new`/`delete` operators (though not used in this module)

**2. Namespaces**
- Learned what `std::` means and why we use it
- Understood why `using namespace std;` is bad practice in headers
- How namespaces prevent naming conflicts

**3. Classes and Objects**
- Difference between classes and structs (default access specifiers)
- Public vs private members
- Member functions (methods) and how to call them
- The `this` pointer

**4. Input/Output Streams**
- `std::cout` for standard output
- `std::cin` for standard input
- `std::cerr` for error output
- `std::getline()` for reading full lines with spaces

**5. String Manipulation**
- `std::string` operations: concatenation, length, indexing
- String formatting and alignment
- Converting characters to uppercase/lowercase

---

## Exercise 00: Megaphone

### Implementation Overview

My megaphone program takes command-line arguments and converts them to uppercase.

**How it works:**
1. Checks if arguments were provided (argc > 1)
2. If no arguments: prints "* LOUD AND UNBEARABLE FEEDBACK NOISE *"
3. If arguments exist: concatenates them and converts to uppercase
4. Uses `std::toupper()` for character conversion

**Key Implementation Details:**
```cpp
// I created a separate function to handle string capitalization
std::string capitalise_string(std::string string_to_capitalise)
{
    for (size_t i = 0; i < string_to_capitalise.length(); i++)
        string_to_capitalise[i] = std::toupper(string_to_capitalise[i]);
    return (string_to_capitalise);
}
```

**What I learned:**
- How to use `std::string` for concatenation (no more `strcat`!)
- The `std::toupper()` function from `<cctype>`
- Command-line argument handling in C++
- Passing strings by value creates a copy

**Challenges:**
- Initially tried to use pointer arithmetic like in C
- Learned that `std::string` uses `.length()` not `strlen()`
- Had to remember C++98 doesn't have range-based for loops

**Testing:**
```bash
./megaphone "shhhhh... I think the students are asleep..."
# Output: SHHHHH... I THINK THE STUDENTS ARE ASLEEP...

./megaphone Damnit " ! " "Sorry students, I thought this thing was off."
# Output: DAMNIT ! SORRY STUDENTS, I THOUGHT THIS THING WAS OFF.

./megaphone
# Output: * LOUD AND UNBEARABLE FEEDBACK NOISE *
```

---

## Exercise 01: My Awesome PhoneBook

### Implementation Overview

I created a phonebook application that stores up to 8 contacts with ADD, SEARCH, and EXIT commands.

**Class Structure:**

**Contact Class:**
- Stores individual contact information (first name, last name, nickname, phone, secret)
- Private member variables with public getters/setters
- Handles data validation and formatting

**PhoneBook Class:**
- Manages an array of 8 Contact objects
- Tracks the current number of contacts and oldest contact index
- Implements circular buffer behavior (overwrites oldest when full)
- Handles display formatting with column alignment

**How it works:**
1. Main loop reads commands from user
2. ADD: Prompts for contact info and stores it
3. SEARCH: Displays formatted table, then shows full contact details
4. EXIT: Terminates the program

**Key Implementation Details:**

```cpp
// I used an array to store contacts (no vectors in C++98)
private:
    Contact _contacts[8];
    int     _contactCount;
    int     _oldestIndex;

// Column formatting was tricky - I created a helper function
std::string formatColumn(std::string str, int width)
{
    if (str.length() > width)
        return str.substr(0, width - 1) + ".";
    return str;
}
```

**What I learned:**
- How to design classes with private data and public interfaces
- Encapsulation principles (keeping data private)
- Constructor initialization lists
- Member function implementation outside class definition
- `std::setw()` and `<iomanip>` for formatting output
- `std::getline()` to read input with spaces
- Circular buffer implementation without dynamic allocation

**Challenges:**
- **Column alignment:** Getting the table to display properly with right-aligned columns took time
- **Input validation:** Handling empty strings and ensuring all fields are filled
- **Index management:** Tracking which contact to overwrite when the phonebook is full
- **Const correctness:** Understanding when to use `const` on getter methods
- **String truncation:** Displaying long fields with "..." at 10 characters

**Design Decisions:**
- Separated Contact and PhoneBook into different classes for better organization
- Used private members with public getters/setters (encapsulation)
- Implemented circular buffer with modulo operator for index wrapping
- Created helper functions for formatting to keep code clean

**Testing:**
```bash
# Added 9 contacts to test circular buffer behavior
# Verified oldest contact gets replaced
# Tested search with valid/invalid indices
# Checked column truncation with long names
# Tested empty input handling
```

---

## Exercise 02: The Job Of Your Dreams

### Implementation Overview

This exercise required implementing the `Account` class based on provided header and expected output.

**How it works:**
1. The `Account.hpp` header and `tests.cpp` were provided
2. I had to implement `Account.cpp` to match the exact output in the log file
3. Used static members to track total accounts, deposits, and withdrawals

**Key Implementation Details:**

```cpp
// Static member initialization (outside class)
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

// Timestamp formatting
void Account::_displayTimestamp(void)
{
    time_t now = time(0);
    tm *ltm = localtime(&now);
    std::cout << "[" << 1900 + ltm->tm_year
              << std::setfill('0') << std::setw(2) << 1 + ltm->tm_mon
              << std::setw(2) << ltm->tm_mday << "_"
              << std::setw(2) << ltm->tm_hour
              << std::setw(2) << ltm->tm_min
              << std::setw(2) << ltm->tm_sec << "] ";
}
```

**What I learned:**
- **Static members:** Variables/functions that belong to the class, not individual objects
- **Static member initialization:** Must be done outside the class definition
- **Time formatting:** Using `<ctime>` library for timestamps
- **Output matching:** Precise formatting matters for automated testing
- **Reading logs:** Reverse engineering implementation from expected output
- **Access specifiers:** When to use private vs public

**Challenges:**
- Understanding static member syntax and initialization
- Getting timestamp format exactly right (YYYYMMDD_HHMMSS)
- Figuring out the logic from the log file alone
- Managing static vs instance member interactions
- Using `std::setfill()` and `std::setw()` for zero-padding

**Design Observations:**
- Static members track class-wide state (total accounts, total amount)
- Instance members track per-object state (individual balance, deposits)
- Constructor increments static counters
- Destructor decrements account count
- Private static function for timestamp (implementation detail)

---

## General Learnings

### C++ Philosophy vs C

**C Approach:**
```c
char str[100];
scanf("%s", str);
printf("%s\n", str);
```

**C++ Approach:**
```cpp
std::string str;
std::cin >> str;
std::cout << str << std::endl;
```

**Why C++ is different:**
- More abstraction (strings handle memory for you)
- Object-oriented (everything is an object with methods)
- Type safety (stricter compile-time checking)
- Standard library (rich set of ready-to-use classes)

### Best Practices I Adopted

1. **Use initialization lists in constructors** (more efficient)
2. **Make getters const** (they don't modify the object)
3. **Use `std::endl` instead of `\n`** (flushes buffer)
4. **Private members with underscores** (`_variableName`)
5. **Include guards in headers** (prevent double inclusion)
6. **Const correctness** (use const whenever possible)

### Common Mistakes I Made

1. Forgetting to initialize static members outside the class
2. Using C-style strings instead of `std::string`
3. Not making getter functions const
4. Forgetting the `std::` prefix (never used `using namespace std;`)
5. Trying to use C++11 features (had to stick to C++98)

---

## Compilation

All exercises compile with:
```bash
c++ -Wall -Wextra -Werror -std=c++98 [files] -o [executable]
```

**Makefile structure I used:**
```makefile
NAME = program
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = file1.cpp file2.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
```

---

## Testing Methodology

**Ex00 (Megaphone):**
- ✅ No arguments → loud feedback message
- ✅ Single argument → uppercase conversion
- ✅ Multiple arguments → concatenation and uppercase
- ✅ Arguments with spaces (in quotes) → preserved in output

**Ex01 (PhoneBook):**
- ✅ ADD command with valid input
- ✅ ADD command with empty fields (should reject)
- ✅ SEARCH with 0 contacts → appropriate message
- ✅ SEARCH with valid index → display full contact
- ✅ SEARCH with invalid index → error handling
- ✅ Filling 8 contacts then adding 9th → overwrites oldest
- ✅ Column truncation for long names
- ✅ EXIT command → clean termination
- ✅ Memory leaks check with valgrind

**Ex02 (Account):**
- ✅ Output matches provided log file exactly (except timestamps)
- ✅ Static member tracking is correct
- ✅ All member functions implemented
- ✅ Constructor/destructor output matches

**Valgrind Check:**
```bash
valgrind --leak-check=full ./phonebook
# Result: All heap blocks were freed -- no leaks are possible
```

---

## Reflection

**What surprised me:**
- How much easier string handling is in C++ compared to C
- The power of encapsulation and data hiding
- Static members are actually really useful
- C++ streams are more intuitive than printf/scanf

**What was difficult:**
- Wrapping my head around object-oriented thinking
- Understanding when to use const
- Getting used to the compile errors (different from C)
- Column formatting for the phonebook table

**What I want to improve:**
- Better class design intuition
- More comfortable with const correctness
- Understanding when to pass by reference vs value
- Memory management with new/delete (coming in later modules)

---

## Files Structure

```
cpp00/
├── ex00/
│   ├── Makefile
│   └── megaphone.cpp
├── ex01/
│   ├── Makefile
│   ├── main.cpp
│   ├── PhoneBook.cpp
│   ├── PhoneBook.hpp
│   ├── Contact.cpp
│   └── Contact.hpp
├── ex02/
│   ├── Makefile
│   ├── Account.cpp
│   ├── Account.hpp
│   └── tests.cpp
└── README.md (this file)
```

---

## Conclusion

CPP Module 00 was a solid introduction to C++ fundamentals. I now understand the basics of OOP, classes, namespaces, and the C++ standard library. The transition from C's procedural style to C++'s object-oriented approach required a mental shift, but I can see the benefits of encapsulation and abstraction.

**Grade:** [Your Grade]  
**Time Spent:** [Approximate hours]

**Ready for CPP01!** 🚀
