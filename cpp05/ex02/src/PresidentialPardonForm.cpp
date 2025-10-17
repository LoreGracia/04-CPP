#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
	: AForm("default", 5, 25)
{
	std::cout << "\033[34mPresidentialPardonForm " << this->getName() << " constructor called\033[0m" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string name)
	: AForm(name, 5, 25)
{
	std::cout << "\033[34mPresidentialPardonForm " << this->getName() << " constructor called\033[0m" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &other)
	: AForm(other)
{
	std::cout << "\033[34mPresidentialPardonForm " << this->getName() << " copy constructor called\033[0m" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm &other)
{
	if (this != &other)
		*this = other;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "\033[34mPresidentialPardonForm " << this->getName() << " destructor called\033[0m" << std::endl;
}

void PresidentialPardonForm::behaviour() const
{
	std::cout << this->getName() << " was pardoned by Zaphod Beeblebrox" << std::endl;
}
