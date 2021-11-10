#include "Fixed.hpp"

Fixed::Fixed( void ) : _n(0), _f(8)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const Fixed& rhs ) : _n(rhs._n), _f(8)
{
    std::cout << "Copy constructor called" << std::endl;
}

Fixed::Fixed( const int n) : _n(n), _f(8)
{
    this->_n = this->_n * pow_rebuild(2, 8);
}

Fixed::Fixed( const float n) : _n(n), _f(8)
{
    this->_n = roundf(this->_n * pow_rebuild(2, 8) + (n - this->_n) * pow_rebuild(2, 8));
}

float pow_rebuild(float nb, float pow)
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

    res = this->_n / pow_rebuild(2, 8);
    return res;
}

int Fixed::toInt(void) const
{
 return this->_n / pow_rebuild(2, 8);
}

std::ostream & operator<<(std::ostream & o, Fixed const & rhs)
{
    o << rhs.toFloat();
    return o;
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
    Fixed const b(10);
    Fixed const c(42.42f);
    Fixed const d(b);

    a = Fixed(1234.4321f);
    std::cout << "a is " << a << std::endl;
    std::cout << "b is " << b << std::endl;
    std::cout << "c is " << c << std::endl;
    std::cout << "d is " << d << std::endl;

    std::cout << "a is " << a.toInt() << " as integer" << std::endl;
    std::cout << "b is " << b.toInt() << " as integer" << std::endl;
    std::cout << "c is " << c.toInt() << " as integer" << std::endl;
    std::cout << "d is " << d.toInt() << " as integer" << std::endl;
    return 0;
}