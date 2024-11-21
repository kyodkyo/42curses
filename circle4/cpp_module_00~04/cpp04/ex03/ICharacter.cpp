#include "ICharacter.hpp"

ICharacter::ICharacter(){
    std::cout << "ICharacter Default constructor called" << std::endl;
}

ICharacter::ICharacter(const ICharacter &iCharacter){
    *this = iCharacter;
    std::cout << "ICharacter Copy constructor called" << std::endl;
}

ICharacter &ICharacter::operator=(const ICharacter &iCharacter){
    (void)iCharacter;
    std::cout << "ICharacter Copy assignment operator called" << std::endl;
    return *this;
}

ICharacter::~ICharacter(){
    std::cout << "ICharacter Destructor called" << std::endl;
}
