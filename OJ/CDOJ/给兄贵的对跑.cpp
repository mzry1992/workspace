#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
using namespace std;

char x[1000];
double l,r,mid,y,ty,base;
const double eps = 1e-9;

int main()
{
    freopen("1.in","r",stdin);
    freopen("2.out","w",stdout);
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%s",x);
        scanf("%lf",&y);
        if (y == 1.0)
        if (x[strlen(x)-1] == '1')
        {
            int i;
            for (i = 0;i < strlen(x);i++)
                if (x[i] == '1') break;
            if (i < strlen(x)-1)    puts("-1");
            else
                puts("-2");
            continue;
        }
        l = 0.0; r = 1000.0;
        while (fabs(l-r) > eps)
        {
            mid = (l+r)/2.0;
            ty = 0.0;
            base = 1.0;
            for (int i = strlen(x)-1;i >= 0;i--)
            {
                ty += (x[i]-'0')*base;
                base *= mid;
            }
            if (ty > y) r = mid;
            else
                l = mid;
        }
        if (fabs(l) < eps)  puts("-1");
        else if (fabs(l-1000.0) < eps) puts("-1");
        else
            printf("%.7lf\n",l);
    }
}
