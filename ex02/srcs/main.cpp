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
    Fixed a;
    Fixed const b(Fixed(5.05f) * Fixed(2));
    Fixed c(1.02f);
    c = b;

    std::cout << "**********       c       **********" << std::endl;
    std::cout << c << std::endl;
    std::cout << "**********       a       **********" << std::endl;
    std::cout << a << std::endl;
    std::cout << "**********     ++a       **********" << std::endl;
    std::cout << ++a << std::endl;
    std::cout << "**********       a       **********" << std::endl;
    std::cout << a << std::endl;
    std::cout << "**********       a++     **********" << std::endl;
    std::cout << a++ << std::endl;
    std::cout << "**********       a      **********" << std::endl;
    std::cout << a << std::endl;
    std::cout << "**********     --a      **********" << std::endl;
    std::cout << --a << std::endl;
    std::cout << "**********       a      **********" << std::endl;
    std::cout << a << std::endl;
    std::cout << "**********       a--    **********" << std::endl;
    std::cout << a-- << std::endl;
    std::cout << "**********       a      **********" << std::endl;
    std::cout << a << std::endl;
    std::cout << "**********     ++a       **********" << std::endl;
    std::cout << ++a << std::endl;
    std::cout << "********** fixed output **********" << std::endl;
    std::cout << a - a << std::endl;
    std::cout << "********** float output **********" << std::endl;
    std::cout << float(0.00390625f - 0.00390625f) << std::endl;
    std::cout << "********** fixed output **********" << std::endl;
    std::cout << a + a << std::endl;
    std::cout << "********** float output **********" << std::endl;
    std::cout << float(0.00390625f + 0.00390625f) << std::endl;
    std::cout << "********** fixed output **********" << std::endl;
    std::cout << "/!\\     too high precision     /!\\" << std::endl;
    std::cout << a * a << std::endl;
    std::cout << "********** float output **********" << std::endl;
    std::cout << float(0.00390625f * 0.00390625f) << std::endl;
    std::cout << "********** fixed output **********" << std::endl;
    std::cout << a / a << std::endl;
    std::cout << "********** float output **********" << std::endl;
    std::cout << float(0.00390625f / 0.00390625f) << std::endl;
    std::cout << "**********       b      **********" << std::endl;
    std::cout << b << std::endl;
    std::cout << "**********    max a b   **********" << std::endl;
    std::cout << Fixed::max(a, b) << std::endl;
    std::cout << "**********    min a b   **********" << std::endl;
    std::cout << Fixed::min(a, b) << std::endl;
}