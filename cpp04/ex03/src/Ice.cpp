#include "Ice.hpp"

Ice::Ice()
	: AMateria("ice")
{
	std::cout << "\033[34mIce created\033[0m" << std::endl;
}

Ice::Ice(const Ice &other)
	: AMateria(other)
{
	std::cout << "\033[34mCopy of Ice created\033[0m" << std::endl;
}

Ice& Ice::operator=(const Ice &other)
{
	if (this != &other)
		*this = other;
	return (*this);
}

Ice::~Ice()
{
	std::cout << "\033[34m" << "Ice destructor called\033[0m" << std::endl;
}

Ice* Ice::clone() const
{
	return new Ice();
}

void Ice::use(ICharacter& target)
{
	std::cout <<  "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
