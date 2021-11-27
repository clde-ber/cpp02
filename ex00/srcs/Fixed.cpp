#include "Fixed.hpp"

Fixed::Fixed( void ) : _n(0), _f(8)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const Fixed& rhs ) : _n(rhs._n), _f(8)
{
    std::cout << "Copy constructor called" << std::endl;
}

const Fixed &  Fixed::operator=( Fixed const &rhs)
{
    std::cout << "Assignation operator called" << std::endl;
    this->_n = rhs._n;
    return rhs;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const 
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->_n * pow_rebuild(2, this->_f);
}

void Fixed::setRawBits(int const raw)
{
    this->_n = raw / pow_rebuild(2, this->_f);
}