#include "Point.hpp"

Point::Point() : x(0), y(0) {
}

Point::Point(const float x, const float y) : x(x), y(y) {
}

Point::Point(const Point &point) : x(point.getX()), y(point.getY()) {
}

Point &Point::operator=(const Point &point) {
    if (this != &point){
        const_cast<Fixed&>(x) = point.getX();
        const_cast<Fixed&>(y) = point.getY();
    }

    return *this;
}

Point::~Point(){
}

const Fixed &Point::getX() const {
    return this->x;
}

const Fixed &Point::getY() const {
    return this->y;
}

std::ostream &operator<<(std::ostream &ofs, const Point &point){
  return ofs << "( " << point.getX().toFloat() << ", " << point.getY().toFloat() << " )";
}
