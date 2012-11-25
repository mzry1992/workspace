#include<cstdio>
#include<cstring>
int next[1000000];
double dp[1000000];
int main()
{
    int n,m;
    while (scanf("%d%d",&n,&m),n)
    {
        memset(next,-1,4*n);
        while (m--)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            next[a]=b;
        }
        for (int i=n-1;i>=0;i--)
        {
            if (next[i]!=-1)
            {
                if (next[i] == n)
                    dp[i] = 0;
                else
                    dp[i]=dp[next[i]];
                continue;
            }
            dp[i]=1;
            for (int j=1;j<=6;j++)
                if (i+j<n)
                    dp[i]+=dp[i+j]/6;
        }
        printf("%.4f\n",dp[0]);
    }
    return 0;
}
