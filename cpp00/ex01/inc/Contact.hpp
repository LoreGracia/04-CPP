#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include <iostream>
#include <iomanip>
#include <cstdlib>

class Contact {
	private:
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_number;
		std::string	darkest_secret;
	public:
		Contact();
		bool	add(std::istream& in);
		std::string	add_first_name(std::string str);
		std::string	add_last_name(std::string str);
		std::string	add_nickname(std::string str);
		std::string	add_phonumber(std::string str);
		std::string	add_darkest_secret(std::string str);
		void	show();
		bool	is();
		std::string	get_first_name();
		std::string	get_last_name();
		std::string	get_nickname();
		std::string	get_phonenumber();
		std::string	get_darkest_secret();
};
#endif
