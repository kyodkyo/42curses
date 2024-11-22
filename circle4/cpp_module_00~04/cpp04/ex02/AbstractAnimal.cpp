#include "AbstractAnimal.hpp"

AbstractAnimal::AbstractAnimal(){
    this->type = "AbstractAnimal";
    std::cout << "AbstractAnimal Default constructor called" << std::endl;
}

AbstractAnimal::AbstractAnimal(const AbstractAnimal &copy){
    *this = copy;
    std::cout << "AbstractAnimal Copy constructor called" << std::endl;
}

AbstractAnimal &AbstractAnimal::operator=(const AbstractAnimal &copy){
    if (this != &copy)
        this->type = copy.getType();

    std::cout << "AbstractAnimal Copy assignment operator called" << std::endl;
    return *this;
}

AbstractAnimal::~AbstractAnimal(){
    std::cout << "AbstractAnimal Destructor called" << std::endl;
}

std::string AbstractAnimal::getType() const {
    return this->type;
}
