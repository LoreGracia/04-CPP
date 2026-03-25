#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	(void)argv;
	if (argc == 1)
		return (std::cout << "Missing arguments: ./PmergeMe 3 6 5 34 1 32 59 42 4\n", 1);
	try
	{
		PmergeMe pm;
		std::cout << pm << std::endl;
		pm.calculate(++argv);
		std::cout << pm << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}
	return 0;
}
