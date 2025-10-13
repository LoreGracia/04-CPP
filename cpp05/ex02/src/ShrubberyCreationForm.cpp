#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
	: name("default"), sign(false), grade_exect(137), grade_sign(145)
{}

ShrubberyCreationForm::ShrubberyCreationForm(std::string name)
	: name(name), sign(false), grade_exect(137), grade_sign(145)
{
	std::cout << "\033[34mShrubberyCreationForm " << this->name << " constructor called\033[0m" << std::endl;
	if (ext > 150 || sign > 150)
		throw GradeTooLowException();
	else if (ext < 1 || sign < 1)
		throw GradeTooHighException();
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &other)
	: name(other.name), sign(other.sign), grade_exect(other.grade_exect), grade_sign(other.grade_sign)
{}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm &other)
{
	if (this != &other)
	{
		sign = other.sign;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

std::string ShrubberyCreationForm::getName() const {return name;}
int ShrubberyCreationForm::getGradeExect() const {return grade_exect;}
int ShrubberyCreationForm::getGradeSign() const {return grade_sign;}
bool ShrubberyCreationForm::getSign() const {return sign;}

ShrubberyCreationForm::GradeTooHighException::GradeTooHighException()
	: msg("Grade too high")
{}

ShrubberyCreationForm::GradeTooLowException::GradeTooLowException()
	: msg("Grade too low")
{}

const char* ShrubberyCreationForm::GradeTooHighException::what() const throw()
{
	return msg;
}

const char* ShrubberyCreationForm::GradeTooLowException::what() const throw()
{
	return msg;
}

std::ostream& operator<<(std::ostream& out, const ShrubberyCreationForm& form)
{
	out << "Name: " << form.getName() << std::endl;
	out << "Signed: " << form.getSign() << std::endl;
	out << "Grade for signing: " << form.getGradeSign() << std::endl;
	out << "Grade for execution: " << form.getGradeExect() << std::endl;
	return out;
}

void ShrubberyCreationForm::beSigned(Bureaucrat *bureaucrat)
{
	if (bureaucrat->getGrade() <= this->grade_sign)
		this->sign = true;
	else
	{
		throw GradeTooLowException();
	}
}
