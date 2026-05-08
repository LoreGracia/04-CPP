#include <locale>
#include <string>
#include <iostream>

int	main(int ac, char **av)
{
	(void)ac;

	if (ac == 1)
		return (std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl, 0);
	for (int i = 1; i < ac; i++) 
	{
		std::locale loc;
		std::string str(av[i]);
		for (size_t j = 0; j < str.length(); j++)
			std::cout << std::toupper(str[j], loc);
	}
	std::cout << std::endl;
	return (0);
}
