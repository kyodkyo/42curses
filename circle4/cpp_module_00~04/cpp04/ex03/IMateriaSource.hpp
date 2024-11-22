#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

#include <string>
#include <iostream>
#include "AMateria.hpp"

class IMateriaSource {
    public:
        IMateriaSource();
        IMateriaSource(const IMateriaSource &iMateriaSource);
        IMateriaSource &operator=(const IMateriaSource &iMateriaSource);
        virtual ~IMateriaSource();

        virtual AMateria *getStore(int idx) const = 0;
        virtual void learnMateria(AMateria *aMateria) = 0;
        virtual AMateria *createMateria(std::string const &type) = 0;
};

#endif