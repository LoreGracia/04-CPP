#include "Animal.hpp"

Animal::Animal()
	: type("animal")
{
	std::cout << "\033[34mAnimal created\033[0m" << std::endl;
}

Animal::Animal(std::string name)
	: type(name)
{
	std::cout << "\033[34mAnimal created\033[0m" << std::endl;
}

Animal::Animal(const Animal &other)
	: type(other.type)
{
	std::cout << "\033[34mCopy of Animal created\033[0m" << std::endl;
}

Animal& Animal::operator=(const Animal &other)
{
	if (this != &other)
	{
		type = other.type;
	}
	return (*this);
}

Animal::~Animal()
{
	std::cout << "\033[34m" << "Animal destructor called\033[0m" << std::endl;
}

void Animal::makeSound() const
{
	std::cout << "*" << this->type << " noise*" << std::endl;
}

std::string	Animal::getType() const
{
	return (this->type);
}
