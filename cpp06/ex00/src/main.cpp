#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
	if (ac == 2)
	{
		ScalarConverter::convert(av[1]);
		return 0;
	}
	std::cout << "\033[31mInsert char, int, float or double literal\033[0m" << std::endl;
	return 1;
}
