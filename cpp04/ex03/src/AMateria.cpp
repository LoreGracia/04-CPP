#include "AMateria.hpp"

AMateria::AMateria(std::string const & type)
	: type(type)
{
	std::cout << "\033[34mAMateria created\033[0m" << std::endl;
}

AMateria::AMateria(const AMateria &other)
	: type(other.type)
{
	std::cout << "\033[34mCopy of AMateria created\033[0m" << std::endl;
}

AMateria& AMateria::operator=(const AMateria &other)
{
	if (this != &other)
	{
		*this = other;
	}
	return (*this);
}

AMateria::~AMateria()
{
	std::cout << "\033[34m" << "AMateria destructor called\033[0m" << std::endl;
}

void AMateria::use(ICharacter& target)
{
	std::cout <<  "* Default AMateria against " << target.getName() << " *" << std::endl;
}

std::string	const & AMateria::getType() const
{
	return (this->type);
}
