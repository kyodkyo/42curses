#include "Cat.hpp"

Cat::Cat(){
    this->type = "Cat";
    std::cout << "Cat Default constructor called" << std::endl;
}

Cat::Cat(const Cat &cat) : Animal(cat) {
    *this = cat;
    std::cout << "Cat Copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &cat){
    if (this != &cat)
        this->type = cat.getType();

    std::cout << "Cat Copy assignment operator called" << std::endl;
    return *this;
}

Cat::~Cat(){
    std::cout << "Cat Destructor called" << std::endl;
}

void Cat::makeSound() const {
    std::cout << "Meow..." << std::endl;
}
