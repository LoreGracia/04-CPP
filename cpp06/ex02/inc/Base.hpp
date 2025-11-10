#ifndef BASE_HPP	
# define BASE_HPP

#include <cstdlib>
#include <string>
#include <iostream>

#define MAX 3

class Base
{
	public:
		virtual ~Base() { std::cout << "\033[34mBase destructor called\033[0m" << std::endl; };
};

#endif
