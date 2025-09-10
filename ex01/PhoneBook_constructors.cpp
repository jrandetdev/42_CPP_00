#include "PhoneBook.class.hpp"

PhoneBook::PhoneBook()
{
	this->current_index = 0;
	std::cout << "\nPhonebook: default constructor called" << std::endl;
}

PhoneBook::~PhoneBook()
{
	std::cout << "Phonebook: destructor called" << std::endl;
}
