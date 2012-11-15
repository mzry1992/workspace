#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n,m,val[10],w,dp[10001],pre[10001],use[10001],sum[10];

int main()
{
    for (int i = 1;i <= 9;i++)  val[i] = i*i-i;
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d%d",&n,&m);
        w = m-n;
        if (w < 0)  printf("No solution\n");
        else
        {
            memset(dp,127,sizeof(dp));
            dp[0] = 0;
            for (int i = 9;i >= 2;i--)
                for (int j = val[i];j <= w;j++)
                    if (dp[j] >= dp[j-val[i]]+1)
                    {
                        dp[j] = dp[j-val[i]]+1;
                        pre[j] = j-val[i];
                        use[j] = i;
                    }
            if (dp[w] > 100)    printf("No solution\n");
            else
            {
                memset(sum,0,sizeof(sum));
                for (int i = w;i != 0;i = pre[i])
                    sum[use[i]]++;
                int sumdig = 0;
                for (int i = 2;i <= 9;i++)  sumdig += i*sum[i];
                if (sumdig > n) printf("No solution\n");
                else
                {
                    sum[1] = n-sumdig;
                    int summ = 0;
                    for (int i = 1;i <= 9;i++)  summ += (i*i)*sum[i];
                    if (summ != m)  printf("No solution\n");
                    else
                    {
                        for (int i = 1;i <= 9;i++)
                            for (int j = 1;j <= sum[i];j++)
                                printf("%d",i);
                        printf("\n");
                    }
                }
            }
        }
    }
}
