#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

double a0,b[3000],a[3000];
int n;

const double e = 2.718281828459;

double f2(double x)
{
    return pow(e,0.5*x*x+x);
}

double f(double x)
{
    double res,a;
    res = a = 1;
    for (int i = 1;i < 3000;i++)
    {
        a = a*b[i]*x/i;
        res += a;
    }
    return res;
}

int main()
{
    b[0] = 1;
    for (int i = 1;i < 3000;i++)
        b[i] = 1.0+(i-1)/b[i-1];
    double eps = 1e-12;
    while (scanf("%lf%d",&a0,&n) != EOF)
    {
        double res = 1.0;

        for (int i = 1;i <= n;i++)
        {
            double x;
            scanf("%lf",&x);
            //printf("%.8f %.8f %.8f %.8f\n",(f(x+eps)-f(x))/eps,f(x),x,(f(x+eps)-f(x))/eps/f(x));
            //printf("%.8f\n",f(x)-f2(x));
            /*if (n<500)
                res*=pow(f(x),1.0/n);
            else*/
                res *= pow(f2(x),1.0/n);
        }
        printf("%.8f\n",res*a0);
    }
	return 0;
}
