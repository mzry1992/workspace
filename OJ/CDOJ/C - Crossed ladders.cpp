#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const double eps = 1e-6;
double x,y,c;

int main()
{
    while (scanf("%lf%lf%lf",&x,&y,&c) != EOF)
    {
        double l,r,mid;
        l = 0.0;
        r = min(x,y);
        while (fabs(l-r) > eps)
        {
            mid = (l+r)/2.0;
            if (c/sqrt(x*x-mid*mid)+c/sqrt(y*y-mid*mid) < 1.0)
                l = mid;
            else
                r = mid;
        }
        printf("%.3f\n",l);
    }
}
