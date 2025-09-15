#include "PhoneBook.hpp"

static void	print_instructions();
static	bool is_valid_command(std::string command);

int main(int argc, char **argv)
{
	(void)argv;
	std::string command;
	PhoneBook	phonebook;

	if (argc > 1)
		std::cout << "Error: Program takes no arguments." << std::endl;

	while (1)
	{
		if (std::cin.eof())
		{
			std::cout << RED << "\nError: EOF detected, quiting program.\n" << RESET << std::endl;
			break;
		}
		print_instructions();
		getline(std::cin, command);
		if (is_valid_command(command) && command == "EXIT")
		{
			std::cout << GREEN << "\nEXIT: deleting all entries and shutting down program ...\n" << RESET << std::endl;
			break;
		}
		phonebook.handle_command(command);
	}
	return (0);
}

static void	print_instructions()
{

	std::cout << BLUE << "\n                 MAIN MENU                 " << RESET << std::endl;
	print_decorations();
	std::cout << BLUE << "\n\nPlease type one of the following 3 commands:\n" << RESET;
	std::cout << BLUE << "- 'ADD' (to add a contact)\n" << RESET;
	std::cout << BLUE << "- 'SEARCH' (to search a contact)\n" << RESET;
	std::cout << BLUE << "- 'EXIT' (to exit the program)\n\n" << RESET;
}

static	bool is_valid_command(std::string command)
{
	return (command == "ADD" || command == "SEARCH" || command == "EXIT");
}

