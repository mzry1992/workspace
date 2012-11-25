#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

double x[8],y[8];

void l2l(double asx,double asy,double aex,double aey,double bsx,double bsy,double bex,double bey,double& resx,double& resy)
{
    resx = asx;
    resy = asy;
    double t =
        ((asx-bsx)*(bsy-bey)-(asy-bsy)*(bsx-bex))/((asx-aex)*(bsy-bey)-(asy-aey)*(bsx-bex));
    resx += (aex-asx)*t;
    resy += (aey-asy)*t;
}

double xmult(double xa,double xb,double ya,double yb)
{
    return xa*yb-ya*xb;
}

int sgn(double x)
{
    if (fabs(x) < 1e-12)    return 0;
    if (x > 0)  return 1;
    return -1;
}

double tx[4],ty[4];

int main()
{
    while (true)
    {
        bool check =  true;
        for (int i = 0; i < 8; i++)
        {
            scanf("%lf%lf",&x[i],&y[i]);
            if (x[i] != 0 || y[i] != 0)
                check = false;
        }
        for (int i = 0; i < 4; i++)
            tx[i] = x[i],ty[i] = y[i];
        if (check == true)  break;
        double mx = (x[4]+x[6])/2;
        double my = (y[4]+y[6])/2;
        double lx = 0;
        double ly = 0;
        for (int i = 0; i < 4; i++)
        {
            lx += (x[i]-mx);
            ly += (y[i]-my);
        }
        lx = -lx;
        ly = -ly;
        for (int i = 0; i < 4; i++)
        {
            if (fabs(lx) < 1e-12 && fabs(ly) < 1e-12)   break;
            double mindis = 1e100;
            for (int j = 4; j < 8; j++)
            {
                if (fabs(xmult(lx,ly,x[(j+1)%4+4]-x[j],y[(j+1)%4+4]-y[j])) > 1e-12)
                {
                    double px,py;
                    l2l(x[j],y[j],x[(j+1)%4+4],y[(j+1)%4+4],x[i],y[i],x[i]+lx,y[i]+ly,px,py);
                    printf("lx = %.12f ly = %.12f\n",lx,ly);
                    printf("%.12f %.12f\n",px,py);
                    double dist = sqrt((x[i]-px)*(x[i]-px)+(y[i]-py)*(y[i]-py));
                    if (fabs(dist) < 1e-12)
                    {
                        mindis = 0;
                        break;
                    }
                    if (sgn(lx) == sgn(px-x[i]) && sgn(ly) == sgn(py-y[i]))
                    {
                        mindis = min(mindis,dist);
                    }
                }
            }
            double vlen = sqrt(lx*lx+ly*ly);
            double disgo = min(mindis,vlen);
            x[i] += lx*disgo/vlen;
            y[i] += ly*disgo/vlen;
            lx -= lx*disgo/vlen;
            ly -= ly*disgo/vlen;
        }
        for (int i = 0; i < 4; i++)
            printf("%.12f %.12f\n",x[i],y[i]);
    }
    return 0;
}
