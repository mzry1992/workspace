#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

const double eps = 1e-8;
const double pi = acos(-1.0);

int cmp(double a,double b)
{
    if (fabs(a-b) < eps)
        return 0;
    if (a < b)  return -1;
    return 1;
}

struct Point
{
    double x,y,z;
};

int n;
Point p[10000];
double l,r,mid1,mid2,val1,val2,pr[10000];

double CalcR(double h)
{
    double res = 0,k;
    for (int i = 0; i < n; i++)
    {
        k = (h-p[i].z)/h;
        res = max(res,pr[i]/k);
    }
    return res;
}

double Calc(double h)
{
    double r = CalcR(h);
    return pi*r*r*h/3;
}

int main()
{
    while (scanf("%d",&n) != EOF)
    {
        l = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%lf%lf%lf",&p[i].x,&p[i].y,&p[i].z);
            pr[i] = sqrt(p[i].x*p[i].x+p[i].y*p[i].y);
            l = max(l,p[i].z);
        }
        r = 1e8;
        for (int fffff = 0; fffff < 100; fffff++)
        {
            mid1 = l+(r-l)*1/3;
            mid2 = l+(r-l)*2/3;
            val1 = Calc(mid1);
            val2 = Calc(mid2);
            if (val1 < val2)
                r = mid2;
            else
                l = mid1;
        }
        printf("%.3f %.3f\n",l,CalcR(l));
    }
    return 0;
}
