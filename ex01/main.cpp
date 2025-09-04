#include "Contact.class.hpp"
#include "PhoneBook.class.hpp" //maybe it might not be used here.

std::string	parse_and_get_user_command(void);
void		save_new_contact(void);
void		display_contact(void);

int main(int argc, char **argv)
{
	(void)argv;
	std::string command;

	if (argc > 1)
		return (1);
	
	while (command != "EXIT")
	{
		command = parse_and_get_user_command();
		if (command == "ADD")
			save_new_contact();
		else if (command == "SEARCH")
			display_contact();
	}
	
	return (0);
}

std::string	parse_and_get_user_command(void)
{
	std::string command;
	
	std::cout << "Please type one of the following 3 commands:\n";
	std::cout << "- 'ADD' (to add a contact)\n";
	std::cout << "- 'SEARCH' (to search a contact)\n";
	std::cout << "- 'EXIT' (to exit the program and erase all contacts)\n\n";
	std::cin >> command;

	while (command != "ADD" && command != "SEARCH" && command != "EXIT")
		std::cin >> command;

	return (command);
}

void	save_new_contact(void)
{
	std::cout << "inside save new contact\n" << std::endl;
}

void	display_contact(void)
{
	std::cout << "inside display contact\n" << std::endl;
}
