#include <iostream>
#include "PhoneBook.class.hpp"

bool	validate_input(std::string &s, bool is_numeric);

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

bool	validate_input(std::string &s, bool is_numeric)
{
	if (s.empty())
	{
		std::cout << RED << "\nError: Contact fields cannot be empty." << RESET << std::endl;
		return (false);
	}

	std::string::iterator it;

	for (it = s.begin(); it != s.end(); ++it)
	{
		if (is_numeric)
		{
			if (!isdigit(*it) && (*it != '+'))
			{
				std::cout << RED << "\nError: input can only contain numbers or the character '+'." << RESET << std::endl;
				return (false);
			}
		}
		else if (!isalpha(*it))
		{
			std::cout << RED << "\nError: input can only contain letters." << RESET << std::endl;
			return (false);
		}
	}
	return (true);
}