#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP

#include <string>

/**
 * a constructor is a special method that is automatically
 * calles when an object is instantiated. It is useful to
 * instantiate members.
 */
class Contact{
	public:
		Contact();//contrcutor
		~Contact();//destructor

		void				set_first_name(std::string s);
		const std::string	&get_first_name(void) const;

		void				set_last_name(std::string s);
		const std::string	&get_last_name(void) const;

		void				set_nickname(std::string s);
		const std::string	&get_nickname(void) const;

		void				set_phone_number(std::string s);
		const std::string	&get_phone_number(void) const;

		void				set_darkest_secret(std::string s);
		const std::string	&get_darkest_secret(void) const;

	//Encapsulation: used to make sure that sensitive data is hidden from users
	//to access or modify the private members, we need to use get and set methods
	private:
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phone_number;
		std::string darkest_secret;
};

std::string	parse_input(std::string prompt, bool is_phone_number);

#endif
