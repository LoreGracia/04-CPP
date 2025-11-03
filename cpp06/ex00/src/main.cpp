#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
	try
	{
		if (ac == 2)
		{
			ScalarConverter::convert(av[1]);
			return 0;
		}
		std::cout << "\033[31mInsert char, int, float or double literal\033[0m" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}
