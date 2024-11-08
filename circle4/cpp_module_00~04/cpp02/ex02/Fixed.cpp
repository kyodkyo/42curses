#include "Fixed.hpp"

Fixed::Fixed() : value(0) { 
}

Fixed::Fixed(const int num) {
    this->value = num << this->bits;
}

Fixed::Fixed(const float num) {
    this->value = roundf(num * (1 << this->bits));
}

Fixed::Fixed(const Fixed &fixed) {
    *this = fixed;
}

Fixed& Fixed::operator=(const Fixed& other) {
    if (this != &other)
        this->value = other.getRawBits();

    return *this;
}

Fixed::~Fixed(){
}

int Fixed::getRawBits(void) const {
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

bool Fixed::operator>(const Fixed &fixed) const {
    return this->value > fixed.getRawBits();
}

bool Fixed::operator<(const Fixed &fixed) const {
    return this->value < fixed.getRawBits();
}

bool Fixed::operator>=(const Fixed &fixed) const {
    return this->value >= fixed.getRawBits();
}

bool Fixed::operator<=(const Fixed &fixed) const {
    return this->value <= fixed.getRawBits();
}

bool Fixed::operator==(const Fixed &fixed) const {
    return this->value == fixed.getRawBits();
}

bool Fixed::operator!=(const Fixed &fixed) const {
    return this->value != fixed.getRawBits();
}

Fixed Fixed::operator+(const Fixed &fixed) const {
    return Fixed(this->toFloat() + fixed.toFloat());
}

Fixed Fixed::operator-(const Fixed &fixed) const {
    return Fixed(this->toFloat() - fixed.toFloat());
}

Fixed Fixed::operator*(const Fixed &fixed) const {
    return Fixed(this->toFloat() * fixed.toFloat());
}

Fixed Fixed::operator/(const Fixed &fixed) const {
    return Fixed(this->toFloat() / fixed.toFloat());
}

Fixed &Fixed::operator++(void) {
    this->value++;
    return (*this);
}

const Fixed Fixed::operator++(int) {
    const Fixed tmp(*this);
    this->value++;
    return tmp;
}

Fixed &Fixed::operator--(void) {
    this->value--;
    return (*this);
}

const Fixed Fixed::operator--(int) {
    const Fixed tmp(*this);
    this->value--;
    return tmp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
    if (a <= b)
        return a;
    return b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
    if (a <= b)
        return a;
    return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
    if (a >= b)
        return a;
    return b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
    if (a >= b)
        return a;
    return b;
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed) {
    out << fixed.toFloat();
    return (out);
}