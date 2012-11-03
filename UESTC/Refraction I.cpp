#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

double xa,xb,ya,yb,n,h;
double nx,ny,res;
const double pi = acos(-1.0);

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%lf%lf%lf%lf",&xa,&ya,&xb,&yb);
        scanf("%lf%lf",&n,&h);
        double tx,ty;
        ty = h;
        nx = xb-xa;
        ny = yb-ya;
        if (ny >= 0)
            printf("Impossible\n");
        else
        {
            tx = (nx/ny)*(h-ya)+xa;
            double ang = atan2(ya-ty,xa-tx);
            double tang,kang,nang;
            if (ang < pi/2.0)
            {
                tang = pi/2.0-ang;
                kang = asin(sin(tang)/n);
                nang = pi/2.0-kang;
                res = tx-h/tan(nang);
            }
            else if (ang > pi/2.0)
            {
                tang = ang-pi/2.0;
                kang = asin(sin(tang)/n);
                nang = pi/2.0-kang;
                res = tx+h/tan(nang);
            }
            else
                res = xa;
            printf("%.3f\n",res);
        }
    }
}
