#include "Contact.hpp"

std::string	Contact::add_first_name(std::string str) { return this->first_name = str; }
std::string	Contact::add_last_name(std::string str) { return this->last_name = str; }
std::string	Contact::add_nickname(std::string str) { return this->nickname = str; }
std::string	Contact::add_phonumber(std::string str) { return this->phone_number = str; }
std::string	Contact::add_darkest_secret(std::string str) { return this->darkest_secret = str; }

std::string	Contact::get_first_name() { return this->first_name; }
std::string	Contact::get_last_name() { return this->last_name; }
std::string	Contact::get_nickname() { return this->nickname; }
std::string	Contact::get_phonenumber() { return this->phone_number; }
std::string	Contact::get_darkest_secret() { return this->darkest_secret; }

Contact::Contact()
{
	this -> first_name.clear();
	this -> last_name.clear();
	this -> nickname.clear();
	this -> phone_number.clear();
	this -> darkest_secret.clear();
}

bool	Contact::add(std::istream& in)
{
	std::cout << "Insert first name:" << std::right << std::setw(22) << "BACK" << std::endl;
	std::getline(in >> std::ws, this -> first_name);
	std::cout << "Insert last name:" << std::endl;
	std::getline(in >> std::ws, this -> last_name);
	std::cout << "Insert nickname:" << std::endl;
	std::getline(in >> std::ws, this -> nickname);
	std::cout << "Insert phone number:" << std::endl;
	std::getline(in >> std::ws, this -> phone_number);
	std::cout << "Insert darkest secret:" << std::endl;
	std::getline(in >> std::ws, this -> darkest_secret);
	return (0);
}

void	Contact::show()
{
	std::cout << "First name:	" << this -> first_name << "\n"
		<< "Last name:	" << this -> last_name << "\n"
		<< "Nickname:	" << this -> nickname << "\n"
		<< "Phone number:	" << this -> phone_number << "\n"
		<< "Darkest secret:	" << this -> darkest_secret << std::endl;
}

bool	Contact::is()
{
	if (!this->first_name.empty())
		return (1);
	return (0);
}
