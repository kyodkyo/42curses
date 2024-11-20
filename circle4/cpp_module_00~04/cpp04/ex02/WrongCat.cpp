#include "WrongCat.hpp"

WrongCat::WrongCat(){
    this->type = "WrongCat";
    std::cout << "WrongCat Default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &wrongCat) : WrongAnimal(wrongCat) {
    *this = wrongCat;
    std::cout << "WrongCat Copy constructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &wrongCat){
    if (this != &wrongCat)
        this->type = wrongCat.getType();

    std::cout << "WrongCat Copy assignment operator called" << std::endl;
    return *this;
}

WrongCat::~WrongCat(){
    std::cout << "WrongCat Destructor called" << std::endl;
}

// void WrongCat::makeSound() const {
//     std::cout << "Mrrrr..?" << std::endl;
// }
