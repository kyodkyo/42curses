#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed{
    private:
        int value;
        const static int bits = 8;

    public:
        Fixed();
        Fixed(const int num);
        Fixed(const float num);
        Fixed(const Fixed &fixed);
        Fixed &operator = (const Fixed& other);
        ~Fixed();
        int getRawBits(void) const;
        void setRawBits(int const raw);
        float toFloat(void) const;
        int toInt(void) const;

        bool operator>(const Fixed &fixed) const;
        bool operator<(const Fixed &fixed) const;
        bool operator>=(const Fixed &fixed) const;
        bool operator<=(const Fixed &fixed) const;
        bool operator==(const Fixed &fixed) const;
        bool operator!=(const Fixed &fixed) const;

        Fixed operator+(const Fixed &fixed) const;
        Fixed operator-(const Fixed &fixed) const;
        Fixed operator*(const Fixed &fixed) const;
        Fixed operator/(const Fixed &fixed) const;

        Fixed &operator++(void);
        const Fixed operator++(int);
        Fixed &operator--(void);
        const Fixed operator--(int);

        static Fixed &min(Fixed &a, Fixed &b);
        static const Fixed &min(const Fixed &a, const Fixed &b);
        static Fixed &max(Fixed &a, Fixed &b);
        static const Fixed &max(const Fixed &a, const Fixed &b);
};

std::ostream& operator<<(std::ostream &out, const Fixed& fixed);

#endif