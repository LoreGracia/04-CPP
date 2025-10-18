#include "Intern.hpp"

Intern::Intern() { std::cout << "\033[34mIntern constructor called\033[0m" << std::endl; }

Intern::Intern(Intern &other)
{
	*this = other;
	std::cout << "\033[34mIntern copy constructor called\033[0m" << std::endl;
}

Intern &Intern::operator=(Intern &other)
{
	if (this != &other)
		*this = other;
	return *this;
}
Intern::~Intern() { std::cout << "\033[34mIntern destructor called\033[0m" << std::endl; }

AForm *Intern::makeForm(std::string name, std::string target)
{
	if (!name.compare("ShrubberyCreationForm"))
	{
		std::cout << "Intern creates " << name << std::endl;
		return new ShrubberyCreationForm(target);
	}
	else if (!name.compare("RobotomyRequestForm"))
	{
		std::cout << "Intern creates " << name << std::endl;
		return new RobotomyRequestForm(target);
	}
	else if (!name.compare("PresidentialPardonForm"))
	{
		std::cout << "Intern creates " << name << std::endl;
		return new PresidentialPardonForm(target);
	}
	throw UnexistentForm();
	std::cout << "\033[31mUnexistent form\033[0m" << std::endl;
	return NULL;
}

Intern::UnexistentForm::UnexistentForm()
	: msg("Not existent name form")
{}

const char* Intern::UnexistentForm::what() const throw()
{ return msg; }
