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
	std::string type[NUMFORM];
	type[0] =  "ShrubberyCreationForm";
	type[1] =  "RobotomyRequestForm";
	type[2] =  "PresidentialPardonForm";
	int i = 0;
	while (i < NUMFORM && type[i] != name)
		i++;
	switch (i)
	{
	case 0:
		std::cout << "Intern creates " << name << std::endl;
		return new ShrubberyCreationForm(target);
	case 1:
		std::cout << "Intern creates " << name << std::endl;
		return new RobotomyRequestForm(target);
	case 2:
		std::cout << "Intern creates " << name << std::endl;
		return new PresidentialPardonForm(target);
	default:
		throw UnexistentForm();
	}
}

Intern::UnexistentForm::UnexistentForm()
	: msg("Not existent name form")
{}

const char* Intern::UnexistentForm::what() const throw()
{ return msg; }
