#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
	: type("Wrong animal")
{
	std::cout << "\033[34mWrongAnimal created\033[0m" << std::endl;
}

WrongAnimal::WrongAnimal(std::string name)
	: type(name)
{
	std::cout << "\033[34mWrongAnimal created\033[0m" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
	: type(other.type)
{
	std::cout << "\033[34mCopy of WrongAnimal created\033[0m" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &other)
{
	if (this != &other)
	{
		type = other.type;
	}
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "\033[34m" << "WrongAnimal destructor called\033[0m" << std::endl;
}

void WrongAnimal::makeSound() const
{
	std::cout << "*" << this->type << " noise*" << std::endl;
}

std::string	WrongAnimal::getType() const
{
	return (this->type);
}
