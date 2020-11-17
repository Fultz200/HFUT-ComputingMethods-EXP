#include"function.h"
#include<vector>
using namespace std;
 
 double RomberIntergral(double a, double b, double MarginOfError){
     double h = b - a;
     double T1 = (h / 2.0) * (f(a) + f(b));
     int k = 1;
     double S;
     double x;
     double T2;
     double S2;
     double S1 = 0.0;
     double C1 = 0.0;
     double C2;
     double R1 = 0.0;
     double R2;  
     while (1)
     {
         S = 0;
         x = a + h/2.0;
         while (x < b)
         {
             S = S + f(x);
             x = x + h;
         }
         T2 = (T1 / 2.0) + (h / 2) * S;
         S2 = (4/3)*T2 - (1 / 3) *T1;
         if(k == 1){
             k++;
             h = h / 2;
             T1 = T2;
             S1 = S2;
             continue;
         }
         C2 = (16/15)*S2 - (1 / 15) * S1;
         if(k == 2){
             C1 = C2;
             k++;
             h = h / 2;
             T1 = T2;
             S1 = S2;
             continue;
         }
         R2 = (64/63)*C2 - (1 / 63) * C1;
         if(k == 3){
             R1 = R2;
             C1 = C2;
             k++;
             h = h / 2;
             T1 = T2;
             S1 = S2;
             continue;
         }
         if(fabs(R2 - R1)>= MarginOfError){
             R1 = R2;
             C1 = C2;
             k++;
             h = h / 2;
             T1 = T2;
             S1 = S2;
             continue;
         }else
        {
             /* code */
             return R2;
        }     
    }
}