#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

const double g = 9.80;
double xa,ya,xb,yb,tim;

double calc(double a,double b,double c,double t)
{
    return (2*sqrt(a)*(b+2*a*t)*sqrt(c+t*(b+a*t))-(b*b-4*a*c)*log((b+2*a*t)/sqrt(a)+2*sqrt(c+t*(b+a*t))))
    /(8*sqrt(a*a*a));
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%lf%lf%lf%lf%lf",&xa,&ya,&xb,&yb,&tim);
        double a = (xb-xa)*(xb-xa)/(tim*tim);
        double b = -g;
        double c = (yb-ya+0.5*g*tim*tim)/tim;
        double res = calc(b*b,2*b*c,c*c+a,tim)-calc(b*b,2*b*c,c*c+a,0);
        if (res != res)
            puts("Impossible.");
        else
            printf("%.3f\n",res);
    }
    return 0;
}
