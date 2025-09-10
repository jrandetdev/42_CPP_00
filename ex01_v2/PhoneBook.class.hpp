#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

#include <iostream>
#include "Contact.class.hpp"

class PhoneBook{
	public:
		PhoneBook();
		~PhoneBook();
		
		void	get_and_add_contact_to_phonebook(PhoneBook phonebook);
		Contact	fill_contact_fields();
		void	add_contact_to_register(Contact &contact);
		void	print_phone_register(Contact *contact_register);
		
	private:
		Contact	contact_register[8];
		size_t	current_index;
}	;

#endif

//possibly an array of strings for the phonebook
//8 contacts maximum
