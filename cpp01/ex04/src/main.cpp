#include "Sed_is_for_losers.hpp"

int	main(int ac, char **av)
{
	if (ac != 4)
		return (std::cout << "3 arg; Filename S1 S2" << std::endl, 1);
	std::ifstream file(av[1]);
	std::string replace_name(std::string(av[1]) + ".replace");
	std::ofstream	replace(replace_name.c_str());
	if (!file.is_open() || !replace)
		return (std::cout << "Could not open file\n" << std::endl, 1);
	std::string	buff;
	size_t	i;
	std::string	s1(av[2]);
	std::string	s2(av[3]);
	while (getline(file, buff))
	{
		i = 0;
		while (std::string(av[2]).compare(av[3]) && (i = buff.find(s1, i)) != std::string::npos)
		{
			buff.erase(i, s1.size());
			buff.insert(i, s2);
		}
		if (buff.empty())
			break;
		replace << buff << std::endl;
	}
	file.close();
	replace.close();
	return 0;
}
