#ifndef _module_h_
#define _module_h_

#include <iostream>
#include <math.h>
#include <vector>
#include <cstdlib>
using namespace std;

// baseed on the expression "x3 - x - 1 = 0"
// we can get several iterative functions
// and if we need to change the original exprission, we can just de here

//////
//SimpleIterator Expression
//////
//now it's "(x + 1)^(1.0 / 3.0)"
double f1(double x)
{
    return pow(x + 1, 1.0 / 3.0);
}
//now it's is "x^3 - 1"
double f2(double x)
{
    return (pow(x, 3.0) - x - 1.0);
}
//ff() refers to the derivative function of f()
//now it's "(1.0 / 3.0) * (x + 1)^(- 2.0 / 3.0)"
double ff1(double x)
{
    return ( 1.0 / 3.0 ) * pow(x + 1, -(2.0 / 3.0));
}
//now it's "3 * x^2"
double ff2(double x)
{
    return (3 * pow(x, 2.0) - 1.0);
}
//////
//NewtonIterator Expression
//////
double newton_f(double x)
{
    return ( x - f1(x) / ff1(x) );
}

//////
//Newton Downhill Method Expression
//////
double newton_downhill_f(double x, double a)
{
    return ( x - a * ( f2(x) / ff2(x) ) );
}
#endif