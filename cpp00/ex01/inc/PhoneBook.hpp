#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
	private:
		Contact array[8];
	public:
		bool	add(std::istream& in, std::string& str);
		bool	search(std::istream& in, std::string& str);
		void	index();
};
#endif
