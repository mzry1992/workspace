#include <iostream>
#include <cmath>
#define PI 3.141592653589793
using namespace std;

double S,r,h,V,tr;

int main()
{
    while (scanf("%lf",&S) == 1)
    {        
          tr = S/(4*PI);   
          r = sqrt(tr);
          h = sqrt(S*S/(PI*PI*tr)-2*S/PI);
          V = PI*tr*h/3;
          printf("%.2lf\n%.2lf\n%.2lf\n",V,h,r);
    }
}
