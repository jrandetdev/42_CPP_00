#include "PhoneBook.class.hpp"

//Constructor and destructor

PhoneBook::PhoneBook()
{
	this->current_index = 0;
	std::cout << GREEN << "\nPhonebook: default constructor called\n" << RESET << std::endl;
}

PhoneBook::~PhoneBook()
{
	std::cout << GREEN << "\nPhonebook: destructor called\n" << RESET << std::endl;
}

bool	PhoneBook::get_contact(Contact &temp_contact)
{
	std::string	line = "";

	if (!parse_input("Enter first name: ", false, line))
		return (false);
	temp_contact.set_first_name(line);

	if (!parse_input("Enter last name: ", false, line))
		return (false);
	temp_contact.set_last_name(line);

	if (!parse_input("Enter nickname: ", false, line))
		return (false);
	temp_contact.set_nickname(line);

	if (!parse_input("Enter phone number: ", true, line))
		return (false);
	temp_contact.set_phone_number(line);

	if (!parse_input("Enter darkest secret: ", false, line))
		return (false);
	temp_contact.set_darkest_secret(line);

	return (true);
}

void	PhoneBook::add_contact(Contact &contact)
{
	size_t	adjusted_index;

	adjusted_index = current_index % 8;
	std::cout << "adjusted index is" << adjusted_index << std::endl;
	contact_register[adjusted_index] = contact;

	this->current_index++;
	std::cout << "\nContact succesfully added." << std::endl;
}

void	PhoneBook::print_phone_register()
{
	for (current_index = 0; current_index < 8; current_index++)
	{
		std::cout << this->contact_register[current_index].get_first_name() << "|" << this->contact_register[current_index].get_last_name() << std::endl;
	}
}
