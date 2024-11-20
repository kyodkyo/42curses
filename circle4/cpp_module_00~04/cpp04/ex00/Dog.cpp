#include "Dog.hpp"

Dog::Dog(){
    this->type = "Dog";
    std::cout << "Dog Default constructor called" << std::endl;
}

Dog::Dog(const Dog &dog) : Animal(dog) {
    *this = dog;
    std::cout << "Dog Copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &dog){
    if (this != &dog)
        this->type = dog.getType();

    std::cout << "Dog Copy assignment operator called" << std::endl;
    return *this;
}

Dog::~Dog(){
    std::cout << "Dog Destructor called" << std::endl;
}

void Dog::makeSound() const {
    std::cout << "Bark Bark!" << std::endl;
}