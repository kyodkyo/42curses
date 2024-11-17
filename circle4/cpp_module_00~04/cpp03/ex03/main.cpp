#include "DiamondTrap.hpp"

int main(void) {
    DiamondTrap a("A");
    DiamondTrap b("B");

    a.attack("B");
    b.takeDamage(30);
    std::cout << "A's hit points: " << a.getHitPoints() << std::endl;
    std::cout << "A's energy points: " << a.getEnergyPoints() << std::endl;
    std::cout << "A's attack damage: " << a.getAttackDamage() << std::endl;
    std::cout << "B's hit points: " << b.getHitPoints() << std::endl;
    std::cout << "B's energy points: " << b.getEnergyPoints() << std::endl;
    std::cout << "B's attack damage: " << b.getAttackDamage() << std::endl << std::endl;

    b.beRepaired(5);
    std::cout << "B's hit points: " << b.getHitPoints() << std::endl;
    std::cout << "B's energy points: " << b.getEnergyPoints() << std::endl;
    std::cout << "B's attack damage: " << b.getAttackDamage() << std::endl << std::endl;

    a.whoAmI();
    b.whoAmI();
    std::cout << std::endl;
}
