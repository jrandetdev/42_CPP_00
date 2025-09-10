#include "PhoneBook.class.hpp"

void	print_prompt(void);

int main(int argc, char **argv)
{
	(void)argv;
	PhoneBook	phonebook;
	std::string command;
	Contact		temp_contact;

	if (argc > 1)
		return (1);

	while (1)
	{
		print_prompt();
		getline(std::cin, command);
		if (std::cin.eof())
		{
			std::cout << RED << '\n' << "Error: EOF detected, exiting program.\n" << RESET << std::endl;
			break ;
		}
		if (command == "ADD")
		{
			if (!phonebook.get_contact(temp_contact))
				break ;
			phonebook.add_contact(temp_contact);
		}
		else if (command == "SEARCH")
			phonebook.print_phone_register();
		else if (command == "EXIT")
		{
			std::cout << "\nEXIT: deleting all entries and shutting down program ...\n" << std::endl;
			break ;
		}
	}
	return (0);
}

void	print_prompt(void)
{
	std::cout << BLUE << "\nPlease type one of the following 3 commands:\n" << RESET;
	std::cout << BLUE << "- 'ADD' (to add a contact)\n" << RESET;
	std::cout << BLUE << "- 'SEARCH' (to search a contact)\n" << RESET;
	std::cout << BLUE << "- 'EXIT' (to exit the program and erase all contacts)\n\n" << RESET;
}
