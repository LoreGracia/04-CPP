#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("default", 137, 145)
{
	std::cout << "\033[34mShrubberyCreationForm " << this->getName() << " constructor called\033[0m" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string name)
	: AForm(name, 137, 145)
{
	std::cout << "\033[34mShrubberyCreationForm " << this->getName() << " constructor called\033[0m" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &other)
	: AForm(other)
{
	std::cout << "\033[34mShrubberyCreationForm " << this->getName() << " copy constructor called\033[0m" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm &other)
{
	if (this != &other)
		*this = other;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "\033[34mShrubberyCreationForm " << this->getName() << " destructor called\033[0m" << std::endl;
}

void ShrubberyCreationForm::behaviour() const
{
	std::string f_name(this->getName() + "_shrubbery");
	std::ofstream f(f_name.c_str());
	if (!f)
		throw "Unable to create file";
	srand(time(NULL));
	int fo= rand() % MAX;
	switch (fo)
	{
	case 1:
		f << AUTUM;
		break;
	case 2:
		f << THREE;
		break;
	case 3:
		f << SQUIRREL;
		break;
	case 4:
		f << BONSAI;
		break;
	default:
		f << TREE;
		break;
	}
	f.close();
}
