# CPP Module 00

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
- Difference between classes and structs (default access specifiers) (class is private and public, struct is only public).
- Public vs private members
- Member functions (methods) and how to call them
- The `this` pointer

**4. Input/Output Streams**
- `std::cout` for standard output
- `std::cin` for standard input
- `std::cerr` for error output
- `std::getline()` for reading full lines with spaces intead of cin which stops at whitespace delimiters

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
- How to use `std::string` for concatenation (no more `ft_strcat`!)
- The `std::toupper()` function from `<cctype>`
- Command-line argument handling in C++
- Passing strings by value creates a copy

**Challenges:**
- Learning about the string class `std::string`, which uses `.length()` not `strlen()`

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

**Contact Class:**
- see Contact.hpp and Contact.cpp
- Stores individual contact information (first name, last name, nickname, phone, secret)
- Private member variables with public getters/setters (introduction to const as well as the use of references for string getters)
- Handles data validation and formatting

**Contact Class Implementation:**
**Class Structure:**

```cpp
class Contact{
	public:
		Contact();
		~Contact();

		void				set_first_name(std::string s);
		const std::string	&get_first_name(void) const;

		void				set_last_name(std::string s);
		const std::string	&get_last_name(void) const;

		void				set_nickname(std::string s);
		const std::string	&get_nickname(void) const;

		void				set_phone_number(std::string s);
		const std::string	&get_phone_number(void) const;

		void				set_darkest_secret(std::string s);
		const std::string	&get_darkest_secret(void) const;

	private:
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phone_number;
		std::string darkest_secret;
};
```

**PhoneBook Class:**
- Manages an array of 8 Contact objects
- Tracks the current number of contacts and oldest contact index, index set to 0 in constructor
- Implements circular buffer behavior (overwrites oldest when full)
- Handles display formatting with column alignment

**PhoneBook Class Implementation:**
```cpp
class PhoneBook{
	public:
		PhoneBook();
		~PhoneBook();
		
	bool	handle_command(std::string command);
	bool	all_contact_details_are_valid(Contact &temp_contact);
	void	add_contact(Contact &contact);
	bool	is_valid_field_input(std::string prompt, Contact &contact, void (Contact::*set)(std::string), bool is_phone_number, std::string &line);
	bool	searchContact();
	void	print_contact(int index);
	int		contact_found_at_index(int index);
	void	print_phone_register();

	private:
		Contact	contact_register[8];
		size_t	current_index;
}	;
```

**How it works:**
1. Main loop reads commands from user
2. ADD: Prompts for contact info and stores it
3. SEARCH: Displays formatted table, then shows full contact details
4. EXIT: Terminates the program

**What I learned:**
- How to design classes with private data and public interfaces
- Encapsulation principles (keeping data private)
- Constructors and Destructors and how they behave
- Constructor initialization lists
- Member function implementation outside class definition
- `std::setw()` and `<iomanip>` for formatting output
- `std::getline()` to read input with spaces and using the .eof() check 
- Circular buffer implementation without dynamic allocation

**Challenges:**
- **Column alignment:** Getting the table to display properly with right-aligned columns took time
- **Input validation:** Handling empty strings and ensuring all fields are filled
- **Index management:** Tracking which contact to overwrite when the phonebook is full
- **Const correctness:** Understanding when to use `const` on getter methods
- **String truncation:** Displaying long fields with "..." at 10 characters
- **References to strings:** Learned what references are and their alias properties, as well as the advantages of using references to avoid copying strings which is resource heavy.

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
3. **Use `std::endl` instead of `\n`** (flushes buffer) at the end of the program
4. **Include guards in headers** (prevent double inclusion)
5. **Const correctness** (use const whenever possible)

---

## Compilation

use make

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

**Valgrind Check:**
```bash
valgrind --leak-check=full ./phonebook
# Result: All heap blocks were freed -- no leaks are possible
```

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
