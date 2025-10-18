#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	try
	{
		Intern intern;
		AForm *shrubberyform = intern.makeForm("ShrubberyCreationForm", "Home");
		AForm *extraform = intern.makeForm("Extra", "Home");
		std::cout << *shrubberyform << std::endl;
		std::cout << *extraform << std::endl;
		delete shrubberyform;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "____________________________________________" << std::endl;
	try
	{
		Intern intern;
		AForm *shrubberyform = intern.makeForm("ShrubberyCreationForm", "Home");
		AForm *robotomyform = intern.makeForm("RobotomyRequestForm", "Taha");
		AForm *presidentialform = intern.makeForm("PresidentialPardonForm", "you");
		Bureaucrat harl("Harl", 15);
		std::cout << *shrubberyform << std::endl;
		std::cout << *robotomyform << std::endl;
		std::cout << *presidentialform << std::endl;
		std::cout << harl << std::endl;
		harl.signForm(*shrubberyform);
		harl.signForm(*robotomyform);
		harl.signForm(*presidentialform);
		harl.executeForm(*shrubberyform);
		harl.executeForm(*robotomyform);
		harl.executeForm(*presidentialform);
		delete shrubberyform;
		delete robotomyform;
		delete presidentialform;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}
