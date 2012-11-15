#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;

double dp[1000005]={0},p;
int a[12],b[12];
int main()
{
    int n,i;
    while (scanf("%d%lf",&n,&p)!=EOF)
    {
        memset(dp,0,sizeof(0));
        for (i=1;i<=n;i++)
            scanf("%lf",&a[i]);
        sort(a+1,a+n+1);
        a[0]=b[0]=0;
        for (i=1;i<=n;i++)
            if (a[i]-a[i-1]>1000)
                b[i]=b[i-1]+1000;
            else b[i]=b[i-1]+a[i]-a[i-1];
        dp[0]=0;
        dp[1]=0;
        for (i=1;i<=n;i++)
            dp[b[i]]=1;
        for (i=2;i<=n+1;i++)
            if (dp[i]==0)
                dp[i]=dp[i-1]*p+dp[i-2]*(1-p);
        printf("%.7f\n",dp[n+1]);
    }
}
