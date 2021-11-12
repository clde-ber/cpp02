#include "Fixed.hpp"
#include "Point.hpp"

int main( void )
{
    Point a(Fixed(1.04555f), Fixed(1.0328906f));
    Point b(Fixed(3.02355f), Fixed(3.0157654f));
    Point c(Fixed(2.06595f), Fixed(4.0877893f));
    Fixed x(0);
    Fixed y(0);

    while (x.toFloat() < 5)
    {
        while (y.toFloat() < 5)
        {
            Point pt(x.toFloat(), y.toFloat());
            if (bsp(a, b, c, pt) == true)
                std::cout << "*";
            y++;
        }
        std::cout << std::endl;
        y.setRawBits(0);
        x++;
    }
}