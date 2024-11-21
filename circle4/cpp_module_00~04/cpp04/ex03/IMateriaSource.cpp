#include "IMateriaSource.hpp"

IMateriaSource::IMateriaSource(){
    std::cout << "IMateriaSource Default constructor called" << std::endl;
}

IMateriaSource::IMateriaSource(const IMateriaSource &iMateriaSource){
    *this = iMateriaSource;
    std::cout << "IMateriaSource Copy constructor called" << std::endl;
}

IMateriaSource &IMateriaSource::operator=(const IMateriaSource &iMateriaSource){
    (void)iMateriaSource;
    std::cout << "IMateriaSource Copy assignment operator called" << std::endl;
    return *this;
}

IMateriaSource::~IMateriaSource(){
    std::cout << "IMateriaSource Destructor called" << std::endl;
}
