#include <iostream>
#include "PhoneBook.class.hpp"

bool	validate_input(std::string &name, bool is_phone_number)
{
	if (name.empty())
	{
		std::cout << "Error: Contact fields cannot be empty." << std::endl;
		return (false);
	}

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

bool	parse_input(std::string prompt, bool is_phone_number, std::string &line)
{
	while (1)
	{
		std::cout << '\n' << prompt << std::endl;
		getline(std::cin, line);
		if (std::cin.eof())
		{
			std::cout << RED << '\n' << "Error: EOF detected, exiting program." << RESET << std::endl;
			break ;
		}
		else if (validate_input(line, is_phone_number))
		{
			return (true);
		}
	}
	return (false);
}
