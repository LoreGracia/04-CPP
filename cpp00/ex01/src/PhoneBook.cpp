#include "PhoneBook.hpp"
#include "Contact.hpp"

bool PhoneBook::add(std::istream& in, std::string& str)
{
	if (!str.compare("ADD"))
	{
		int	i = 0;
		while (i < 7 && this->array[i].is())
			i++;
		std::cout << i << "|" << std::endl;
		this->array[i].add(in);
		system("clear");
		return (1);
	}
	return (0);
}

void	PhoneBook::index()
{
	std::cout << "|" << std::right << std::setw(10) << "index" << "|" 
			<< std::right << std::setw(10) << "first name" << "|" 
			<< std::right << std::setw(10) << "last name" << "|" 
			<< std::right << std::setw(10) << "nickname" << "|" << "\n" << std::flush;
	for (int i = 0; i < 8; i++)
	{
		std::cout << "|" << std::right << std::setw(10) << i + 1 << "|"
				<< std::right << std::setw(10) << (this->array[i].get_first_name().length() > 10 ? this->array[i].get_first_name().substr(0, 9) + "." : this->array[i].get_first_name()) << "|"
				<< std::right << std::setw(10) << (this->array[i].get_last_name().length() > 10 ? this->array[i].get_last_name().substr(0, 9)  + "." : this->array[i].get_last_name()) << "|"
				<< std::right << std::setw(10) << (this->array[i].get_nickname().length() > 10 ? this->array[i].get_nickname().substr(0, 9)  + "." : this->array[i].get_nickname()) << "|" << std::endl;
	}
}

bool PhoneBook::search(std::istream& in, std::string& str)
{
	if (!str.compare("SEARCH"))
	{
		do
		{
			std::cout << std::internal << std::setw(40) << "Insert Index    or    write BACK" << std::endl;
			this->index();
			std::getline(in >> std::ws, str);
			system("clear");
			if (!str.compare("EXIT") || !str.compare("BACK") || in.eof())
				break;
			if (str.empty() || str.length() != 1 || std::isdigit(str[0] - '0') || !str.compare("0"))
				std::cout << std::internal << std::setw(53) << "\033[31mPlease enter number between 1 - 9 or BACK\033[0m" << std::endl;
			else
			{
				if (this -> array[str[0] - '0' - 1].is())
				{
					system("clear");
					this -> array[str[0] - '0' - 1].show();
					break;
				}
				else
					std::cout << std::internal << std::setw(40) << "\033[31mEmpty Contact\033[0m" << std::endl;
			}
		} while (str.compare("EXIT") && str.compare("BACK") && !in.eof());
		if (!str.compare("EXIT"))
			return (-1);
		return (1);
	}
	return (0);
}
