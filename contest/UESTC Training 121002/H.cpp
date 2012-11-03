#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

double a,b,c,d,m,t;

inline double calc(double v)
{
    return (a*v*v*v+b*v*v+c*v+d)*m;
}

int main()
{
    while (scanf("%lf%lf%lf%lf%lf%lf",&a,&b,&c,&d,&m,&t) != EOF)
    {
        double l = 0,r = 1e20,mid;
        for (int tim = 0;tim < 100;tim++)
        {
            mid = (l+r)/2;
            if (calc(mid) >= t)
                r = mid;
            else
                l = mid;
        }
        printf("%.2f\n",trunc(l*100)/100);
    }
    return 0;
}

