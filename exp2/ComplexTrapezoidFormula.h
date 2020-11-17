#include<iostream>
#include<math.h>
#include"function.h"
using namespace std;

double ComplexTrapezoidFormula(double a,double b, int n) {
    double fa = f(a);
    double fb = f(b);
    double h = (b - a) / n;
    double fxk = 0.0;
    for(int k = 1; k < n;k++){
        double xk = a + k*h;
        fxk = fxk + f(xk);
    }
    double res = (h / 2.0) * (fa + 2.0*fxk + fb);
    return res;
}