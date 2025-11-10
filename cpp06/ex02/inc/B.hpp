#ifndef B_HPP	
# define B_HPP

#include <string>
#include <iostream>
#include "Base.hpp"

class B : public Base
{
	public:
		B() { std::cout << "\033[34mB constructor called\033[0m" << std::endl; };
};

#endif
