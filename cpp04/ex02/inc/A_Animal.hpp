#ifndef A_ANIMAL_HPP
#define A_ANIMAL_HPP

#include <string>
#include <iostream>

class	A_Animal
{	
	protected:
		std::string type;
	public:
		A_Animal();
		A_Animal(std::string name);
		A_Animal(const A_Animal &other);
		A_Animal &operator=(const A_Animal &other);
		virtual ~A_Animal() = 0;
		void makeSound() const;
		std::string	getType() const;
};
#endif
