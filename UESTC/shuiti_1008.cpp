#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

double r,s[10000],Pi=acos(-1.0);

int main()
{
    int t,n,i,j;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%d%lf",&n,&r);
        double res = 0;
        for(j=1;j<=n;j++)
        {
            scanf("%lf",&s[j]);
            if (s[j-1] > s[j])
            res += s[j-1]-s[j];
        }
        if (s[n] > s[1])
            res += s[n]-s[1];
        if (res != 0)
        {
            res =2*Pi*r/res;
            printf("%.3f\n",res);
        }
        else
            printf("Inf\n");
    }
    return 0;
}
