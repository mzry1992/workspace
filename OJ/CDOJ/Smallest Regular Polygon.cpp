#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdio>
using namespace std;

const double pi = acos(-1.0);
double xa,ya,xb,yb,x,l,s;
int n;

int main()
{
    while (true)
    {
        scanf("%lf%lf%lf%lf%d",&xa,&ya,&xb,&yb,&n);
        if (n == 0) break;
        l = sqrt((xa-xb)*(xa-xb)+(ya-yb)*(ya-yb));
        if (n&1) x = l*0.5/sin(0.5*pi*(n-1)/n);
        else x=l/2;
        s = 0.5*sin(2*pi/n)*x*x*n;
        printf("%.6f\n",s);
    }
    return 0;
}
