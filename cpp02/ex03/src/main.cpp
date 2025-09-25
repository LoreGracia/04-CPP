#include "Point.hpp"
#include <iostream>
int main( void ) {
	Point a(10,0);
	Point b(0,0);
	Point c(0,10);
	Point point(5,2);
	std::cout << bsp(a, b, c, point) << std::endl;
	return 0;
}
