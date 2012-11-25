#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

const double pi = acos(-1.0);
const double g = 9.81;
double l,h,w;

int main()
{
    while (scanf("%lf%lf%lf",&l,&h,&w) != EOF)
    {
        l /= 100;
        h /= 100;
        w = w*pi/30;
        double st;
        if (h <= 0.5*l)
            st = 0;
        else
            st = sqrt(fabs(2*(h-0.5*l)/g));
        if (cos(st*w) > 0)
            puts("butter");
        else
            puts("bread");
        //printf("%.6f %.6f %.6f\n",rest,0.5*g*rest*rest,dist);
    }
	return 0;
}
