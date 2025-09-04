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
		//destructor

		std::string get_first_name(void) const;
		std::string get_last_name(void) const;
		std::string get_nickname(void) const;
		std::string get_phone_number(void) const;
		std::string get_darkest_secret(void) const;
	private:
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phone_number;
		std::string darkest_secret;
};

#endif
