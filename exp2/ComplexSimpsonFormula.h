#include"function.h"
using namespace std;

double ComplexSimpsonFormula(double a, double b, int n){
    double fa = f(a);
    double fb = f(b);
    double h = (b - a) / n;
    double x = a;
    double fxkl2 = 0.0;
    double fxk = 0.0;
    for(int k = 0; k < n; k++){
        double xk1 = a + k*h;
        x = xk1 + h / 2.0;
        fxkl2 = fxkl2 + f(x) ;
    }

    for(int k = 1;k < n;k++){
        double xk = a + k*h;
        fxk = fxk + f(xk);
    }

    double res = (h / 6) * (fa + 4*fxkl2 + 2*fxk + fb);
    return res;
}