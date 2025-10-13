#ifndef BUREAUCRAT_HPP	
# define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>

class Bureaucrat
{
	private:
		std::string const name;
		int grade;
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
		Bureaucrat();
		Bureaucrat(std::string const name, int grade);
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat &operator=(const Bureaucrat &other);
		~Bureaucrat();
		std::string getName() const;
		int	getGrade() const;
		void increment(int value);
		void decrement(int value);
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat);

#endif
