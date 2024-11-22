#include "Dog.hpp"

Dog::Dog(){
    this->type = "Dog";
    this->brain = new Brain();
    std::cout << "Dog Default constructor called" << std::endl;
}

Dog::Dog(const Dog &dog) : AbstractAnimal(dog) {
    this->brain = new Brain();
    *this = dog;
    std::cout << "Dog Copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &dog){
    if (this != &dog)
        this->type = dog.getType();
    if (this->brain)
        delete this->brain;
    this->brain = new Brain(*dog.brain);

    std::cout << "Dog Copy assignment operator called" << std::endl;
    return *this;
}

Dog::~Dog(){
    delete this->brain;
    std::cout << "Dog Destructor called" << std::endl;
}

void Dog::makeSound() const {
    std::cout << "Bark Bark!" << std::endl;
}

std::string Dog::getDogIdea(int idx) const {
    return brain->getIdea(idx);
}

void Dog::setDogIdea(int idx, std::string idea) {
    brain->setIdea(idx, idea);
}