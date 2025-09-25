#include "ScavTrap.hpp"

int main( void ) {
ScavTrap a("Dannyel");
ScavTrap b("Frank");
a.attack("Frank");
b.takeDamage(10);
b.beRepaired(10);
a.guardGate();
return 0;
}
