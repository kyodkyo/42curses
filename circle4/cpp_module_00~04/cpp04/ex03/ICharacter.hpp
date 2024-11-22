#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

#include <string>
#include <iostream>
#include "AMateria.hpp"

class AMateria;

class ICharacter {
    public:
        ICharacter();
        ICharacter(const ICharacter &iCharacter);
        ICharacter &operator=(const ICharacter &iCharacter);
        virtual ~ICharacter();

        virtual AMateria *getInventory(int idx) const = 0;
        virtual std::string const &getName() const = 0;
        virtual void equip(AMateria *materia) = 0;
        virtual void unequip(int idx) = 0;
        virtual void use(int idx, ICharacter &target) = 0;
};

#endif