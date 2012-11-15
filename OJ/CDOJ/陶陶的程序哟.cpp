#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
    double h,r,d,d1;
    int t,i;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
     scanf("%lf%lf%lf",&h,&r,&d);
     if (h > 2*r)
        h = 2*r;
     if (h < 0.0)
        h = 0.0;
     d1=d/4*(2*r*r*r+3*r*r*(h-r)-(h-r)*(h-r)*(h-r))/r/r/r;
     printf("%.2lf\n",d1);
    }
    return 0;
}
