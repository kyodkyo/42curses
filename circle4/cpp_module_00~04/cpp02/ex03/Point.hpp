#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point{
    private:
        Fixed const x;
        Fixed const y;

    public:
        Point();
        Point(const float x, const float y);
        Point(const Point &point);
        Point &operator=(const Point &point);
        ~Point();
        const Fixed &getX() const;
        const Fixed &getY() const;
};

std::ostream& operator<<(std::ostream &out, const Point &poiny);

Point operator-(const Point &point1, const Point &point2);
Fixed operator*(const Point &point1, const Point &point2);
bool operator~(const Fixed &fixed);
bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif