#ifndef _newtoniterator_h_
#define _newtonoterator_h_
#include "Module.h"

void Newton_Iterator(double x0, double e, int N, int M)
{
    int i, k = 0;      //"i" refers to the downhill counter.
    double x, a; //a refers to iteration factor.
    while (k < N)
    {
        cout << k << " " << x0 << endl;
        if (ff2(x0) == 0)
        {
            cout << "strange phenomenon." << endl;
            exit(1);
        }
        a = 1.0;//refresh the value of "a".
        x = newton_downhill_f(x0, a);
        i = 0;
        while (fabs(f2(x)) >= fabs(f2(x0)))
        {
            i++;
            a *= 0.5;
            if (i >= M)
            {
                cout << "error, input another x0." << endl;
                exit(1);
            }
            x = newton_downhill_f(x0, a);
        }
        if (fabs(x - x0) < e)
        {
            cout << x << endl;
            exit(0);
        } else {
            x0 = x;
            k++;//enter the next round.
        }
    }
    if (k >= N)
    {
        cout << "fail to do the newtondownhill iteration." << endl;
        exit(1);
    }
}

#endif