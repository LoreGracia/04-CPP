#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("RobotomyRequestForm", 45, 72), target("default")
{
	std::cout << "\033[34mRobotomyRequestForm " << this->getName() << " constructor called\033[0m" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string name)
	: AForm("RobotomyRequestForm", 54, 72), target(name)
{
	std::cout << "\033[34mRobotomyRequestForm " << this->getName() << " constructor called\033[0m" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &other)
	: AForm(other)
{
	std::cout << "\033[34mRobotomyRequestForm " << this->getName() << " copy constructor called\033[0m" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm &other)
{
	if (this != &other)
		*this = other;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "\033[34mRobotomyRequestForm " << this->getName() << " destructor called\033[0m" << std::endl;
}

void RobotomyRequestForm::behaviour() const
{
	try
	{
		srand(time(NULL));
		int fo= rand() % SUCCESS_RATE;
		std::cout << "Fo : " << fo << std::endl;
		if (fo)
		{
			std::cout << "BRRRRRRR BRRRRR BRRRRRRRRRRRRRRRRRRRR" << std::endl;
			std::cout << this->getName() << " has been robotmized successfully" << std::endl;
		}
		else
			throw FailedRobotomyException();
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

RobotomyRequestForm::FailedRobotomyException::FailedRobotomyException()
	: msg("Robotomy failed")
{}

const char* RobotomyRequestForm::FailedRobotomyException::what() const throw()
{
	return msg;
}
