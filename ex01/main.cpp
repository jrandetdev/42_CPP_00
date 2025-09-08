#include "Contact.class.hpp"
#include "PhoneBook.class.hpp" //maybe it might not be used here.

void	parse_and_get_user_command(std::string &command);

int main(int argc, char **argv)
{
	(void)argv;
	PhoneBook	phonebook;
	std::string command;

	if (argc > 1)
		return (1);
	while (command != "EXIT")
	{
		parse_and_get_user_command(command);
		std::cout << "command is worth " << command << std::endl;
	}
	return (0);
}

void	parse_and_get_user_command(std::string &command)
{
	//std::string command;
	
	std::cout << "Please type one of the following 3 commands:\n";
	std::cout << "- 'ADD' (to add a contact)\n";
	std::cout << "- 'SEARCH' (to search a contact)\n";
	std::cout << "- 'EXIT' (to exit the program and erase all contacts)\n\n";
	std::cin >> command;

	while (command != "ADD" && command != "SEARCH" && command != "EXIT")
	{
		std::cin >> command;
		if (std::cin.eof())
		{
			std::cout << "Error: EOF detected." << std::endl;
		}
	}
}

void	save_new_contact(PhoneBook &phonebook)
{
	(void)phonebook;
	std::cout << "inside save new contact\n" << std::endl;
}

