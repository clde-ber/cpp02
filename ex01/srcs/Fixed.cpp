#include "Fixed.hpp"

Fixed::Fixed( void ) : _n(0), _f(8)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const Fixed & rhs ) : _n(rhs._n), _f(rhs._f)
{
    std::cout << "Copy constructor called" << std::endl;
}

Fixed::Fixed( const int n ) : _n(n), _f(8)
{
    this->_n = this->_n * pow_rebuild(2, this->_f);
}

Fixed::Fixed( const float n ) : _n(n), _f(8)
{
    this->_n = roundf(this->_n * pow_rebuild(2, this->_f) + (n - this->_n) * pow_rebuild(2, this->_f));
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const 
{
    return (this->_n);
}

void Fixed::setRawBits(int const raw)
{
    this->_n = raw;
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

const Fixed &  Fixed::operator=( Fixed const &rhs)
{
    std::cout << "Assignation operator called" << std::endl;
    return rhs;
}

std::ostream & operator<<(std::ostream & o, Fixed const & rhs)
{
    o << rhs.toFloat();
    return o;
}