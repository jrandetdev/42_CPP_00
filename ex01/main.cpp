#include "Contact.class.hpp"
#include "PhoneBook.class.hpp" //maybe it might not be used here.

void	print_prompt(void);
void	search_new_contact(PhoneBook &phonebook);

int main(int argc, char **argv)
{
	(void)argv;
	PhoneBook	phonebook;
	std::string command;

	if (argc > 1)
		return (1);

	print_prompt();
	while (getline(std::cin, command)) //automatically checks for eof becaude 
	{
		if (command == "ADD")
			phonebook.get_and_add_contact_to_phonebook(phonebook);
		else if (command == "SEARCH")
			search_new_contact(phonebook);
		else if (command == "EXIT")
		{
			std::cout << "\nEXIT: deleting all entries and shutting down program ..." << std::endl;
			break ;
		}
		print_prompt();
	}
	return (0);
}

void	print_prompt(void)
{
	std::cout << "\nPlease type one of the following 3 commands:\n";
	std::cout << "- 'ADD' (to add a contact)\n";
	std::cout << "- 'SEARCH' (to search a contact)\n";
	std::cout << "- 'EXIT' (to exit the program and erase all contacts)\n\n";
}

void	search_new_contact(PhoneBook &phonebook)
{
	(void)phonebook;
	std::cout << "inside search contact" << std::endl;
}
