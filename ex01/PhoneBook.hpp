#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP


#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include "Contact.hpp"

#define RED     "\033[31m"      /* Red */
#define YELLOW  "\033[33m"      /* Yellow */
#define GREEN   "\033[32m"      /* Green */
#define BLUE    "\033[34m"      /* Blue */
#define RESET   "\033[0m"		/* Reset */
#define HEART   "\xE2\x99\xA5"	/* Heart */

class PhoneBook{
	public:
		PhoneBook();
		~PhoneBook();
		
	bool	handle_command(std::string command);
	bool	all_contact_details_are_valid(Contact &temp_contact);
	void	add_contact(Contact &contact);
	bool	is_valid_field_input(std::string prompt, Contact &contact, void (Contact::*set)(std::string), bool is_phone_number, std::string &line);
	bool	searchContact();
	void	print_contact(int index);
	int		contact_found_at_index(int index);
	void	print_phone_register();

	private:
		Contact	contact_register[8];
		size_t	current_index;
}	;

bool	is_valid_input(std::string prompt, bool is_phone_number, std::string &line);
void	print_one_column(std::string s, bool is_vertical_bar);
void	print_decorations();

#endif