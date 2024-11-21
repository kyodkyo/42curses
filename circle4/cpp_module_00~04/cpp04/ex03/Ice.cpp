#include "Ice.hpp"

Ice::Ice(){
    this->type = "ice";
    std::cout << "Ice Default constructor called" << std::endl;
}

Ice::Ice(const Ice &ice) : AMateria(ice) {
    *this = ice;
    std::cout << "Ice Copy constructor called" << std::endl;
}

Ice &Ice::operator=(const Ice &ice){
    if (this != &ice)
        this->type = ice.getType();
        
    std::cout << "Ice Copy assignment operator called" << std::endl;
    return *this;
}

Ice::~Ice(){
    std::cout << "Ice Destructor called" << std::endl;
}

AMateria *Ice::clone() const {
    AMateria *ice = new Ice();
    return ice;
}

void Ice::use(ICharacter &target){
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
