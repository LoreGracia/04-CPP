#include "Cure.hpp"

Cure::Cure()
	: AMateria("cure")
{
	std::cout << "\033[34mCure created\033[0m" << std::endl;
}

Cure::Cure(const Cure &other)
	: AMateria(other)
{
	std::cout << "\033[34mCopy of Cure created\033[0m" << std::endl;
}

Cure& Cure::operator=(const Cure &other)
{
	if (this != &other)
	{
		*this = other;
	}
	return (*this);
}

Cure::~Cure()
{
	std::cout << "\033[34m" << "Cure destructor called\033[0m" << std::endl;
}

Cure* Cure::clone() const
{
	return new Cure();
}

void Cure::use(ICharacter& target)
{
	std::cout <<  "* heals " << target.getName() << "’s wounds *" << std::endl;
}
