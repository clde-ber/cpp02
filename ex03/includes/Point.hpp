#ifndef POINT_H
#define POINT_H

#include "Fixed.hpp"

class Point
{
    private:
        Fixed const _x;
        Fixed const _y;
    public:
        Point( void );
        Point( Fixed const x, Fixed const y );
        Point( Point const & rhs);
        const Point & operator=( Point const &rhs);
        ~Point();
        float getX(void) const;
        void setX(int const raw) const;
        float getY(void) const;
        void setY(int const raw) const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);
Fixed side(Point const one, Point const two, Point const three);

#endif