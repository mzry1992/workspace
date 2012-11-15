#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

const double eps = 1e-10;
double W,H,a,b,xa,ya,xb,yb,wa,ha,wb,hb,ml,res;
int ta,tb;

int cmp(double a,double b)
{
    if (fabs(a-b) < eps)    return 0;
    if (a < b)  return -1;
    return 1;
}

double CalcDis(double xa,double ya,double xb,double yb)
{
    return sqrt((xa-xb)*(xa-xb)+(ya-yb)*(ya-yb));
}

double Gao(double lx,double ly,double rx,double ry)
{
    double midrx,midry,midlx,midly,res,disr,disl;
    for (int ff = 0;ff < 500;ff++)
    {
        midlx = (rx-lx)/3.0+lx;
        midly = (ry-ly)/3.0+ly;
        midrx = rx-(rx-lx)/3.0;
        midry = ry-(ry-ly)/3.0;
        disl = CalcDis(xa,ya,midlx,midly)+CalcDis(midlx,midly,xb,yb);
        disr = CalcDis(xa,ya,midrx,midry)+CalcDis(midrx,midry,xb,yb);
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
    return CalcDis(xa,ya,lx,ly)+CalcDis(lx,ly,xb,yb);
}

int main()
{
    while (scanf("%lf%lf%lf%lf",&W,&H,&a,&b) != EOF)
    {
        scanf("%lf%lf%d%lf%lf%d",&xa,&ya,&ta,&xb,&yb,&tb);
        if (ta == 1)
        {
            wa = a;
            ha = b;
        }
        else
        {
            wa = b;
            ha = a;
        }
        if (tb == 1)
        {
            wb = a;
            hb = b;
        }
        else
        {
            wb = b;
            hb = a;
        }
        if (cmp(xa-0.5*wa,0) < 0 || cmp(xa+0.5*wa,W) > 0 ||
                cmp(ya-0.5*ha,0) < 0 || cmp(ya+0.5*ha,H) > 0)
        {
            puts("-1");
            continue;
        }
        if (cmp(xb-0.5*wb,0) < 0 || cmp(xb+0.5*wb,W) > 0 ||
                cmp(yb-0.5*hb,0) < 0 || cmp(yb+0.5*hb,H) > 0)
        {
            puts("-1");
            continue;
        }
        if (ta == tb)
        {
            printf("%.3f\n",CalcDis(xa,ya,xb,yb));
            continue;
        }
        ml = 0.5*sqrt(a*a+b*b);
        if (cmp(0.5*W-ml,0) < 0 || cmp(0.5*W+ml,W) > 0 ||
                cmp(0.5*H-ml,0) < 0 || cmp(0.5*H+ml,H) > 0)
        {
            puts("-1");
            continue;
        }
        if ((cmp(xa,ml) >= 0 && cmp(xa,W-ml) <= 0 && cmp(ya,ml) >= 0 && cmp(ya,H-ml) <= 0) ||
                (cmp(xb,ml) >= 0 && cmp(xb,W-ml) <= 0 && cmp(yb,ml) >= 0 && cmp(yb,H-ml) <= 0))
        {
            printf("%.3f\n",CalcDis(xa,ya,xb,yb));
            continue;
        }
        res = min(min(Gao(ml,ml,W-ml,ml),Gao(W-ml,ml,W-ml,H-ml)),
                  min(Gao(W-ml,H-ml,ml,H-ml),Gao(ml,H-ml,ml,ml)));
        printf("%.3f\n",res);
    }
    return 0;
}

