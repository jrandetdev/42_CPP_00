#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

#include <iostream>
#include "Contact.class.hpp"

class PhoneBook{
	public:
		PhoneBook();
		~PhoneBook();
		void	print_phone_register(Contact *contact_register);
	private:
		Contact	contact_register[8];
		size_t	current_index;
}	;

#endif

//possibly an array of strings for the phonebook
//8 contacts maximum
