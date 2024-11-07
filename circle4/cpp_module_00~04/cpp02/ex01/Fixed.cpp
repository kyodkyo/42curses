#include "Fixed.hpp"

Fixed::Fixed() : value(0) { 
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int num) {
    std::cout << "Int constructor called" << std::endl;
    this->value = num << this->bits;
}

Fixed::Fixed(const float num) {
    std::cout << "Float constructor called" << std::endl;
    this->value = roundf(num * (1 << this->bits));
}

Fixed::Fixed(const Fixed& fixed) {
    std::cout << "Copy constructor called" << std::endl;
    *this = fixed;
}

Fixed& Fixed::operator = (const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;

    if (this != &other)
        this->value = other.getRawBits();

    return *this;
}

Fixed::~Fixed(){
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return this->value;
}

void Fixed::setRawBits(int const raw){
    this->value = raw;
}

float Fixed::toFloat(void) const {
    return ((float)this->value) / (1 << this->bits);
}

int Fixed::toInt(void) const {
    return this->value >> this->bits;
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed) {
    out << fixed.toFloat();
    return (out);
}