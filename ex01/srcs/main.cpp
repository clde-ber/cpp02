#include "Fixed.hpp"

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

int main(void)
{
    Fixed a(1234.4321f);
    Fixed const b(10);
    Fixed const c(42.42f);
    Fixed const d(b);

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