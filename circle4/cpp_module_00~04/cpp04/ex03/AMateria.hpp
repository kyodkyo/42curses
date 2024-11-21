#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <string>
#include <iostream>
#include "ICharacter.hpp"

class ICharacter;

class AMateria {
    public:
        AMateria();
        AMateria(std::string const &type);
        AMateria(const AMateria &aMateria);
        AMateria &operator=(const AMateria &aMateria);
        virtual ~AMateria();

        std::string const &getType() const;
        virtual AMateria *clone() const = 0;
        virtual void use(ICharacter &target);

    protected:
        std::string type;
};

#endif