#include<cstdio>
int a[1000],sum[1001],dp[1000][1000],s[1000][1000];
const int inf=0x7fffffff;
int max(int x,int y)
{
    if (x<y) return y;
    else return x;
}
int main()
{
    int n,m;
    while (scanf("%d%d",&n,&m)!=EOF)
    {
        for (int i=0;i<n;i++)
            scanf("%d",&a[i]);
        sum[0]=0;
        for (int i=0;i<n;i++)
            sum[i+1]=sum[i]+a[i];
        dp[0][0]=0;
        for (int i=0;i<n;i++)
            for (int j=i+1;j<n;j++)
                dp[0][0]+=a[i]*a[j];
        for (int i=1;i<n;i++)
            dp[i][0]=inf;
        for (int i=1;i<n;i++)
        {
            dp[i][1]=inf;
            for (int j=0;j<i;j++)
                if (dp[i][1]>dp[j][0]-(sum[i]-sum[j])*(sum[n]-sum[i]))
                {
                    dp[i][1]=dp[j][0]-(sum[i]-sum[j])*(sum[n]-sum[i]);
                    s[i][1]=j;
                }
        }
        for (int l=2;l<=m;l++)
        {
            dp[n-1][l]=inf;
            for (int j=l-1;j<n-1;j++)
                if (dp[n-1][l]>dp[j][l-1]-(sum[n-1]-sum[j])*(sum[n]-sum[n-1]))
                    {
                        dp[n-1][l]=dp[j][l-1]-(sum[n-1]-sum[j])*(sum[n]-sum[n-1]);
                        s[n-1][l]=j;
                    }
            for (int i=n-2;i>=l;i--)
            {
                dp[i][l]=inf;
                for (int j=s[i+1][l];j>=max(l-1,s[i][l-1]);j--)
                    if (dp[i][l]>dp[j][l-1]-(sum[i]-sum[j])*(sum[n]-sum[i]))
                    {
                        dp[i][l]=dp[j][l-1]-(sum[i]-sum[j])*(sum[n]-sum[i]);
                        s[i][l]=j;
                    }
            }
        }
        int ans=0x7fffffff;
        for (int i=m;i<n;i++)
            if (ans>dp[i][m])
                ans=dp[i][m];
        printf("%d\n",ans);
    }
    return 0;
}
