#include "Fixed.hpp"

int const Fixed::_f = 8;

Fixed::Fixed( void ) : _n(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const Fixed& rhs ) : _n(rhs._n)
{
    std::cout << "Copy constructor called" << std::endl;
}

const Fixed & Fixed::operator=( Fixed const & rhs)
{
    _n = rhs._n;
    std::cout << "Assignation operator called" << std::endl;
    return rhs;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const 
{
    std::cout << "getRawBits member function called" << std::endl;
    return _n * pow_rebuild(2, _f);
}

void Fixed::setRawBits(int const raw)
{
    _n = raw / pow_rebuild(2, _f);
}