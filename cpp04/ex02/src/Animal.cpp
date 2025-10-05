#include "A_Animal.hpp"

A_Animal::A_Animal()
	: type("animal")
{
	std::cout << "\033[34mA_Animal created\033[0m" << std::endl;
}

A_Animal::A_Animal(std::string name)
	: type(name)
{
	std::cout << "\033[34mA_Animal created\033[0m" << std::endl;
}

A_Animal::A_Animal(const A_Animal &other)
	: type(other.type)
{
	std::cout << "\033[34mCopy of A_Animal created\033[0m" << std::endl;
}

A_Animal& A_Animal::operator=(const A_Animal &other)
{
	if (this != &other)
	{
		type = other.type;
	}
	return (*this);
}

A_Animal::~A_Animal()
{
	std::cout << "\033[34m" << "A_Animal destructor called\033[0m" << std::endl;
}

void A_Animal::makeSound() const
{
	std::cout << "*" << this->type << " noise*" << std::endl;
}

std::string	A_Animal::getType() const
{
	return (this->type);
}
