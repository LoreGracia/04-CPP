#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat harl("Harl", 155);
		std::cout << harl << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		Bureaucrat harl("Harl", -5);
		std::cout << harl << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		Bureaucrat harl("Harl_high_error", 5);
		Bureaucrat max = harl;
		std::cout << harl << std::endl;
		harl.decrement(5);
		std::cout << harl << std::endl;
		harl.increment(10);
		std::cout << harl << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		Bureaucrat harl("Harl_low_error", 150);
		Bureaucrat max("Max", 50);
		std::cout << harl << std::endl;
		std::cout << max << std::endl;
		max = harl;
		std::cout << harl << std::endl;
		std::cout << max << std::endl;
		harl.decrement(5);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}
