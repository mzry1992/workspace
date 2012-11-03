#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

const double goalxl = (68-7.32)/2;
const double goalxr = (68+7.32)/2;
const double goalz = 2.44;
const double g = 9.80665;
const double eps = 1e-8;

double X0,Y0;
int n;
double v0,dx,dy,dz,x1,dis,vx,vz,dis0,z;

int cmp(double a,double b)
{
    if (fabs(a-b) < eps)    return 0;
    if (a < b)  return -1;
    return 1;
}

bool Gao()
{
    if (cmp(dy,0) >= 0)    return false;
    x1 = X0-Y0/dy*dx;
    if (cmp(x1,goalxl) <= 0 || cmp(x1,goalxr) >= 0) return false;
    if (cmp(dz,0) == 0)    return true;
    dis = sqrt(Y0*Y0+(X0-x1)*(X0-x1));
    vx = v0*sqrt(dx*dx+dy*dy)/sqrt(dx*dx+dy*dy+dz*dz);
    vz = v0*dz/sqrt(dx*dx+dy*dy+dz*dz);
    if (cmp(8*vz*vx/(3*g),dis) < 0)    return false;
    if (cmp(8*vz*vx/(3*g),dis) == 0)    return true;
    dis0 = 0;
    while (true)
    {
        if (cmp(0.5*vz*vz/g,goalz) < 0) return true;
        if (cmp(dis0+2*vz*vx/g,dis) >= 0)
        {
            z = vz*((dis-dis0)/vx)-0.5*g*((dis-dis0)/vx)*((dis-dis0)/vx);
            return cmp(z,goalz) < 0;
        }
        dis0 += 2*vz*vx/g;
        vx /= 2;
        vz /= 2;
    }
}

int main()
{
    int ft = 0;
    while (scanf("%lf%lf",&X0,&Y0) != EOF)
    {
        scanf("%d",&n);
        ft++;
        printf("Case #%d:\n",ft);
        for (int i = 0;i < n;i++)
        {
            scanf("%lf%lf%lf%lf",&v0,&dx,&dy,&dz);
            printf("Shot %d: ",i+1);
            if (Gao() == true)
                puts("yes");
            else
                puts("no");
        }
    }
    return 0;
}
