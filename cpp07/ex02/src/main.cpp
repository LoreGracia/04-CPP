#include "Array.hpp"

int main()
{
	try
	{
		std::cout << "\033[30mINT" << std::endl;
		std::cout << "			\033[30mOperator[]" << std::endl;
		Array<int> b(4);
		std::cout << "b[0] = " << b[0] << std::endl;
		b[0] = 4;
		std::cout << "b[0] = " << b[0] << std::endl;
		std::cout << "b[1] = " << b[1] << std::endl;
		b[1] = 2;
		std::cout << "b[1] = " << b[1] << std::endl;
		std::cout << "b[2] = " << b[2] << std::endl;
		b[2] = 42;
		std::cout << "b[2] = " << b[2] << std::endl;
		std::cout << "b[3] = " << b[3] << std::endl;
		b[3] = 6;
		std::cout << "b[3] = " << b[3] << std::endl;
		std::cout << std::endl;

		std::cout << "			\033[30mOperator=" << std::endl;
		Array<int> a;
		std::cout << "&b = " << &b << " | " << "&a = " << &a << std::endl;
		a = b;
		std::cout << "&b = " << &b << " | " << "&a = " << &a << std::endl;
		std::cout << "&b[0] = " << &b[0] << " | " << "&a[0] = " << &a[0] << std::endl;
		std::cout << "b[0] = " << b[0] << " | " << "a[0] = " << a[0] << std::endl;
		a[0] = 24;
		std::cout << "&b = " << &b << " | " << "&a = " << &a << std::endl;
		std::cout << "&b[0] = " << &b[0] << " | " << "&a[0] = " << &a[0] << std::endl;
		std::cout << "b[0] = " << b[0] << " | " << "a[0] = " << a[0] << std::endl;
		std::cout << std::endl;
		
		std::cout << "			\033[30mConstructor copy" << std::endl;
		Array<int> c(a);
		std::cout << "&c = " << &c << " | " << "&a = " << &a << std::endl;
		std::cout << "&c[0] = " << &c[0] << " | " << "&a[0] = " << &a[0] << std::endl;
		std::cout << "c[0] = " << c[0] << " | " << "a[0] = " << a[0] << std::endl;
		std::cout << std::endl;

		std::cout << "			\033[30mSize throw" << std::endl;
		std::cout << "c.size = " << c.size() << std::endl;
		std::cout << "c[4] = " << c[4] << std::endl;//out of range throw
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		std::cout << "\033[30mSTRING" << std::endl;
		std::cout << "			\033[30mOperator[]" << std::endl;
		Array<std::string> b(4);
		std::cout << "b[0] = " << b[0] << std::endl;
		b[0] = "Marai Chuzena";
		std::cout << "b[0] = " << b[0] << std::endl;
		std::cout << "b[1] = " << b[1] << std::endl;
		b[1] = "su choz techaba";
		std::cout << "b[1] = " << b[1] << std::endl;
		std::cout << "b[2] = " << b[2] << std::endl;
		b[2] = "un techador que por alli pasaba le dijo";
		std::cout << "b[2] = " << b[2] << std::endl;
		std::cout << "b[3] = " << b[3] << std::endl;
		b[3] = "Chuzena, tu techas tu choza o techas la ajena";
		std::cout << "b[3] = " << b[3] << std::endl;
		std::cout << std::endl;

		std::cout << "			\033[30mOperator=" << std::endl;
		Array<std::string> a;
		std::cout << "&b = " << &b << " | " << "&a = " << &a << std::endl;
		a = b;
		std::cout << "&b = " << &b << " | " << "&a = " << &a << std::endl;
		std::cout << "&b[0] = " << &b[0] << " | " << "&a[0] = " << &a[0] << std::endl;
		std::cout << "b[0] = " << b[0] << " | " << "a[0] = " << a[0] << std::endl;
		a[0] = "Coneixen el que diu";
		std::cout << "&b = " << &b << " | " << "&a = " << &a << std::endl;
		std::cout << "&b[0] = " << &b[0] << " | " << "&a[0] = " << &a[0] << std::endl;
		std::cout << "b[0] = " << b[0] << " | " << "a[0] = " << a[0] << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		
		std::cout << "			\033[30mConstructor copy" << std::endl;
		Array<std::string> c(a);
		std::cout << "&c = " << &c << " | " << "&a = " << &a << std::endl;
		std::cout << "&c[0] = " << &c[0] << " | " << "&a[0] = " << &a[0] << std::endl;
		std::cout << "c[0] = " << c[0] << " | " << "a[0] = " << a[0] << std::endl;
		std::cout << std::endl;

		std::cout << "			\033[30mSize throw" << std::endl;
		std::cout << "c.size = " << c.size() << std::endl;
		std::cout << "c[4] = " << c[4] << std::endl;//out of range throw
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}
