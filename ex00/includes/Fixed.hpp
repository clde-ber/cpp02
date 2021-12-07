#ifndef FIXED_H
#define FIXED_H

#include <iostream>

class Fixed
{
    private:
        int _n;
        static const int _f;
        float pow_rebuild(float nb, float pow) const;
    public:
        Fixed( void );
        Fixed( const Fixed& rhs );
        ~Fixed();
        const Fixed & operator=( Fixed const &rhs);
        int getRawBits(void) const;
        void setRawBits(int const raw);
};

#endif