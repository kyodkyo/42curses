#include "ScavTrap.hpp"

int main(void) {
    ScavTrap a("A");
    ScavTrap b("B");

    a.attack("B");
    b.takeDamage(20);
    std::cout << "A's hit points: " << a.getHitPoints() << std::endl;
    std::cout << "A's energy points: " << a.getEnergyPoints() << std::endl;
    std::cout << "A's attack damage: " << a.getAttackDamage() << std::endl;
    std::cout << "B's hit points: " << b.getHitPoints() << std::endl;
    std::cout << "B's energy points: " << b.getEnergyPoints() << std::endl;
    std::cout << "B's attack damage: " << b.getAttackDamage() << std::endl << std::endl;

    b.attack("A");
    a.takeDamage(5);
    std::cout << "A's hit points: " << a.getHitPoints() << std::endl;
    std::cout << "A's energy points: " << a.getEnergyPoints() << std::endl;
    std::cout << "A's attack damage: " << a.getAttackDamage() << std::endl;
    std::cout << "B's hit points: " << b.getHitPoints() << std::endl;
    std::cout << "B's energy points: " << b.getEnergyPoints() << std::endl;
    std::cout << "B's attack damage: " << b.getAttackDamage() << std::endl << std::endl;

    b.beRepaired(5);
    std::cout << "B's hit points: " << b.getHitPoints() << std::endl;
    std::cout << "B's energy points: " << b.getEnergyPoints() << std::endl;
    std::cout << "B's attack damage: " << b.getAttackDamage() << std::endl;
}
