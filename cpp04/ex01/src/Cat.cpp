#include "Cat.hpp"

Cat::Cat()
	: Animal("cat"), brain(new Brain)
{
	std::cout << "\033[34mCat created\033[0m" << std::endl;
}

Cat::Cat(const Cat &other)
	: Animal(other), brain(new Brain(*other.brain))
{
	std::cout << "\033[34mCopy of Cat created\033[0m" << std::endl;
}

Cat& Cat::operator=(const Cat &other)
{
	if (this != &other)
	{
		type = other.type;
		delete brain;
		brain = new Brain(*other.brain);
	}
	return (*this);
}

Cat::~Cat()
{
	delete this->brain;
	std::cout << "\033[34m" << this->type << " destructor called\033[0m" << std::endl;
}
