#include "Fixed.hpp"

int Fixed::getRawBits(void) const 
{
    return (this->_n);
}

void Fixed::setRawBits(int const raw)
{
    this->_n = raw;
}