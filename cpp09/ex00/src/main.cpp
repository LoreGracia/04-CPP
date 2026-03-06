#include "BitcoinExchange.hpp"

int main(int argc, char** argv)
{
	try
	{
		if (argc != 2)
			throw std::logic_error("Missing or too much arguments");
		Btc btc;
		(void)argv;
		// std::cout << std::fixed << std::setprecision(2) << _data[std::strtoul(date.c_str(), NULL, 10)] << std::endl;
		btc.findPrize(argv[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}
