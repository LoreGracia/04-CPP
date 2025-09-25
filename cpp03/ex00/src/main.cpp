#include "ClapTrap.hpp"

int main( void ) {
	ClapTrap a("Dannyel");
	ClapTrap b("Frank");
	a.attack("Frank");
	b.takeDamage(10);
	b.beRepaired(10);
	return 0;
}
