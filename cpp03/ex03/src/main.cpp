#include "DiamondTrap.hpp"

int main( void ) {
DiamondTrap a("Dannyel");
DiamondTrap b("Frank");
a.attack("Frank");
b.beRepaired(10);
a.guardGate();
a.highFivesGuys();
b.whoAmI();
a.whoAmI();
return 0;
}
