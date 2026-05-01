#include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
		return (std::cout << "Try: ./RPN \"8 9 * 9 - 9 - 9 - 4 - 1 +\"" << std::endl, 1);
	// try
	// {
	// 	RPN rpn;
	// 	std::string a = "8 9 * 9 - 9 - 9 - 4 - 1 +";
	// 	std::string b = "7 7 * 7 -";
	// 	std::string c = "1 2 * 2 / 2 * 2 4 - +";
	// 	std::string d = "(1 + 1)";
	// 	std::cout << "\033[30m" << "\"" << a << "\" =	\033[0m" << rpn.calculate(a) << std::endl;
	// 	std::cout << "\033[30m" << "\"" << b << "\" =	\033[0m" << rpn.calculate(b) << std::endl;
	// 	std::cout << "\033[30m" << "\"" << c << "\" =	\033[0m" << rpn.calculate(c) << std::endl;
	// 	std::cout << "\033[30m" << "\"" << d << "\" =	\033[0m" << rpn.calculate(d) << std::endl;
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << "Error: " << e.what() << "\033[0m" << std::endl;
	// }
	//std::cout << std::endl;
	try
	{
		RPN rpn;
		std::cout << rpn.calculate(argv[1]) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}
}
