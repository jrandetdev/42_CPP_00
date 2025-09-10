#include "PhoneBook.class.hpp"

void	PhoneBook::add_contact_to_register(Contact &contact)
{
	size_t	adjusted_index;

	adjusted_index = current_index % 8;
	std::cout << "adjusted index is" << adjusted_index << std::endl;
	contact_register[adjusted_index] = contact;

	std::cout << "\nContact succesfully added." << std::endl;
}

Contact	PhoneBook::fill_contact_fields()
{
	Contact		contact;
	std::string	line = "";

	line = parse_input("\nEnter first name: ", false);
	if (line.empty())
		return (NULL);
	contact.set_first_name(line);

	line = parse_input("\nEnter last name: ", false);
	contact.set_last_name(line);

	// line = parse_input("\nEnter nickname: ", false);
	// contact.set_nickname(line);

	// line = parse_input("\nEnter phone number: ", true);
	// contact.set_phone_number(line);

	// line = parse_input("\nEnter darkest secret: ", false);
	// contact.set_darkest_secret(line);

	return (contact);
}

void	PhoneBook::get_and_add_contact_to_phonebook()
{
	Contact filled_contact;

	filled_contact = *(this->fill_contact_fields());
	this->add_contact_to_register(filled_contact);

	current_index++; // once the contact has been filled and added, then the current index is incremented 
	// std::cout << "\nfirst name of contact 1 is " << this->contact_register[0].get_first_name() << std::endl;
	// std::cout << "first name of contact 2 is " << this->contact_register[1].get_first_name() << std::endl;
	// std::cout << "first name of contact 3 is " << this->contact_register[2].get_first_name() << std::endl;
	// std::cout << "first name of contact 4 is " << this->contact_register[3].get_first_name() << std::endl;
	// std::cout << "first name of contact 5 is " << this->contact_register[4].get_first_name() << std::endl;
	// std::cout << "first name of contact 6 is " << this->contact_register[5].get_first_name() << std::endl;
	// std::cout << "first name of contact 7 is " << this->contact_register[6].get_first_name() << std::endl;
	// std::cout << "first name of contact 8 is " << this->contact_register[7].get_first_name() << std::endl;
	// std::cout << "first name of contact 1 is " << this->contact_register[0].get_first_name() << std::endl;
}
