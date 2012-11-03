#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

double xa,ya,xb,yb,xv,yv,vd,vb,l,x,y;
const double eps = 1e-12;

int cmp(double a,double b)
{
    if (fabs(a-b) < eps)    return 0;
    if (a < b)  return -1;
    return 1;
}

double sqr(double a)
{
    return a*a;
}

int main()
{
    while (true)
    {
        scanf("%lf%lf%lf%lf%lf%lf%lf%lf%lf",&xa,&ya,&xb,&yb,&xv,&yv,&vd,&vb,&l);
        if (cmp(xa,0) == 0 &&
            cmp(ya,0) == 0 &&
            cmp(xb,0) == 0 &&
            cmp(yb,0) == 0 &&
            cmp(xv,0) == 0 &&
            cmp(yv,0) == 0 &&
            cmp(vd,0) == 0 &&
            cmp(vb,0) == 0 &&
            cmp(l,0) == 0)  break;
        double tl,tr,mid,ls,dis,dis1;
        tl = 0;
        tr = 1e10;
        ls = l/vb;
        for (int i = 0;i < 80;i++)
        {
            mid = (tl+tr)/2.0;
            x = xa+xv*(mid+ls);
            y = ya+yv*(mid+ls);
            dis = sqrt(sqr(x-xb)+sqr(y-yb));
            if (cmp(dis,l) < 0)
                dis1 = l-dis;
            else
                dis1 = dis-l;
            if (cmp(dis1,vd*mid) < 0)
                tr = mid;
            else
                tl = mid;
        }
        printf("%.3f %.3f\n",l,tl+ls);
    }
    return 0;
}
