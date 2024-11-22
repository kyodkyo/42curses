#include "MateriaSource.hpp"

MateriaSource::MateriaSource(){
    for(int i=0; i<4; i++)
        this->store[i] = NULL;
    
    std::cout << "MateriaSource Default constructor called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &materiaSource) : IMateriaSource() {
    *this = materiaSource;
    std::cout << "MateriaSource Copy constructor called" << std::endl;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &materiaSource){
    if (this != &materiaSource){
        for(int i=0; i<4; i++){
            delete this->store[i];

            if (materiaSource.store[i])
                this->store[i] = materiaSource.store[i].clone();
            else
                this->store[i] = NULL;
        }
    }

    std::cout << "MateriaSource Copy assignment operator called" << std::endl;
    return *this;
}

MateriaSource::~MateriaSource(){
    for(int i=0; i<4; i++)
        delete this->store[i];

    std::cout << "MateriaSource Destructor called" << std::endl;
}

AMateria *MateriaSource::getStore(int idx) const {
    return this->store[idx];
}

void MateriaSource::learnMateria(AMateria *aMateria){
    for(int i=0; i<4; i++){
        if (!this->store[i]){
            this->store[i] = aMateria->clone();
            delete aMateria;
            break;
        }
    }
}

AMateria *MateriaSource::createMateria(std::string const &type){
    AMateria *result = NULL;

    for(int i=0; i<4; i++){
        if (this->store[i]->getType() == type){
            if (type == "ice")
                result = new Ice();
            else if (type == "cure")
                result = new Cure();
            break;
        }
    }

    return result;
}
