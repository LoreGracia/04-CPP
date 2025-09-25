#include "FragTrap.hpp"

int main( void ) {
FragTrap a("Dannyel");
FragTrap b("Frank");
a.attack("Frank");
b.takeDamage(10);
b.beRepaired(10);
a.highFivesGuys();
return 0;
}
