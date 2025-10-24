#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <fstream>
#include <cstdlib>
#include <ctime>
#include "AForm.hpp"
#define SUCCESS_RATE 2 // 50% = 1 | 0

class RobotomyRequestForm : public AForm
{
	private:
		std::string target;
		class FailedRobotomyException : public std::exception
		{
			private:
				const char* msg;
			public:
				FailedRobotomyException();
				const char* what() const throw();
		};
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string name);
		RobotomyRequestForm(RobotomyRequestForm &other);
		RobotomyRequestForm &operator=(RobotomyRequestForm &other);
		~RobotomyRequestForm();
		void behaviour() const;
};

#endif
