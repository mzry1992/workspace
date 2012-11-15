#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

int n;
double a,b,c,m;
double x1,x;

double calc(double a,double b,double c)
{
    return ((-b+sqrt(b*b-4*a*c))/(2.0*a));
}

int main()
{
    while (true)
    {
        scanf("%d%lf",&n,&c);
        if (n == 0 && c == 0)   break;
        scanf("%lf%lf%lf",&m,&a,&b);
        x1 = calc(a+c,4*b,-m);
        int res = 0;
        for (int i = 2;i <= n;i++)
        {
            scanf("%lf%lf%lf",&m,&a,&b);
            x = calc(a+c,4*b,-m);
            if (x > x1) res++;
        }
        printf("%d\n",res);
    }
}
