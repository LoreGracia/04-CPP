#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp" 

class Cure : virtual public AMateria
{
	public:
		Cure();
		Cure(const Cure &other);
		Cure &operator=(const Cure &other);
		~Cure();
		Cure* clone() const;
		void use(ICharacter& target);
};

#endif
