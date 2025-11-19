#include "PhoneBook.hpp"

/**
 * @brief Construct a new Phone Book:: Phone Book object.
 * Sets the current index in the array of contacts to 0.
 */
PhoneBook::PhoneBook()
{
	this->current_index = 0;
}

PhoneBook::~PhoneBook()
{
	
}

/**
 * @brief 
 * 
 * @param category 
 * @param data 
 */
void	print_index_view(std::string category, std::string data)
{
    std::cout << BLUE << std::left << std::setw(18) << category 
    		<< ": " << RESET << data << std::endl;
}

/**
 * @brief displays the PhoneBook categories respecting the 10 char wide columns,
 * pipe character separating them and the text being right alligned.
 * 
 * Use of the std setfill and setw functions for output from the iomanip library
 * in C++.
 * 
 */
void	PhoneBook::print_phone_register()
{
	size_t	temp_index;
	
	std::cout << RED <<  "\n        " << HEART << ' ' << HEART << ' ' << "MY LOVELY PHONEBOOK" << ' ' << HEART << ' ' << HEART  << RESET << std::endl;
	print_decorations();
	std::cout << '\n';
	for (temp_index = 0; temp_index < 8; temp_index++)
	{
		std::cout << std::setfill(' ') << std::setw(10);
		std::cout << BLUE << temp_index + 1 << '|' << RESET;
		print_one_column(this->contact_register[temp_index].get_first_name(), true);
		print_one_column(this->contact_register[temp_index].get_last_name(), true);
		print_one_column(this->contact_register[temp_index].get_nickname(), false);
	}
	print_decorations();
}

void	PhoneBook::print_contact(int	index)
{
	index += -1;

	std::cout << "\n" << std::endl;
	print_index_view("First name", contact_register[index].get_first_name());
	print_index_view("Last name", contact_register[index].get_last_name());
	print_index_view("Nickname", contact_register[index].get_nickname());
	print_index_view("Phone number", contact_register[index].get_phone_number());
	print_index_view("Darkest secret", contact_register[index].get_darkest_secret());
}

int	PhoneBook::contact_found_at_index(int index)
{
	if (contact_register[index - 1].get_first_name().empty())
		return (false);
	print_contact(index);
	return (true);
}

/**
 * @brief Displays the phonebook and prompts user to select a contact by index
 * 
 * This function enters an interactive loop where it:
 * 
 * 1. Displays all stored contacts in a formatted table
 * 
 * 2. Prompts the user to enter a contact index (1-8)
 * 
 * 3. Uses std::getline() to safely read the entire line of input, which:
 *    - Captures the full input including any spaces (preventing input buffer 
 * 	issues where cin stops reding when it encounters a whitespace, which is its delimiter)
 *    - Extracts and discards the newline character automatically
 *    - Allows checking for EOF (Ctrl+D on Unix)
 * 
 * 4. Validates the index is within valid range (1-8)
 * 
 * 5. Verifies a contact exists at the specified index
 * 
 * The function uses getline() instead of operator>> because:
 * 
 * - It prevents leaving newline characters in the input buffer
 * 
 * - It allows proper EOF detection via std::cin.eof()
 * 
 * - It handles malformed input more gracefully (e.g., "3 abc" would be caught)
 * 
 * @return true  If a valid contact was found and displayed successfully
 * @return false If EOF was detected (user wants to exit) or if no contact 
 *               exists at the selected index after initial validation
 * 
 * @note The function loops until valid input is provided or EOF is detected
 * @note Index validation occurs in two stages: range check (1-8) and 
 *       existence check via contact_found_at_index()
 */
bool	PhoneBook::searchContact()
{
	std::string	user_index;

	while (1)
	{
		print_phone_register();
		std::cout << "\n\nSelect contact number :" << std::endl;
		getline(std::cin, user_index);
		if (std::cin.eof())
			return (false);
		int index = std::atoi(user_index.c_str());
		if (index <= 0 || index >= 9)
		{
			std::cout << RED << "\nIndex must be between 1 and 9\n" << RESET << std::endl;
			continue;
		}
		if (contact_found_at_index(index))
			break;
		else
		{
			std::cout << RED << "\nError: No contact at the selected index." << RESET << std::endl;
			return (false);
		}
	}
	return (true);
}

/**
 * @brief Add_contact function which adds the reference of the new contact object to
 * the array of contacts in PhoneBook, and adjusts the current index in 
 * a circular manner using the % operator. 
 * 
 * @param contact (reference to new contact)
 */
void	PhoneBook::add_contact(Contact &contact)
{
	size_t	adjusted_index;
	
	adjusted_index = current_index % 8;
	contact_register[adjusted_index] = contact;
	
	this->current_index++;
	std::cout << GREEN << "\nContact succesfully added." << RESET << std::endl;
}

bool	PhoneBook::is_valid_field_input(std::string prompt, Contact &contact, void (Contact::*set)(std::string), bool is_phone_number, std::string &line)
{
	if (is_valid_input(prompt, is_phone_number, line))
	{
		(contact.*set)(line);
		return (true);
	}
	return (false);
}

bool	PhoneBook::all_contact_details_are_valid(Contact &temp_contact)
{
	std::string	line = "";

	std::cout << BLUE << "\n             CREATE NEW CONTACT             " << RESET << std::endl;
	print_decorations();
	std::cout << '\n';
	if (!is_valid_field_input("Enter first name: ", temp_contact, &Contact::set_first_name, false, line))
		return (false);
	if (!is_valid_field_input("Enter last name: ", temp_contact, &Contact::set_last_name, false, line))
		return (false);
	if (!is_valid_field_input("Enter nickname: ", temp_contact, &Contact::set_nickname, false, line))
		return (false);
	if (!is_valid_field_input("Enter phone number: ", temp_contact, &Contact::set_phone_number, true, line))
		return (false);
	if (!is_valid_field_input("Enter darkest secret: ", temp_contact, &Contact::set_darkest_secret, false, line))
		return (false);
	return (true);
}

bool	PhoneBook::handle_command(std::string command)
{
	Contact	temp_contact;
	
	if (command == "ADD")
	{
		if (this->all_contact_details_are_valid(temp_contact))
			this->add_contact(temp_contact);
	}
	else if (command == "SEARCH")
	{
		if (!searchContact())
			return (false);
	}
	return (true);
}
