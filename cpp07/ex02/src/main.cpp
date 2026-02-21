#include "whatever.hpp"

int main()
{
	{ //swap
		std::cout << "		Swap" << std::endl;
		int a = 4;
		int b = 2;
		std::cout << "a = " << a << std::endl;
		std::cout << "b = " << b << std::endl;
		swap(a, b);
		std::cout << "a = " << a << std::endl;
		std::cout << "b = " << b << std::endl;
		std::cout << std::endl;

		char c = 'c';
		char d = 'd';
		std::cout << "c = " << c << std::endl;
		std::cout << "d = " << d << std::endl;
		swap(c, d);
		std::cout << "c = " << c << std::endl;
		std::cout << "d = " << d << std::endl;
		std::cout << std::endl;

		std::string hi = "Hello";
		std::string bye = "Goodbye";
		std::cout << "hi = " << hi << std::endl;
		std::cout << "bye = " << bye << std::endl;
		swap(hi, bye);
		std::cout << "hi = " << hi << std::endl;
		std::cout << "bye = " << bye << std::endl;
		std::cout << std::endl;

		void *A = &a;
		void *B = &b;
		std::cout << "A = " << A << std::endl;
		std::cout << "B = " << B << std::endl;
		std::cout << "a = " << a << std::endl;
		std::cout << "b = " << b << std::endl;
		swap(A, B);
		std::cout << "A = " << A << std::endl;
		std::cout << "B = " << B << std::endl;
		std::cout << "a = " << a << std::endl;
		std::cout << "b = " << b << std::endl;
		std::cout << std::endl;
	}
	{ //min
		std::cout << "		Min" << std::endl;
		int a = 4;
		int b = 2;
		std::cout << "a = " << a << std::endl;
		std::cout << "b = " << b << std::endl;
		std::cout << "min = " << min(a, b) << std::endl;
		std::cout << std::endl;

		char c = 'c';
		char d = 'd';
		std::cout << "c = " << c << std::endl;
		std::cout << "d = " << d << std::endl;
		std::cout << "min = " << min(c, d) << std::endl;
		std::cout << std::endl;
	}
	{ //max
		std::cout << "		Max" << std::endl;
		int a = 4;
		int b = 2;
		std::cout << "a = " << a << std::endl;
		std::cout << "b = " << b << std::endl;
		std::cout << "max = " << max(a, b) << std::endl;
		std::cout << std::endl;

		char c = 'c';
		char d = 'd';
		std::cout << "c = " << c << std::endl;
		std::cout << "d = " << d << std::endl;
		std::cout << "max = " << max(c, d) << std::endl;
		std::cout << std::endl;
	}
	{ //subject main
		std::cout << "		Subject main" << std::endl;
		int a = 2;
		int b = 3;
		::swap( a, b );
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
		std::string c = "chaine1";
		std::string d = "chaine2";
		::swap(c, d);
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
		std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	}
}
