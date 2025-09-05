#include "PhoneBook.class.hpp"
#include "Contact.class.hpp"

PhoneBook::PhoneBook()
{
	this->current_index = 0;
	std::cout << "Phonebook: default constructor called" << std::endl;
}

PhoneBook::~PhoneBook()
{
	std::cout << "Destructor called" << std::endl;
}

void	PhoneBook::print_phone_register(Contact *contact_register)
{
	(void)contact_register;
	std::cout << "print phone register called" << std::endl;
}
