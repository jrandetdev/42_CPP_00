#include "PhoneBook.hpp"

void	print_decorations()
{
	for (int i = 0; i < 44; i++)
	{
		std::cout << BLUE << '=' << RESET;
	}
}

std::string trunc(std::string str, size_t len)
{
	if (str.size() > len)
		return (str.substr(0, len - 1) + ".");
	return(str);
}

void	print_one_column(std::string s, bool is_vertical_bar)
{
	std::cout << std::setfill(' ') << std::setw(10);
	std::cout << trunc(s, 10);
	is_vertical_bar ? std::cout << BLUE << '|' << RESET : std::cout << BLUE << '|' << RESET << std::endl;
}
