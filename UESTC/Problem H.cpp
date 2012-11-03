#include<cstdio>
long long dp[3001],a[3001];
int main()
{
    int t;
    scanf("%d",&t);
    while (t--)
    {
        int n;
        long long s,m=0,p,k=0;
        scanf("%d%I64d%I64d",&n,&p,&s);
        s*=100;p*=100;
        for (int i=1;i<=n;i++)
        {
            double x;
            scanf("%lf",&x);
            a[i]=x*100;
        }
        dp[1]=s;
        long long max=s;
        for (int i=2;i<=n;i++)
        {
            dp[i]=dp[i-1];
            for (int j=1;j<i;j++)
                if (dp[j]/a[j]*a[i]+dp[j]%a[j]-p>dp[i])
                    dp[i]=dp[j]/a[j]*a[i]+dp[j]%a[j]-p;
            if (max<dp[i])
                max=dp[i];
        }
        printf("%.2f\n",(max-s)/100.0);
    }
    return 0;
}
