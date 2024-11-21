#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

class MateriaSource : public IMateriaSource {
    public:
        MateriaSource();
        MateriaSource(const MateriaSource &materiaSource);
        MateriaSource &operator=(const MateriaSource &materiaSource);
        ~MateriaSource();

        void learnMateria(AMateria *aMateria);
        AMateria *createMateria(std::string const &type);

    private:
        AMateria *store[4];
};

#endif