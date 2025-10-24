#include "AForm.hpp"

AForm::AForm()
	: name("default"), sign(false), grade_exect(150), grade_sign(150)
{
	std::cout << "\033[34mAForm " << this->name << " constructor called\033[0m" << std::endl;
}

AForm::AForm(std::string name, int ext, int sign)
	: name(name), sign(false), grade_exect(ext), grade_sign(sign)
{
	std::cout << "\033[34mAForm " << this->name << " constructor called\033[0m" << std::endl;
	if (ext > 150 || sign > 150)
		throw GradeTooLowException();
	else if (ext < 1 || sign < 1)
		throw GradeTooHighException();
}

AForm::AForm(AForm &other)
	: name(other.name), sign(other.sign), grade_exect(other.grade_exect), grade_sign(other.grade_sign)
{
	std::cout << "\033[34mAForm " << this->name << " copy constructor called\033[0m" << std::endl;
}

AForm &AForm::operator=(AForm &other)
{
	if (this != &other)
	{
		sign = other.sign;
	}
	return *this;
}

AForm::~AForm()
{
	std::cout << "\033[34mAForm " << this->name << " destructor called\033[0m" << std::endl;
}

std::string AForm::getName() const {return name;}
int AForm::getGradeExect() const {return grade_exect;}
int AForm::getGradeSign() const {return grade_sign;}
bool AForm::getSign() const {return sign;}

AForm::GradeTooHighException::GradeTooHighException()
	: msg("Grade too high")
{}

AForm::GradeTooLowException::GradeTooLowException()
	: msg("Grade too low")
{}

const char* AForm::GradeTooHighException::what() const throw()
{
	return msg;
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return msg;
}

std::ostream& operator<<(std::ostream& out, const AForm& form)
{
	out << "Name: " << form.getName() << std::endl;
	out << "Signed: " << form.getSign() << std::endl;
	out << "Grade for signing: " << form.getGradeSign() << std::endl;
	out << "Grade for execution: " << form.getGradeExect() << std::endl;
	return out;
}

void AForm::beSigned(Bureaucrat *bureaucrat)
{
	if (bureaucrat->getGrade() > this->grade_sign)
		throw GradeTooLowException();
	this->sign = true;
}

void AForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > this->grade_exect)
		throw AForm::GradeTooLowException();
	else if (this->sign == false)
		throw AForm::NotSignedForm();
	behaviour();
}

AForm::NotSignedForm::NotSignedForm()
	: msg("Form is not signed")
{}

const char *AForm::NotSignedForm::what() const throw()
{
	return msg;
}
