#ifndef DOG_HPP
#define DOG_HPP

#include "A_Animal.hpp"
#include "Brain.hpp"

class	Dog : public A_Animal
{
	private:
		Brain* brain;
	public:
		Dog();
		Dog(const Dog &other);
		Dog &operator=(const Dog &other);
		~Dog();
		void makeSound() const;
};
#endif
