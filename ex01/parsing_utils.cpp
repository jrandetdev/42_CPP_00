#include <iostream>
#include "PhoneBook.class.hpp"

bool	validate_input(std::string &name, bool is_phone_number)
{
	//preliminary check to see if length is 0 or not
	if (name.empty())
	{
		std::cout << "Error: Contact fields cannot be empty." << std::endl;
		return (false); // if length is non existant exit early
	}

	// prepare the iterator for the for loop
	std::string::iterator it;

	for (it = name.begin(); it != name.end(); ++it)
	{
		if (is_phone_number)
		{
			if (!isdigit(*it) && (*it != '+'))
			{
				std::cout << "Error: input can only contain numbers or the character '+'." << std::endl;
				return (false);
			}
		}
		else if (!isalpha(*it))
		{
			std::cout << "Error: input can only contain letters." << std::endl;
			return (false);
		}
	}
	return (true);
}

std::string	parse_input(std::string prompt, bool is_phone_number)
{
	std::string line = "";

	std::cout << prompt << std::endl;

	std::cout << "inside parse input" << std::endl;
	while (1)
	{
		getline(std::cin, line);
		if (std::cin.eof())
		{
			std::cout << "Error: EOF detected, exiting program." << std::endl;
			break ;
		}
		if (validate_input(line, is_phone_number))
		{
			return (line);
		}
		else
		{
			std::cout << prompt << std::endl;
		}
	}
	return (NULL);
}
