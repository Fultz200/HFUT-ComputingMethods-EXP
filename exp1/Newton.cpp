#include <iostream>
#include <math.h>
using namespace std;
float get_DiffQuotient(float *, float *, int);

int main()
{
    cout << "input the value of x." << endl;
    float x;
    cin >> x;
    float X[3] = {1.0, 4.0, 9.0}, Y[3] = {0.0}, dq[3] = {0.0};
    for(int i = 0; i < 3; i++) {
        Y[i] = sqrt(X[i]);
    }
    for(int i = 0; i < 3; i++) {
        dq[i] = get_DiffQuotient(X, Y, i);
    }
    float result = 0.0;
    for(int i = 0; i < 3; i++){
        float temp = 1;
        for(int j = 0; j < i; j++){
            temp = temp * (x - X[j]);
        }
        result += dq[i]*temp;
    }
    cout << result << endl;
    return 0;
}

float get_DiffQuotient(float *X, float *Y, int n){
    float res = 0;
    float temp = 0;
    for(int i = 0; i < n+1; i++){
        temp = Y[i];
        for(int j = 0; j < n+1; j++){
            if(i != j){
                temp = temp / (X[i] - X[j]);
            }
        }
        res = res + temp;
    }
    return res;
}