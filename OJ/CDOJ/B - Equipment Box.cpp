#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

double a,b,x,y;

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%lf%lf%lf%lf",&a,&b,&x,&y);
        if (a > b)  swap(a,b);
        if (x > y)  swap(x,y);
        if (x <= a && y <= b) printf("Escape is possible.\n");
        else if (x > a && y > b)    printf("Box cannot be dropped.\n");
        else if (x > a && y < b)    printf("Box cannot be dropped.\n");
        else if(sqrt(a*a+b*b) <= y) printf("Box cannot be dropped.\n");
        else
        {
            double m = ((2.0*a*x*x+sqrt(-4.0*x*x*y*y*(a*a-x*x-y*y))))/(2.0*(x*x+y*y));
            double n = sqrt(x*x-m*m);
            if (b-sqrt(y*y-(a-m)*(a-m)) >= n)
                printf("Escape is possible.\n");
            else printf("Box cannot be dropped.\n");
        }
    }
}
