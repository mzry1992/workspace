#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

const double eps = 1e-11;
double cx[4],cy[4],cost[4];

inline double Distance(double x1,double y1,double x2,double y2)
{
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

double Calc(double x,double y)
{
    double res = 0.0;
    for (int i = 1;i <= 3;i++)
        res += Distance(x,y,cx[i],cy[i])*cost[i];
    return res;
}

double CalcX(double y)
{
    double lx,rx,mid1,mid2;
    lx = -2000.0;
    rx = 2000.0;
    while (true)
    {
        mid1 = lx+(rx-lx)/3.0;
        mid2 = lx+2.0*(rx-lx)/3.0;
        if (Calc(mid1,y) < Calc(mid2,y))    rx = mid2;
        else lx = mid1;
        if (fabs(rx-lx) < eps)  break;
    }
    return lx;
}

double CalcY(double x)
{
    double lx,rx,mid1,mid2;
    lx = -2000.0;
    rx = 2000.0;
    while (true)
    {
        mid1 = lx+(rx-lx)/3.0;
        mid2 = lx+2.0*(rx-lx)/3.0;
        if (Calc(x,mid1) < Calc(x,mid2))    rx = mid2;
        else lx = mid1;
        if (fabs(rx-lx) < eps)  break;
    }
    return lx;
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        for (int i = 1;i <= 3;i++)
            scanf("%lf%lf",&cx[i],&cy[i]);
        for (int i = 1;i <= 3;i++)
            scanf("%lf",&cost[i]);
        double x,y,tx,ty;
        x = y = 0.0;
        while (true)
        {
            tx = CalcX(y);
            ty = CalcY(tx);
            if (fabs(Calc(tx,ty)-Calc(x,y)) < eps)  break;
            x = tx;
            y = ty;
        }
        printf("%.11f\n",Calc(x,y));
    }
}
