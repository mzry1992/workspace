#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

double a,b,l,lmin,theta,w,tx,ty;

int main()
{
    scanf("%lf%lf%lf",&a,&b,&l);
    theta = atan2(pow(b,1.0/3.0),pow(a,1.0/3.0));
    lmin = pow(pow(a,2.0/3.0)+pow(b,2.0/3.0),1.5);
    if (l > lmin)
        printf("My poor head =(\n");
    else
    {
        w = (lmin-l)/(tan(theta)+1.0/tan(theta));
        printf("%.8f\n",w);
    }
    return 0;
}
