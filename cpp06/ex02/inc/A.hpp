#ifndef A_HPP	
# define A_HPP

#include <string>
#include <iostream>
#include "Base.hpp"

class A : public Base
{
	public:
		A() { std::cout << "\033[34mA constructor called\033[0m" << std::endl; };
};

#endif
