#include "easyfind.hpp"

int main()
{
	try
	{ //vector
		std::cout << "\033[30m		Vector\033[0m" << std::endl;
		std::vector<int> a(6);
		a[0] = 4;
		a[1] = 2;
		a[2] = 42;
		a[3] = 3;
		a[4] = 1;
		a[5] = 41;
		std::cout << "a = " << *easyfind(a, 42) << std::endl;
		std::cout << "a = " << *easyfind(a, 5) << std::endl;//throw
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	
	try
	{ //deque
		std::cout << "\033[30m		Deque\033[0m" << std::endl;
		std::deque<int> a(6);
		a[0] = 4;
		a[1] = 2;
		a[2] = 42;
		a[3] = 3;
		a[4] = 1;
		a[5] = 41;
		std::cout << "a = " << *easyfind(a, 42) << std::endl;
		std::cout << "a = " << *easyfind(a, 5) << std::endl;//throw
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{ //list
		std::cout << "\033[30m		List\033[0m" << std::endl;
		std::list<int> a(6);
		a.push_front(41);
		a.push_front(1);
		a.push_front(3);
		a.push_front(42);
		a.push_front(2);
		a.push_front(4);
		std::cout << "a = " << *easyfind(a, 42) << std::endl;
		std::cout << "a = " << *easyfind(a, 5) << std::endl;//throw
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{ //string
		std::cout << "\033[30m		String\033[0m" << std::endl;
		std::string a("hola calabaza");
		std::cout << "a = " << *easyfind(a, 'z') << std::endl;
		std::cout << "a = " << *easyfind(a, 'e') << std::endl;//throw
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}
