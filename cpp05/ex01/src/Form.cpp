#include "Form.hpp"

Form::Form()
	: name("default"), sign(false), grade_exect(150), grade_sign(150)
{
	std::cout << "\033[34mForm " << this->name << " constructor called\033[0m" << std::endl;
}

Form::Form(std::string name, int ext, int sign)
	: name(name), sign(false), grade_exect(ext), grade_sign(sign)
{
	std::cout << "\033[34mForm " << this->name << " constructor called\033[0m" << std::endl;
	if (ext > 150 || sign > 150)
		throw GradeTooLowException();
	else if (ext < 1 || sign < 1)
		throw GradeTooHighException();
}

Form::Form(Form &other)
	: name(other.name), sign(other.sign), grade_exect(other.grade_exect), grade_sign(other.grade_sign)
{
	std::cout << "\033[34mForm " << this->name << " copy constructor called\033[0m" << std::endl;
}

Form &Form::operator=(Form &other)
{
	if (this != &other)
	{
		sign = other.sign;
	}
	return *this;
}

Form::~Form()
{
	std::cout << "\033[34mForm " << this->name << " destructor called\033[0m" << std::endl;
}

std::string Form::getName() const {return name;}
int Form::getGradeExect() const {return grade_exect;}
int Form::getGradeSign() const {return grade_sign;}
bool Form::getSign() const {return sign;}

Form::GradeTooHighException::GradeTooHighException()
	: msg("Grade too high")
{}

Form::GradeTooLowException::GradeTooLowException()
	: msg("Grade too low")
{}

const char* Form::GradeTooHighException::what() const throw()
{
	return msg;
}

const char* Form::GradeTooLowException::what() const throw()
{
	return msg;
}

std::ostream& operator<<(std::ostream& out, const Form& form)
{
	out << "Name: " << form.getName() << std::endl;
	out << "Signed: " << form.getSign() << std::endl;
	out << "Grade for signing: " << form.getGradeSign() << std::endl;
	out << "Grade for execution: " << form.getGradeExect() << std::endl;
	return out;
}

void Form::beSigned(Bureaucrat *bureaucrat)
{
	if (bureaucrat->getGrade() > this->grade_sign)
		throw GradeTooLowException();
	this->sign = true;
}
