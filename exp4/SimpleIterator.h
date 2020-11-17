#ifndef _simpleiterative_h_
#define _simpleiterative_h_

#include "Module.h"

void Sim_iterator(double x0, double e, int N)
{
    double x;
    int k;
    for (k = 0; k < N; k++)
    {
        x = f1(x0);
        if (fabs(fabs(x) - fabs(x0)) < e)
        {
            cout << x << endl;
            exit(0);
        }
        x0 = x;
    }
    if (k >= N)
    {
        cout << "fail to iterate." << endl;
        exit(0);
    }
}

#endif