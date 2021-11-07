#include "Fixed.hpp"

Fixed::Fixed( void ) : _n(0), _f(8)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( Fixed& rhs ) : _n(rhs._n), _f(8)
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

int main(void)
{
    Fixed a;
    Fixed b(a);
    Fixed c;
    c = b;
    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;
    return 0;
}