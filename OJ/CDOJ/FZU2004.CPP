#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

const double eps = 1e-10;

struct Point
{
    double x,y;
};

Point p[20];
double c[20];
double x,y;
double midrx,midry,midlx,midly,disl,disr;
int n;

int cmp(double a,double b)
{
    if (fabs(a-b) < eps)    return 0;
    if (a < b)  return -1;
    return 1;
}

double CalcCost(double x,double y)
{
    double res = 0.0;
    for (int i = 0;i < n;i++)
        res += sqrt((x-p[i].x)*(x-p[i].x)+(y-p[i].y)*(y-p[i].y))*c[i];
    return res;
}

double Gao(double lx,double ly,double rx,double ry,double &x,double &y)
{
    for (int ff = 0;ff < 50;ff++)
    {
        midlx = (rx-lx)/3.0+lx;
        midly = (ry-ly)/3.0+ly;
        midrx = rx-(rx-lx)/3.0;
        midry = ry-(ry-ly)/3.0;
        disl = CalcCost(midlx,midly);
        disr = CalcCost(midrx,midry);
        if (cmp(disl,disr) > 0)
        {
            lx = midlx;
            ly = midly;
        }
        else
        {
            rx = midrx;
            ry = midry;
        }
    }
    x = lx;
    y = ly;
}

int main()
{
    while (true)
    {
        n = 4;
        for (int i = 0;i < n;i++)
        {
            scanf("%lf%lf",&p[i].x,&p[i].y);
            c[i] = 1.0;
        }
        if (cmp(p[0].x,0) < 0)  break;
        x = y = 0.0;
        for (int gao = 0;gao < 50;gao++)
            if ((gao&1) == 0)
                Gao(x,-1e3,x,1e3,x,y);
            else
                Gao(-1e3,y,1e3,y,x,y);
        printf("%.4f\n",CalcCost(x,y));
    }
    return 0;
}
