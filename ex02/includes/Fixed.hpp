#ifndef FIXED_H
#define FIXED_H

#include <iostream>
#include <cmath>

class Fixed
{
    private:
        int _n;
        static const int _f;
        float pow_rebuild(float nb, float pow) const;
    public:
        Fixed( void );
        Fixed( const Fixed& rhs );
        Fixed( const int n);
        Fixed( const float n);
        ~Fixed();
        const Fixed & operator=( Fixed const & rhs);
        int getRawBits(void) const;
        void setRawBits(int const raw);
        float toFloat(void) const;
        int toInt(void) const;
        int operator<(Fixed const & rhs);
        int operator>(Fixed const & rhs);
        int operator<=(Fixed const & rhs);
        int operator>=(Fixed const & rhs);
        int operator==(Fixed const & rhs);
        int operator!=(Fixed const & rhs);
        Fixed operator+(Fixed const & rhs);
        Fixed operator-(Fixed const & rhs);
        Fixed operator*(Fixed const & rhs);
        Fixed operator/(Fixed const & rhs);
        Fixed& operator++( void );
        Fixed operator++(int inc);
        Fixed& operator--( void );
        Fixed operator--(int inc);
        static const Fixed& min(Fixed const & a, Fixed const & b);
        static const Fixed& max(Fixed const & a, Fixed const & b);
        static Fixed& min(Fixed & a, Fixed & b);
        static Fixed& max(Fixed & a, Fixed & b);
};

std::ostream & operator<<(std::ostream & o, Fixed const & rhs);

#endif