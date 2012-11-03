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
    return fabs(xa-xb)+fabs(ya-yb);
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
        res = min(min(CalcDis(xa,ya,ml,ml)+CalcDis(ml,ml,xb,yb),
                      CalcDis(xa,ya,W-ml,ml)+CalcDis(W-ml,ml,xb,yb)),
                  min(CalcDis(xa,ya,W-ml,H-ml)+CalcDis(W-ml,H-ml,xb,yb),
                      CalcDis(xa,ya,ml,H-ml)+CalcDis(ml,H-ml,xb,yb)));
        if (cmp(xa,ml) >= 0 && cmp(xa,W-ml) <= 0)
            res = min(res,min(CalcDis(xa,ya,xa,ml)+CalcDis(xa,ml,xb,yb),
                              CalcDis(xa,ya,xa,H-ml)+CalcDis(xa,H-ml,xb,yb)));
        if (cmp(ya,ml) >= 0 && cmp(ya,H-ml) <= 0)
            res = min(res,min(CalcDis(xa,ya,ml,ya)+CalcDis(ml,ya,xb,yb),
                              CalcDis(xa,ya,W-ml,ya)+CalcDis(W-ml,ya,xb,yb)));
        if (cmp(xb,ml) >= 0 && cmp(xb,W-ml) <= 0)
            res = min(res,min(CalcDis(xa,ya,xb,ml)+CalcDis(xb,ml,xb,yb),
                              CalcDis(xa,ya,xb,H-ml)+CalcDis(xb,H-ml,xb,yb)));
        if (cmp(yb,ml) >= 0 && cmp(yb,H-ml) <= 0)
            res = min(res,min(CalcDis(xa,ya,ml,yb)+CalcDis(ml,yb,xb,yb),
                              CalcDis(xa,ya,W-ml,yb)+CalcDis(W-ml,yb,xb,yb)));
        printf("%.3f\n",res);
    }
    return 0;
}
