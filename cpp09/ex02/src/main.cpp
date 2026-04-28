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
		std::cout << "Max ±1 or ±2 comparissions expected:	" << result << std::endl;
}

int main(int argc, char **argv)
{
	(void)argc;
	if (argc == 1)
		return (std::cout << "Missing arguments: ./PmergeMe 3 6 5 34 1 32 59 42 4 or ./PmergeMe $(shuf -ri 1-3000 -n 10)\n", 1);
	try
	{
		PmergeMeV pmV;
		PmergeMeD pmD;
		std::cout << "Before:		";
		for (int i = 1; i != argc; i++)
			std::cout << argv[i] << " ";
		std::cout << std::endl;
		++argv;
		std::clock_t initv = std::clock();
		pmV.calculate(argv);
		std::clock_t endv = std::clock();
		std::clock_t initd = std::clock();
		pmD.calculate(argv);
		std::clock_t endd = std::clock();
		std::cout << "V After:	" << pmV << std::endl;
		std::cout << "D After:	" << pmD << std::endl;
		std::cout << "V Comparissions done:			" << compv << std::endl;
		std::cout << "D Comparissions done:			" << compd << std::endl;
		double vtime = (double(endv - initv) / CLOCKS_PER_SEC)* 1000000.0;
		double dtime = (double(endd - initd) / CLOCKS_PER_SEC)* 1000000.0;
		print_expected(argc);// calculate fordJohnson expected comparisions n⌈log2​(3n/4​)⌉−⌊(2^⌊log2​(6n)⌋)/3​⌋+⌊log2​(6n)/2​⌋ with Wolfram error de margen ±1 o ±2

		std::cout << "V Time µs: " << vtime << std::endl;
		std::cout << "D Time µs: " << dtime << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}
	return 0;
}
