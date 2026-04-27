#include "PmergeMe.hpp"
size_t compv = 0;
size_t compd = 0;

int floor_log2(unsigned int x) {
    int result = 0;
    while (x >>= 1) ++result;
    return result;
}

int ceil_log2(unsigned int x) {
    int f = floor_log2(x);
    return ((1U << f) == x) ? f : f + 1;
}

void	print_expected(int argc)
{
		size_t n = argc - 1;
		int part1 = n * ceil_log2((3*n + 3) / 4);
		int fl = floor_log2(6*n);
		int part2 = (1 << fl) / 3;
		int part3 = fl / 2;
		int result = part1 - part2 + part3;
		std::cout << "Max comparissions expected:	" << result << std::endl;
}

int main(int argc, char **argv)
{
	(void)argc;
	if (argc == 1)
		return (std::cout << "Missing arguments: ./PmergeMe 3 6 5 34 1 32 59 42 4\n", 1);
	try
	{
		PmergeMeV pmV;
		PmergeMeD pmD;
		std::cout << "Before:	";
		for (int i = 1; i != argc; i++)
			std::cout << argv[i] << " ";
		std::cout << std::endl;
		++argv;
		pmV.calculate(argv);
		std::cout << "pasa" << std::endl;
		pmD.calculate(argv);
		std::cout << "pasa" << std::endl;
		std::cout << "V After:	" << pmV << std::endl;
		std::cout << "D After:	" << pmD << std::endl;
		std::cout << "V Comparissions done:		" << compv << std::endl;
		std::cout << "D Comparissions done:		" << compd << std::endl;
		print_expected(argc);// calculate fordJohnson expected comparisions n⌈log2​(3n/4​)⌉−⌊(2^⌊log2​(6n)⌋)/3​⌋+⌊log2​(6n)/2​⌋ with Wolfram
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}
	return 0;
}
