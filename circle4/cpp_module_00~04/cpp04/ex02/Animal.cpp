#include "Animal.hpp"

Animal::Animal(){
    this->type = "Animal";
    std::cout << "Animal Default constructor called" << std::endl;
}

Animal::Animal(const Animal &animal){
    *this = animal;
    std::cout << "Animal Copy constructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &animal){
    if (this != &animal)
        this->type = animal.getType();

    std::cout << "Animal Copy assignment operator called" << std::endl;
    return *this;
}

Animal::~Animal(){
    std::cout << "Animal Destructor called" << std::endl;
}

void Animal::makeSound() const {
    std::cout << "Animal doesn't make sound..." << std::endl;
}

std::string Animal::getType() const {
    return this->type;
}
