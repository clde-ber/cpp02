#include "Fixed.hpp"

int const Fixed::_f = 8;

Fixed::Fixed( void ) : _n(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const Fixed & rhs ) : _n(rhs._n)
{
    std::cout << "Copy constructor called" << std::endl;
}

Fixed::Fixed( const int n ) : _n(n)
{
    std::cout << "Int constructor called" << std::endl;
    _n = _n * pow_rebuild(2, _f);
}

Fixed::Fixed( const float n ) : _n(n)
{
    std::cout << "Float constructor called" << std::endl;
    _n = roundf(_n * pow_rebuild(2, _f) + (n - _n) * pow_rebuild(2, _f));
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

float Fixed::pow_rebuild(float nb, float pow) const
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

int Fixed::getRawBits(void) const 
{
    return (_n);
}

void Fixed::setRawBits(int const raw)
{
    _n = raw;
}

float Fixed::toFloat(void) const
{
    float res(0);

    res = _n / pow_rebuild(2, _f);
    return res;
}

int Fixed::toInt(void) const
{
 return _n / pow_rebuild(2, _f);
}

const Fixed & Fixed::operator=( Fixed const & rhs)
{
    std::cout << "Assignation operator called" << std::endl;
    new (this) Fixed(rhs);
    return *this;
}

std::ostream & operator<<(std::ostream & o, Fixed const & rhs)
{
    o << rhs.toFloat();
    return o;
}