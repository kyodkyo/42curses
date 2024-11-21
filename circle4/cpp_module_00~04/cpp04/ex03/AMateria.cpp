#include "AMateria.hpp"

AMateria::AMateria(){
    this->type = "Default";
    std::cout << "AMateria Default constructor called" << std::endl;
}

AMateria::AMateria(std::string const &type){
    this->type = type;
    std::cout << "AMateria Type constructor called" << std::endl;
}

AMateria::AMateria(const AMateria &aMateria){
    *this = aMateria;
    std::cout << "AMateria Copy constructor called" << std::endl;
}

AMateria &AMateria::operator=(const AMateria &aMateria){
    if (this != &aMateria)
        this->type = aMateria.getType();

    std::cout << "AMateria Copy assignment operator called" << std::endl;
    return *this;
}

AMateria::~AMateria(){ 
    std::cout << "AMateria Destructor called" << std::endl;
}

std::string const &AMateria::getType() const {
    return this->type;
}

void AMateria::use(ICharacter &target){
    std::cout << "AMateria use on " << target.getName() << std::endl;
}
