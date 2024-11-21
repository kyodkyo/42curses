#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter {
    public:
        Character();
        Character(std::string name);
        Character(const Character &copy);
        Character &operator=(const Character &copy);
        ~Character();

        void printInventory() const;
        std::string const &getName() const;
        void equip(AMateria *materia);
        void unequip(int idx);
        void use(int idx, ICharacter &target);

    private:
        std::string name;
        AMateria *inventory[4];
};

#endif