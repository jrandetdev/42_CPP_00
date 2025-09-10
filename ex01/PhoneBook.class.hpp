#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

#include <iostream>
#include <iomanip>
// #include <iosfwd>
#include "Contact.class.hpp"


#define RED     "\033[31m"      /* Red */
#define YELLOW  "\033[33m"      /* Yellow */
#define GREEN   "\033[32m"      /* Green */
#define BLUE    "\033[34m"      /* Blue */
#define RESET   "\033[0m"		/* Reset */

class PhoneBook{
	public:
		PhoneBook();
		~PhoneBook();
		
		bool	get_contact(Contact &temp_contact);
		void	add_contact(Contact &contact);
		void	search_contact();
		void	print_phone_register();
		
	private:
		Contact	contact_register[8];
		size_t	current_index;
}	;

#endif

//possibly an array of strings for the phonebook
//8 contacts maximum
