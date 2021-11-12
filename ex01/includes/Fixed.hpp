#ifndef FIXED_H
#define FIXED_H

#include <iostream>
#include <cmath>

class Fixed
{
    private:
        int _n;
        const int _f;
    public:
        Fixed( void );
        Fixed( const Fixed& rhs );
        Fixed( const int n);
        Fixed( const float n);
        ~Fixed();
        const Fixed &  operator=( Fixed const &rhs);
        int getRawBits(void) const;
        void setRawBits(int const raw);
        float toFloat(void) const;
        int toInt(void) const;
};

std::ostream & operator<<(std::ostream & o, Fixed const & rhs);
float pow_rebuild(float nb, float pow);
//1001101001010
#endif
/*
Un constructeur qui prend un const int en paramètre et qui le converti à sa valeur
fixe(8) correspondante. La partie fractionnelle doit être initialisée comme dans
l’ex00.
• Un constructeur qui prend un const float en paramètre et et le convertit à sa
valeur fixe(8) correspondante. La partie fractionnelle doit être initialisée comme
dans l’ex00.
• Une fonction membre float toFloat(void) const; qui convertit un nombres à
point fixe en float.
• Une fonction membre int toInt(void) const; qui convertit un nombres à point
fixe en int.*/