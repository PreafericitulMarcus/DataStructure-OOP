#include <iostream>
#include "problem2.h"
using namespace std;

Complex::Complex()
{
    real = 0;
    imaginary = 0;
}
double Complex::re()
{
    return real;
}
double Complex::ima()
{
    return imaginary;
}
