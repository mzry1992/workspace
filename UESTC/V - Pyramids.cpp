#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

double AB,AC,AD,BC,BD,CD;
double xc,xd,yd,theta,x,y,z,V,Sbcd;

int main()
{
    while (scanf("%lf%lf%lf%lf%lf%lf",&AB,&AC,&AD,&BC,&BD,&CD) != EOF)
    {
        xc = BC;
        theta = acos((BC*BC+BD*BD-CD*CD)/(2*BC*BD));
        xd = BD*cos(theta);
        yd = BD*sin(theta);
        x = (AB*AB-AC*AC+xc*xc)/(2*xc);
        y = (AC*AC-AD*AD-(x-xc)*(x-xc)+(x-xd)*(x-xd)+yd*yd)/(2*yd);
        z = sqrt(AB*AB-x*x-y*y);
        Sbcd = BC*BD*sin(theta);
        V = Sbcd*z/6.0;
        printf("%.4f\n",V);
    }
}
