#include "Cat.hpp"

Cat::Cat(){
    this->type = "Cat";
    this->brain = new Brain();
    std::cout << "Cat Default constructor called" << std::endl;
}

Cat::Cat(const Cat &cat) : AbstractAnimal(cat) {
    *this = cat;
    this->brain = new Brain();
    std::cout << "Cat Copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &cat){
    if (this != &cat)
        this->type = cat.getType();
    if (this->brain)
        delete this->brain;
    this->brain = new Brain(*cat.brain);

    std::cout << "Cat Copy assignment operator called" << std::endl;
    return *this;
}

Cat::~Cat(){
    delete this->brain;
    std::cout << "Cat Destructor called" << std::endl;
}

void Cat::makeSound() const {
    std::cout << "Meow..." << std::endl;
}

std::string Cat::getCatIdea(int idx) const {
    return brain->getIdea(idx);
}

void Cat::setCatIdea(int idx, std::string idea) {
    brain->setIdea(idx, idea);
}