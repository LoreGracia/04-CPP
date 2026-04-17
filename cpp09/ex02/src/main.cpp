#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	(void)argc;
	if (argc == 1)
		return (std::cout << "Missing arguments: ./PmergeMe 3 6 5 34 1 32 59 42 4\n", 1);
	try
	{
		PmergeMe pm;
		std::cout << "Before:	";
		for (int i = 1; i != argc; i++)
			std::cout << argv[i] << " ";
		std::cout << std::endl;
		pm.calculate(++argv);
		std::cout << "After:	" << pm << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}
	return 0;
}
