#include "PhoneBook.class.hpp"

// Constructor and Destruction functions for Contact Class

Contact::Contact() : first_name(""), last_name(""), nickname(""), phone_number(""), darkest_secret("")
{
	std::cout << "Contact: Default constructor called" << std::endl;
}

Contact::~Contact()
{
	std::cout << "Contact: Destructor called" << std::endl;
}
