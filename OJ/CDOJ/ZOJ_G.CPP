#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

int n;
int a[1200][1200];
int get[1200];
int dp[24000];
int ttot;

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d",&n);
        ttot = 0;
        for (int i = 1;i <= n;i++)
        {
            scanf("%d",&a[i][0]);
            for (int j = 1;j <= a[i][0];j++)
                scanf("%d",&a[i][j]);
        }
        for (int i = 1;i <= n;i++)
        {
            scanf("%d",&get[i]);
            ttot += get[i];
        }
        for (int i = 0;i < 24000;i++) dp[i] = -1;
        dp[0] = 0;
        for (int i = 1;i <= n;i++)
        {
            for (int j = 1;j <= a[i][0];j++)
            for (int k = a[i][j];k <= ttot;k++)
            if (dp[k] != -1)
            if (dp[k-a[i][j]] < dp[k]+1)
                dp[k-a[i][j]] = dp[k]+1;
            for (int j = 0;j <= ttot-get[i];j++)
                dp[j+get[i]] = dp[j];
            for (int j = 0;j < get[i];j++)
                dp[j] = -1;
        }
        int ans = 0;
        for (int i = 0;i <= ttot;i++)
        if (dp[i] > ans)
            ans = dp[i];
        printf("%d\n",ans);
    }
}

