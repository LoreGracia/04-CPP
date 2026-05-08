#include "PhoneBook.hpp"
#include "Contact.hpp"


int	main()
{
	int			ret;
	PhoneBook	pb;
	std::string str;
	std::istream *in = &std::cin;
	system("clear");
	do
		{
			std::cout << std::internal << std::setw(30) << "ADD | SEARCH | EXIT" << std::endl;
			std::getline(*in >> std::ws, str);
			if (!str.empty())
			{
				ret = 0;
				system("clear");
				ret = pb.add(*in, str);
				if (!ret)
					ret = pb.search(*in, str);
				if (!ret && !(*in).eof())
					std::cout << std::internal << std::setw(35) << "\033[31mWrite one of the options(capitalized)\033[0m" << std::endl;					
			}
		}
		while (str.compare("EXIT") && !(*in).eof());
}
