#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
    public:
        FragTrap();
        FragTrap(std::string name);
        FragTrap(const FragTrap &fragTrap);
        FragTrap &operator=(const FragTrap &FragTrap);
        ~FragTrap();
        void highFivesGuys();
};

#endif