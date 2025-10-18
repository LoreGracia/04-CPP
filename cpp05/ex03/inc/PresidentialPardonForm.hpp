#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <fstream>
#include "AForm.hpp"

class PresidentialPardonForm : virtual public AForm
{
	private:
		std::string target;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string name);
		PresidentialPardonForm(PresidentialPardonForm &other);
		PresidentialPardonForm &operator=(PresidentialPardonForm &other);
		~PresidentialPardonForm();
		void behaviour() const;
};

#endif
