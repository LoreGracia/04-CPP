#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include <iostream>
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
	private:
	class UnexistentForm : virtual public std::exception
	{
		private:
			const char* msg;
		public:
			UnexistentForm();
			const char* what() const throw();
	};
	public:
		Intern();
		Intern(Intern &other);
		Intern &operator=(Intern &other);
		~Intern();
		AForm *makeForm(std::string name, std::string target);
};

#endif
