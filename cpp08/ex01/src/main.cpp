#include "Span.hpp"

int main()
{
	{
		std::cout << "\033[30m			More than 1000" << std::endl;
		Span sp(10001);
		for (int i = 0; i < 10001; i++)
			sp.addNumber(i);
		std::cout << "sp.shortest = " << sp.shortestSpan() << std::endl;
		std::cout << "sp.largest = " << sp.longestSpan() << std::endl;
		std::cout << std::endl;
	}
	try
	{
		std::cout << "\033[30m			Deep copy" << std::endl;
		Span sp(6);
		sp.addNumber(4);
		sp.addNumber(2);
		sp.addNumber(42);
		sp.addNumber(3);
		sp.addNumber(1);
		Span cp(sp);
		std::cout << "sp = " << &sp << " | cp = " << &cp << std::endl;
		std::cout << "sp.shortest = " << sp.shortestSpan() << std::endl;
		cp.addNumber(2);
		std::cout << "sp.shortest = " << sp.shortestSpan() << std::endl;
		std::cout << "cp.shortest = " << cp.shortestSpan() << std::endl;
		sp = cp;
		std::cout << "sp.shortest = " << sp.shortestSpan() << std::endl;
		std::cout << "sp = " << &sp << " | cp = " << &cp << std::endl;
		std::cout << std::endl;

		std::cout << "\033[30m			Throw add full" << std::endl;
		cp.addNumber(7);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl << std::endl;

	}
	try
	{
		std::cout << "\033[30m			Short span" << std::endl;
		std::cout << "\033[30m			Throw no span(0)" << std::endl;
		Span a(5);
		std::cout << "sp.shortest = " << a.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl << std::endl;
	}
	try
	{
		std::cout << "\033[30m			Throw no span(1)" << std::endl;
		Span a(5);
		a.addNumber(1);
		std::cout << "sp.shortest = " << a.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl << std::endl;

	}

	try
	{
		std::cout << "\033[30m			Large span" << std::endl;
		std::cout << "\033[30m			Throw no span(0)" << std::endl;
		Span a(5);
		std::cout << "sp.shortest = " << a.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl << std::endl;

	}
	try
	{
		std::cout << "\033[30m			Throw no span(1)" << std::endl;
		Span a(5);
		a.addNumber(1);
		std::cout << "sp.shortest = " << a.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl << std::endl;
	}

	{
		std::cout << "\033[30m			Default" << std::endl;
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	return 0;
}
