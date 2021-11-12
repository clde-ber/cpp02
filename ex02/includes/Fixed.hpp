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
        static float pow_rebuild(float nb, float pow);
};

/*
La fonction membre statique min qui prend une référence sur deux nombres a point
fixe et qui renvoie une réference vers le plus petit, et un overload qui prend deux
references sur deux nombres à point fixe et qui renvoie une réference vers la plus
petite valeur.
• La fonction membre statique max qui prend une référence sur deux nombres à point
fixe et qui renvoie une réference vers le plus grand, et un overload qui prend une
reférence sur deux nombres à point fixe et qui renvoie une réference vers la plus
grande valeur.*/
std::ostream & operator<<(std::ostream & o, Fixed const & rhs);
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