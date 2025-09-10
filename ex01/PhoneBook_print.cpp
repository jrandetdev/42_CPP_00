#include "PhoneBook.class.hpp"

void	PhoneBook::print_phone_register()
{
	for (current_index = 0; current_index < 8; current_index++)
	{
		std::cout << this->contact_register[current_index].get_first_name() << "|" << this->contact_register[current_index].get_last_name() << std::endl;
	}
}
