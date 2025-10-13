#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
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
		Form();
		Form(std::string name, int exec, int sign);
		Form(Form &other);
		Form &operator=(Form &other);
		~Form();
		std::string getName() const;
		int getGradeExect() const;
		int getGradeSign() const;
		bool getSign() const;
		void beSigned(Bureaucrat *bureaucrat);

};

std::ostream& operator<<(std::ostream& out, const Form& form);

#endif
