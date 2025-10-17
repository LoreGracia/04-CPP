#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
	: name("default"), grade(150)
{}

Bureaucrat::Bureaucrat(std::string const name, int grade)
	: name(name)
{
	std::cout << "\033[34mBureaucrat " << this->name << " constructor called\033[0m" << std::endl;
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
	: name(other.name), grade(other.grade)
{}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
	{
		grade = other.grade;
	}
	return *this; 
}

Bureaucrat::~Bureaucrat()
{}

std::string Bureaucrat::getName() const
{
	return (this->name);
}

int	Bureaucrat::getGrade() const
{return (this->grade);}

void Bureaucrat::increment(int value)
{
	if (grade - value > 0)
		grade -= value;
	else
		throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::decrement(int value)
{
	if (grade + value < 151)
		grade += value;
	else
		throw Bureaucrat::GradeTooLowException();
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat is now grade " << bureaucrat.getGrade() << std::endl;
	return (out);
}

Bureaucrat::GradeTooHighException::GradeTooHighException()
	: msg("\033[31mGrade too high\033[0m")
{}
Bureaucrat::GradeTooLowException::GradeTooLowException()
	: msg("\033[31mGrade too low\033[0m")
{}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{return msg;}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{return msg;}

void Bureaucrat::signForm(Form& form)
{
	try 
	{
		form.beSigned(this);
		std::cout << this->name << " signed " << form.getName() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << this->name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
	}
}
