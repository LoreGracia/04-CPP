#ifndef C_HPP	
# define C_HPP

#include <string>
#include <iostream>
#include "Base.hpp"

class C : public Base
{
	public:
		C() { std::cout << "\033[34mC constructor called\033[0m" << std::endl; };
};

#endif
