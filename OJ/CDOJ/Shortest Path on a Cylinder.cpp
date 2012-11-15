#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

const double pi = acos(-1.0);
const double eps = 1e-8;

double r,h;

double ha,aa,ra,hb,ab,rb;
double xa,ya,za,xb,yb,zb;

int typa,typb;

int cmp(double a,double b)
{
    if (fabs(a-b) < eps)    return 0;
    if (a < b)  return -1;
    return 1;
}

double sqr(double x)
{
    return x*x;
}

double Distance(double xa,double ya,double za,double xb,double yb,double zb)
{
    return sqrt(sqr(xb-xa)+sqr(yb-ya)+sqr(zb-za));
}

double solve()
{
    aa = aa/180*pi;
    ab = ab/180*pi;

    xa = cos(aa)*ra;
    ya = sin(aa)*ra;
    za = ha;

    xb = cos(ab)*rb;
    yb = sin(ab)*rb;
    zb = hb;

    if (cmp(ha,0) == 0) typa = 0;
    else if (cmp(ha,h) == 0)    typa = 2;
    else typa = 1;

    if (cmp(hb,0) == 0) typb = 0;
    else if (cmp(hb,h) == 0)    typb = 2;
    else typb = 1;

    if (typa == typb)
    {
        if (typa == 1)
        {
            double theta;
            if (cmp(aa,ab) > 0) theta = aa-ab;
            else theta = ab-aa;
            if (cmp(theta,pi) > 0)  theta = 2*pi-theta;
            double A = r*theta;
            double B = fabs(ha-hb);
            return sqrt(A*A+B*B);
        }
        else
            return Distance(xa,ya,za,xb,yb,zb);
    }
    else
    {
        if (typa > typb)
        {
            swap(typa,typb);
            swap(xa,xb);
            swap(ya,yb);
            swap(za,zb);
        }
        if (typa == 0)
        {
            if (typb == 1)
                return zb+Distance(xa,ya,za,xb,yb,za);
            else
            {
            }
        }
        else
            return h-za+Distance(xa,ya,zb,xb,yb,zb);
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1; ft <= t; ft++)
    {
        scanf("%lf%lf",&r,&h);
        scanf("%lf%lf%lf",&ha,&aa,&ra);
        scanf("%lf%lf%lf",&hb,&ab,&rb);
        printf("Case #%d: %.2f\n",ft,solve());
    }
    return 0;
}
