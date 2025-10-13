#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <string>
#include <iostream>
#include <exception>
#include "AForm.hpp"

class ShrubberyCreationForm
{
	private:
		const std::string name;
		bool sign;
		const int grade_exect;
		const int grade_sign;
		class GradeTooHighException : public std::exception
		{
			private:
				const char* msg;
			public:
				GradeTooHighException();
				const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			private:
				const char* msg;
			public:
				GradeTooLowException();
				const char* what() const throw();
		};
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string name);
		ShrubberyCreationForm(ShrubberyCreationForm &other);
		ShrubberyCreationForm &operator=(ShrubberyCreationForm &other);
		~ShrubberyCreationForm();
		std::string getName() const;
		int getGradeExect() const;
		int getGradeSign() const;
		bool getSign() const;
		void beSigned(Bureaucrat *bureaucrat);

};

std::ostream& operator<<(std::ostream& out, const ShrubberyCreationForm& form);

#endif
