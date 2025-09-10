#include "PhoneBook.class.hpp"
#include "Contact.class.hpp"

PhoneBook::PhoneBook()
{
	this->current_index = 1;
	std::cout << "Phonebook: default constructor called" << std::endl;
}

PhoneBook::~PhoneBook()
{
	std::cout << "Phonebook: destructor called" << std::endl;
}

void	PhoneBook::add_contact_to_register(Contact &contact)
{
	size_t	adjusted_index;

	adjusted_index = current_index % 8;
	contact_register[adjusted_index] = contact;

	std::cout << "\nContact succesfully added." << std::endl;

	std::cout << "in add_contact_to_register contact is " << contact_register[adjusted_index].get_first_name() << std::endl;
}

Contact	PhoneBook::fill_contact_fields()
{
	Contact		contact;
	std::string	line = "";

	line = parse_input("\nEnter first name: ", false);
	contact.set_first_name(line);

	line = parse_input("\nEnter last name: ", false);
	contact.set_last_name(line);

	line = parse_input("\nEnter nickname: ", false);
	contact.set_nickname(line);

	line = parse_input("\nEnter phone number: ", true);
	contact.set_phone_number(line);

	line = parse_input("\nEnter darkest secret: ", false);
	contact.set_darkest_secret(line);

	current_index++;
	return (contact);
}

void	PhoneBook::get_and_add_contact_to_phonebook(PhoneBook phonebook)
{
	Contact filled_contact;

	filled_contact = phonebook.fill_contact_fields();
	phonebook.add_contact_to_register(filled_contact);

	std::cout << "contatct is " << filled_contact.get_first_name() << std::endl;
}

void	PhoneBook::print_phone_register(Contact *contact_register)
{
	(void)contact_register;
	std::cout << "print phone register called" << std::endl;
}
