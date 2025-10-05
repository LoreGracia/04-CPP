#include "WrongCat.hpp"

WrongCat::WrongCat()
	: WrongAnimal("wrong cat")
{
	std::cout << "\033[34mWrongCat created\033[0m" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other)
	: WrongAnimal(other.type)
{
	std::cout << "\033[34mCopy of WrongCat created\033[0m" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat &other)
{
	if (this != &other)
	{
		type = other.type;
	}
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "\033[34m" << this->type << " destructor called\033[0m" << std::endl;
}
