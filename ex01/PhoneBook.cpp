#include "PhoneBook.class.hpp"

void	print_one_column(std::string s, bool is_vertical_bar);

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
	std::cout << GREEN << "\nContact succesfully added." << RESET << std::endl;
}

void	PhoneBook::search_contact()
{
	std::string input = "";
	
	print_phone_register();
	std::cout << "Which contact would you like to display? (Please input the desired index from 0-9)" << std::endl;
	while (1)
	{
		getline(std::cin, input);
		if (input.length() > 1 || !isdigit(input[0]))
		{
			std::cout << RED << "Error: index must be a numerical value between 0 and 9\n" << RESET << std::endl;
		}
		std::cout << "digit is valid!" << std::endl;
	}
}

void	PhoneBook::print_phone_register()
{
	for (current_index = 0; current_index < 8; current_index++)
	{
		std::cout << std::setfill(' ') << std::setw(10);
		std::cout << current_index << '|';
		print_one_column(this->contact_register[current_index].get_first_name(), true);
		print_one_column(this->contact_register[current_index].get_last_name(), true);
		print_one_column(this->contact_register[current_index].get_nickname(), false);
	}
}
std::string trunc(std::string str, size_t len)
{
	if (str.length() > len)
		return (str.substr(0, len - 1) + ".");
	return(str);
}
void	print_one_column(std::string s, bool is_vertical_bar)
{
	std::cout << std::setfill(' ') << std::setw(10);
	std::cout << trunc(s, 10);
	is_vertical_bar ? std::cout << '|' : std::cout << std::endl;
}
