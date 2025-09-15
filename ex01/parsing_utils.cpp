#include "PhoneBook.hpp"

bool	validateInput(std::string &s, bool is_numeric);

bool	is_valid_input(std::string prompt, bool is_phone_number, std::string &line)
{
	while (1)
	{
		std::cout << YELLOW << '\n' << prompt << RESET << std::endl;
		getline(std::cin, line);
		if (std::cin.eof())
			break;
		else if (validateInput(line, is_phone_number))
			return (true);
	}
	return (false);
}

bool	validateInput(std::string &s, bool is_numeric)
{
	if (s.empty())
	{
		std::cout << RED << "\nError: Contact fields cannot be empty." << RESET << std::endl;
		return (false);
	}

	for (std::string::iterator it = s.begin(); it != s.end(); ++it)
	{
		if (is_numeric)
		{
			if (!isdigit(*it) && (*it != '+'))
			{
				std::cout << RED << "\nError: input can only contain numbers or the character '+'." << RESET << std::endl;
				return (false);
			}
		}
		else if (!isalpha(*it) && !isspace(*it))
		{
			std::cout << RED << "\nError: input can only contain letters or spaces." << RESET << std::endl;
			return (false);
		}
	}
	return (true);
}
