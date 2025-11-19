#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>

class Contact{
	public:
		Contact();
		~Contact();

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

	private:
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phone_number;
		std::string darkest_secret;
};

#endif

