#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

double b,a;

int main()
{
    int totcas;
    scanf("%d",&totcas);
    for (int cas = 1;cas <= totcas;cas++)
    {
        scanf("%lf%lf",&b,&a);
        double res = 0,pre = b,now;
        double d = a/1e5;
        for (int i = 1;i <= 100000;i++)
        {
            now = b*sqrt(fabs(1-1.0*(i*d)*(i*d)/a/a));
            res += sqrt((pre-now)*(pre-now)+d*d);
            //printf("%.10f\n",res);
            pre = now;
        }
        //printf("%.10f\n",pre);
        printf("Case %d: %.10f\n",cas,res*4);
    }
	return 0;
}
