#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
    public:
        DiamondTrap();
        DiamondTrap(std::string name);
        DiamondTrap(const DiamondTrap &diamondTrap);
        DiamondTrap &operator=(const DiamondTrap &diamondTrap);
        ~DiamondTrap();
        void whoAmI();

    private:
        std::string name;

};

#endif