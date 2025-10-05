#include "Dog.hpp"

Dog::Dog()
	: Animal("dog")
{
	std::cout << "\033[34mDog created\033[0m" << std::endl;
}

Dog::Dog(const Dog &other)
	: Animal(other)
{
	std::cout << "\033[34mCopy of Dog created\033[0m" << std::endl;
}

Dog& Dog::operator=(const Dog &other)
{
	if (this != &other)
	{
		type = other.type;
	}
	return (*this);
}

Dog::~Dog()
{
	std::cout << "\033[34m" << this->type << " destructor called\033[0m" << std::endl;
}
