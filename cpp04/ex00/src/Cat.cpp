#include "Cat.hpp"

Cat::Cat()
	: Animal("cat")
{
	std::cout << "\033[34mCat created\033[0m" << std::endl;
}

Cat::Cat(const Cat &other)
	: Animal(other)
{
	std::cout << "\033[34mCopy of Cat created\033[0m" << std::endl;
}

Cat& Cat::operator=(const Cat &other)
{
	if (this != &other)
	{
		type = other.type;
	}
	return (*this);
}

Cat::~Cat()
{
	std::cout << "\033[34m" << this->type << " destructor called\033[0m" << std::endl;
}
