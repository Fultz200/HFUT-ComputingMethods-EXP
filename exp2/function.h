#ifndef function.h
#define function.h
#include<math.h>
#include<iostream>
using namespace std;
double f(double x){
    double res;
    if(x == 0.0){
        return 1.0;
    }
    res = sin(x) / x;
    return res;
}
#endif