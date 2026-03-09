#include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
		return (std::cout << "Try: ./RPN \"8 9 * 9 - 9 - 9 - 4 - 1 +\"" << std::endl, 1);
	try
	{
		RPN rpn;
		std::cout << rpn.calculate("8 9 * 9 - 9 - 9 - 4 - 1 +") << std::endl;
		std::cout << rpn.calculate("7 7 * 7 -") << std::endl;
		std::cout << rpn.calculate("1 2 * 2 / 2 * 2 4 - +") << std::endl;
		std::cout << rpn.calculate("(1 + 1)") << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}
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
