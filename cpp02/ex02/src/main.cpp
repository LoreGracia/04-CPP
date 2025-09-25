#include "Fixed.hpp"
#include <iostream>
int main( void ) {
	{
		Fixed a;
		Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << Fixed::max( a, b ) << std::endl;
	}
	{
		Fixed a;
		Fixed const b( Fixed( 21.21f ) * Fixed( 2 ) );
		std::cout << std::endl;
		std::cout << "\033[32ma = \033[0m" << a << std::endl;
		std::cout << "\033[32mb = \033[0m" << b << std::endl;
		std::cout << "\033[32ma < b  ? \033[0m" << (a < b) << std::endl;
		std::cout << "\033[32ma > b  ? \033[0m" << (a > b) << std::endl;
		std::cout << "\033[32ma <= b ? \033[0m" << (a <= b) << std::endl;
		std::cout << "\033[32ma >= b ? \033[0m" << (a >= b) << std::endl;
		std::cout << "\033[32ma == b ? \033[0m" << (a == b) << std::endl;
		std::cout << "\033[32ma != b ? \033[0m" << (a != b) << std::endl;
		std::cout << std::endl;
		std::cout << "\033[32ma = \033[0m" << a << "\033[32m a++ ? \033[0m" << a++ << std::endl;
		std::cout << "\033[32ma = \033[0m" << a << "\033[32m ++a ? \033[0m" << ++a << std::endl;
		std::cout << "\033[32ma = \033[0m" << a << "\033[32m a-- ? \033[0m" << a-- << std::endl;
		std::cout << "\033[32ma = \033[0m" << a << "\033[32m --a ? \033[0m" << --a << std::endl;
		std::cout << "\033[32ma = \033[0m" << a << "\033[32m ++ ++a ? \033[0m" << ++ ++a << std::endl;
		std::cout << std::endl;
		std::cout << "\033[32ma = \033[0m" << a << "\033[32m b = \033[0m" << b << std::endl;
		std::cout << "\033[32ma + b ? \033[0m" << (a + b) << std::endl;
		std::cout << "\033[32ma = \033[0m" << a << "\033[32m b = \033[0m" << b << std::endl;
		std::cout << "\033[32ma - b ? \033[0m" << (a - b) << std::endl;
		std::cout << "\033[32ma = \033[0m" << a << "\033[32m b = \033[0m" << b << std::endl;
		std::cout << "\033[32ma * b ? \033[0m" << (a * b) << std::endl;
		std::cout << "\033[32ma = \033[0m" << a << "\033[32m b = \033[0m" << b << std::endl;
		std::cout << "\033[32ma / b ? \033[0m" << (a / b) << std::endl;
		std::cout << std::endl;
		std::cout << "\033[32ma = \033[0m" << a << "\033[32m b = \033[0m" << b << std::endl;
		std::cout << "\033[32mmin ? \033[0m"<< Fixed::min( a, b ) << std::endl;
		std::cout << "\033[32mmax ? \033[0m"<< Fixed::max( a, b ) << std::endl;
	}
	return 0;
}
