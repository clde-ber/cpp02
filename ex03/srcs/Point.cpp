#include "Point.hpp"
#include "Fixed.hpp"

Point::Point( void ) : _x(0), _y(0)
{
}

Point::Point( Fixed const x, Fixed const y ) : _x(x), _y(y)
{
}

Point::Point( Point const &rhs) : _x(rhs._x), _y(rhs._y)
{
}

Point::~Point( void )
{
}

const Point& Point::operator=( Point const &rhs)
{
    return rhs;
}

float Point::getX(void) const 
{
    return this->_x.toFloat();
}

void Point::setX(int const raw) const
{
    this->_x = raw;
}

float Point::getY(void) const 
{
    return this->_y.toFloat();
}

void Point::setY(int const raw) const
{
    this->_y = raw;
}
/*
p = p0 + (p1 - p0) * s + (p2 - p0) * t

The point p is inside the triangle if 0 <= s <= 1 and 0 <= t <= 1 and s + t <= 1.

s,t and 1 - s - t are called the barycentric coordinates of the point p.*/

Fixed sign (Point p1, Point p2, Point p3)
{
    return Fixed((p1.getX() - p3.getX()) * (p2.getY() - p3.getY()) - (p2.getX() - p3.getX()) * (p1.getY() - p3.getY()));
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    Fixed distA(sign(point, a, b));
    Fixed distB(sign(point, b, c));
    Fixed distC(sign(point, c, a));
    bool has_pos;
    bool has_neg;

    has_neg = (distA.getRawBits() < 0) || (distB.getRawBits() < 0) || (distC.getRawBits() < 0);
    has_pos = (distA.getRawBits() > 0) || (distB.getRawBits() > 0) || (distC.getRawBits() > 0);
    return !(has_neg && has_pos);
}