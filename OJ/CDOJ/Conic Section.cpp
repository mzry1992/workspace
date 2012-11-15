#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

double a,b,c,d,e,f;
double a1,b1,a2,b2,c1;

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%lf%lf%lf%lf%lf%lf",&a,&b,&c,&d,&e,&f);
        c1 = f;
        if (fabs(a) > 1e-6)
        {
            a1 = a;
            a2 = 0;
            c1 -= d*d/(4*a);
        }
        else
        {
            a1 = 0;
            a2 = d;
        }
        if (fabs(c) > 1e-6)
        {
            b1 = c;
            b2 = 0;
            c1 -= e*e/(4*c);
        }
        else
        {
            b1 = 0;
            b2 = e;
        }
        if (a2 == 0 && b2 == 0)
        {
            if (a1 == b1)   printf("circle\n");
            else if (a1*b1 > 0) printf("ellipse\n");
            else printf("hyperbola\n");
        }
        else printf("parabola\n");
    }
}
