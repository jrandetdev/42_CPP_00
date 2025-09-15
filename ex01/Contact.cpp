#include "PhoneBook.hpp"
#include "Contact.hpp"

// Constructor and Destruction functions for Contact Class

Contact::Contact() : first_name(""), last_name(""), nickname(""), phone_number(""), darkest_secret("")
{
	
}

Contact::~Contact()
{

}

// Get and set first_name

void	Contact::set_first_name(std::string s)
{
	first_name = s;
}

const std::string	&Contact::get_first_name(void) const
{
	return (this->first_name);
}

// Get and set nickname

void	Contact::set_last_name(std::string s)
{
	last_name = s;
}

const std::string	&Contact::get_last_name(void) const
{
	return (this->last_name);
}

// Get and set last_name

void	Contact::set_nickname(std::string s)
{
	nickname = s;
}

const std::string	&Contact::get_nickname(void) const
{
	return (this->nickname);
}

// Get and set phone number

void	Contact::set_phone_number(std::string s)
{
	phone_number = s;
}

const std::string	&Contact::get_phone_number(void) const
{
	return (this->phone_number);
}

// Getr and set darkest secret

void	Contact::set_darkest_secret(std::string s)
{
	darkest_secret = s;
}

const std::string	&Contact::get_darkest_secret(void) const
{
	return (this->darkest_secret);
}
