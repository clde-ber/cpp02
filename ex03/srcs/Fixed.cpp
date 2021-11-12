#include "Fixed.hpp"
#include "Point.hpp"

int Fixed::getRawBits(void) const 
{
    return (this->_n);
}

void Fixed::setRawBits(int const raw)
{
    this->_n = raw;
}

Fixed::Fixed( void ) : _n(0), _f(8)
{
}

Fixed::Fixed( const Fixed& rhs ) : _n(rhs._n), _f(8)
{
}

Fixed::Fixed( const int n) : _n(n), _f(8)
{
    this->_n = this->_n * pow_rebuild(2, this->_f);
}

Fixed::Fixed( const float n) : _n(n), _f(8)
{
    this->_n = roundf(this->_n * pow_rebuild(2, this->_f) + (n - this->_n) * pow_rebuild(2, this->_f));
}

float Fixed::pow_rebuild(float nb, float pow)
{
    float res(1);

    for (int i = 0; i < pow; i++)
        res = res * nb;
    if (pow < 0)
    {
        for (int i = 0; i < -pow; i++)
            res = res * 1 / nb;
    }
    return res;
}

float Fixed::toFloat(void) const
{
    float res(0);

    res = this->_n / pow_rebuild(2, this->_f);
    return res;
}

int Fixed::toInt(void) const
{
 return this->_n / pow_rebuild(2, this->_f);
}

std::ostream & operator<<(std::ostream & o, Fixed const & rhs)
{
    o << rhs.toFloat();
    return o;
}

const Fixed &  Fixed::operator=( Fixed const &rhs) const
{
    return rhs;
}

Fixed::~Fixed()
{
}

int Fixed::operator<(Fixed const & rhs)
{
    if (this->_n < rhs._n)
        return 1;
    return 0;
}

int Fixed::operator>(Fixed const & rhs)
{
    if (this->_n > rhs._n)
        return 1;
    return 0;
}

int Fixed::operator<=(Fixed const & rhs)
{
    if (this->_n <= rhs._n)
        return 1;
    return 0;
}

int Fixed::operator>=(Fixed const & rhs)
{
    if (this->_n >= rhs._n)
        return 1;
    return 0;
}

int Fixed::operator==(Fixed const & rhs)
{
    if (this->_n == rhs._n)
        return 1;
    return 0;
}

int Fixed::operator!=(Fixed const & rhs)
{
    if (this->_n != rhs._n)
        return 1;
    return 0;
}

Fixed Fixed::operator+(Fixed const & rhs)
{
    return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed Fixed::operator-(Fixed const & rhs)
{
    return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed Fixed::operator*(Fixed const & rhs)
{
    return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed Fixed::operator/(Fixed const & rhs)
{
    return Fixed(this->toFloat() / rhs.toFloat());
}

Fixed& Fixed::operator++( void )
{
    ++this->_n;
    return *this;
}
//Fixed Fixed::operator++(int inc)
//{
//    (void)inc;
//    this->setRawBits(this->_n + 1 * pow_rebuild(2, this->_f));
//    this->setRawBits(this->toFloat());
//    return *this;
//}

Fixed Fixed::operator++(int)
{
    Fixed tmp = *this;
    this->_n++;
    return tmp;
}

Fixed& Fixed::operator--( void )
{
    --this->_n;
    return *this;
}
//Fixed Fixed::operator++(int inc)
//{
//    (void)inc;
//    this->setRawBits(this->_n + 1 * pow_rebuild(2, this->_f));
//    this->setRawBits(this->toFloat());
//    return *this;
//}

Fixed Fixed::operator--(int)
{
    Fixed tmp = *this;
    this->_n--;
    return tmp;
}

const Fixed& Fixed::min(Fixed const & a, Fixed const & b)
{
    if (a._n < b._n)
        return a;
    return b;
}

const Fixed& Fixed::max(Fixed const & a, Fixed const & b)
{
    if (a._n > b._n)
         return a;
    return b;
}

Fixed& Fixed::min(Fixed & a, Fixed & b)
{
    if (a._n < b._n)
         return a;
    return b;
}

Fixed& Fixed::max(Fixed & a, Fixed & b)
{
    if (a._n > b._n)
         return a;
    return b;
}