#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

const double g = 9.8;
double h,vx,vy,t,v1,v2,v3,flytim,curx,cury;
char s[10];

int main()
{
    while (scanf("%lf%s%lf%lf",&h,s,&vx,&vy) != EOF)
    {
        flytim = (vy+sqrt(vy*vy+2*g*h))/g;
        if (strcmp(s,"Red") == 0)
            printf("%.3f\n",flytim*vx);
        else
        {
            scanf("%lf",&t);
            curx = t*vx;
            cury = h+vy*t-g*t*t/2.0;
            if (strcmp(s,"Yellow") == 0)
            {
                if (flytim <= t)
                    printf("%.3f\n",flytim*vx);
                else
                {
                    vy = vy-g*t;
                    vx *= 2.0;
                    vy *= 2.0;
                    flytim = (vy+sqrt(vy*vy+2*g*cury))/g;
                    printf("%.3f\n",curx+flytim*vx);
                }
            }
            else
            {
                scanf("%lf%lf%lf",&v1,&v2,&v3);
                if (flytim <= t)
                    printf("%.3f\n",flytim*vx);
                else
                {
                    vy = vy-g*t;
                    flytim = (vy+sqrt(vy*vy+2*g*cury))/g;
                    printf("%.3f ",curx+flytim*v1);
                    printf("%.3f ",curx+flytim*v2);
                    printf("%.3f\n",curx+flytim*v3);
                }
            }
        }
    }
    return 0;
}
