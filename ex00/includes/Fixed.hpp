#ifndef KAREN_H
#define KAREN_H

#include <iostream>

class Fixed
{
    private:
        int _n;
        const int _f;
    public:
        Fixed( void );
        Fixed( Fixed& rhs );
        ~Fixed();
        const Fixed &  operator=( Fixed const &rhs);
        int getRawBits(void) const;
        void setRawBits(int const raw);
};

#endif