#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap {
    public:
        ClapTrap();
        ClapTrap(std::string name);
        ClapTrap(const ClapTrap &clapTrap);
        ClapTrap &operator=(const ClapTrap &clapTrap);
        virtual ~ClapTrap();

        std::string getName() const;
        unsigned int getHitPoints() const;
        unsigned int getEnergyPoints() const;
        unsigned int getAttackDamage() const;

        virtual void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

    protected:
        std::string name;
        unsigned int hitPoints;
        unsigned int energyPoints;
        unsigned int attackDamage;
};

#endif