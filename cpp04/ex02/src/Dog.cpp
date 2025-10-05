#include "Dog.hpp"

Dog::Dog()
	: A_Animal("dog"), brain(new Brain)
{
	std::cout << "\033[34mDog created\033[0m" << std::endl;
}

Dog::Dog(const Dog &other)
	: A_Animal(other), brain (new Brain(*other.brain))
{
	std::cout << "\033[34mCopy of Dog created\033[0m" << std::endl;
}

Dog& Dog::operator=(const Dog &other)
{
	if (this != &other)
	{
		type = other.type;
		delete brain;
		brain = new Brain(*other.brain);
	}
	return (*this);
}

Dog::~Dog()
{
	delete brain;
	std::cout << "\033[34m" << this->type << " destructor called\033[0m"  << std::endl;
}
