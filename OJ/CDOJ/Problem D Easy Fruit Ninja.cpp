#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
using namespace std;

double xa,xb,xc;
double va,vb,vc;
double a,b,c;
double vxa,vxb,vxc;
double vya,vyb,vyc;

const double eps = 1e-8;

int cmp(double a,double b)
{
    if (fabs(a-b) < eps)    return 0;
    if (a < b)  return -1;
    return 1;
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1; ft <= t; ft++)
    {
        scanf("%lf%lf%lf",&xa,&xb,&xc);
        scanf("%lf%lf%lf",&va,&vb,&vc);
        scanf("%lf%lf%lf",&a,&b,&c);

        printf("Case #%d: ",ft);


        vxa = va*cos(a);
        vxb = vb*cos(b);
        vxc = vc*cos(c);

        vya = va*sin(a);
        vyb = vb*sin(b);
        vyc = vc*sin(c);

        {
            double d,e,f,g;
            d = (xa-xb)*(vyc-vyb);
            e = (vxa-vxb)*(vyc-vyb);

            f = (xc-xb)*(vya-vyb);
            g = (vxc-vxb)*(vya-vyb);

            double minext;
            minext = 2.0*vya/10.0;
            minext = min(minext,2.0*vyb/10.0);
            minext = min(minext,2.0*vyc/10.0);

            if (cmp(minext,0.0) == 0)
            {
                printf("-1\n");
                continue;
            }

            a = e-g;
            b = d-f;

            if ((cmp(a,0.0) == 0 && cmp(b,0.0) != 0))
            {
                printf("-1\n");
                continue;
            }

            if (cmp(a,0.0) == 0 && cmp(b,0.0) == 0)
            {
                printf("Multiply answer\n");
                continue;
            }

            double res;

            res = -b/a;

            if (cmp(res,minext) >= 0 || cmp(res,0.0) <= 0)
                printf("-1\n");
            else printf("%.4f\n",res);
        }
    }
    return 0;
}
