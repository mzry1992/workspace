#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

double k,h,a,b;
const double pi = acos(-1.0);
const double eps = 1e-6;

double calc(double x1,double y1,double x2,double y2)
{
    if (fabs(x1-x2) < eps)   return 90.0;
    return 180*atan2(y1-y2,x1-x2)/pi;
}

int main()
{
    while (scanf("%lf%lf%lf%lf",&k,&h,&a,&b) != EOF)
    {
        double l;
        l = h/sin(pi*k/180);
        double tl,tr,tmid;
        double a1,a2;
        double b1,b2;
        double tx,ty;
        tl = 0.0;
        tr = l;
        double dist;
        double d1,d2;
        while (fabs(tl-tr) >= eps)
        {
            tmid = (tl+tr)/2.0;
            tx = tmid*cos(pi*k/180);
            ty = h-tmid*h/l;
            a1 = calc(tx,ty,b,0.0);
            a2 = calc(0.0,a,tx,ty);
            d1 = sqrt((tx-b)*(tx-b)+ty*ty);
            d2 = sqrt(tx*tx+(a-ty)*(a-ty));
            dist = d1+d2;
            if (a1 < eps)   a1 = a1+180.0;
            b1 = 180-k-a1;
            if (a2 > eps)
                b2 = 180-((90-k)+180-a2+90);
            else
            {
                a2 = a2+180.0;
                b2 = 180-((90-k)+90-a2);
            }
            if (b1 > b2)
                tr = tmid;
            else
                tl = tmid;
        }
        printf("%.2f\n",dist);
    }
}
