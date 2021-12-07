#include "Fixed.hpp"

/*
**  Floats:
**
**  we often discover that floating point numbers that look the same do not necessarily satisfy C's "==" test
**  Floating pt arithmetic -> precision
**  poor accuracy
**  ex perfect cube
**  not every fraction can be represented exactly in binary vs integer
**  Zero is not the only "special case" float.
** There are also representations for positive and negative infinity,
** and for a not-a-number (NaN) value...
**
**  seeeeeeeemmmmmmmmmmmmmmmmmmmmmmm
**  31                             0
**
**  s = sign bit, e = exponent, m = mantissa
**
**  Using the smallest representable float is not necessarily a good practice, because it sets
**  equality when there is sometimes no equality (smaller numbers than epsilon)
**
**  when you're defining how close is close enough,
**  you need to talk about how many significant digits you want to match
**
**  Arithmetic underflow can occur when the true result of a floating point operation
**  is smaller in magnitude (that is, closer to zero) than the smallest value
**  representable as a normal floating point number in the target datatype.
**
**
**  Integers:
**  
**  Bits representing an integer are interpreted literally as a binary number,
**  while bits in a floating point number have a more complicated interpretation
**  "Accuracy" refers to how close a measurement is to the true value,
**  whereas "precision" has to do with how much information you have about a quantity
**  Integer arithmetic -> accuracy
**  ex sphere
**  risk of overflow
*/


/*  
**  performance is sometimes more important than precision...
**
**  Recall that a binary number:
**
**  1101012
**
**  represents the value:
**
**  1 * 25 + 1 * 24 + 0 * 23 + 1 * 22 + 0* 21 + 1 * 20
**
**  = 32 + 16 + 4 + 1
**
**  = 5310
**
**  A binary point is like the decimal point in a decimal system.
**  It acts as a divider between the integer and the fractional part of a number.
**  Binary representation : 
**  A binary point represents the coefficient of the term 2^0 = 1
**  vs decimal representation 10^0
**  For example, the number:
**    1         1         0         1         0   .     1
**  represents the value:
**  = 1 * 2^4 + 1 * 2^3 + 0 * 2^2 + 1 * 2^1 + 0 * 2^0 + 1 * 2^-1
**
**  fixed point numbers are simply a shifted version of an integer
**  (by setting binary point to a non-zero position)
*/

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