#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(){
    this->type = "WrongAnimal";
    std::cout << "WrongAnimal Default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &wrongAnimal){
    *this = wrongAnimal;
    std::cout << "WrongAnimal Copy constructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &wrongAnimal){
    if (this != &wrongAnimal)
        this->type = wrongAnimal.getType();

    std::cout << "WrongAnimal Copy assignment operator called" << std::endl;
    return *this;
}

WrongAnimal::~WrongAnimal(){
    std::cout << "WrongAnimal Destructor called" << std::endl;
}

void WrongAnimal::makeSound() const {
    std::cout << "Rrrrr..?" << std::endl;
}

std::string WrongAnimal::getType() const {
    return this->type;
}
