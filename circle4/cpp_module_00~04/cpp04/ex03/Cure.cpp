#include "Cure.hpp"

Cure::Cure(){
    this->type = "cure";
    std::cout << "Cure Default constructor called" << std::endl;
}

Cure::Cure(const Cure &cure) : AMateria(cure) {
    *this = cure;
    std::cout << "Cure Copy constructor called" << std::endl;
}

Cure &Cure::operator=(const Cure &cure){
    if (this != &cure)
        this->type = cure.getType();
        
    std::cout << "Cure Copy assignment operator called" << std::endl;
    return *this;
}

Cure::~Cure(){
    std::cout << "Cure Destructor called" << std::endl;
}

AMateria *Cure::clone() const {
    AMateria *cure = new Cure();
    return cure;
}

void Cure::use(ICharacter &target){
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
