#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n,m,sx,sy,w,si,ti,di,dp[201][200][200],Q[500],head,tail;
char mp[300][300];

int main()
{
    scanf("%d%d%d%d%d",&n,&m,&sx,&sy,&w);
    for (int i = 0;i < n;i++)
        scanf("%s",mp[i]);
    memset(dp,-63,sizeof(dp));
    sx--,sy--;
    dp[0][sx][sy] = 0;
    for (int i = 1;i <= w;i++)
    {
        scanf("%d%d%d",&si,&ti,&di);
        si = ti-si+1;
        if (di == 1)
        {
            for (int k = 0;k < m;k++)
                for (int j = n;j >= 0;j--)
                    if (j == n || mp[j][k] == 'x')
                        head = tail = 500;
                    else
                    {
                        while (head < tail)
                        {
                            if (dp[i-1][Q[head]][k]+Q[head] < dp[i-1][j][k]+j)  head++;
                            else    break;
                        }
                        Q[--head] = j;
                        while (head < tail)
                        {
                            if (Q[tail-1]-j > si)   tail--;
                            else    break;
                        }
                        dp[i][j][k] = max(dp[i][j][k],dp[i-1][Q[tail-1]][k]+Q[tail-1]-j);
                    }
        }
        else if (di == 2)
        {
            for (int k = 0;k < m;k++)
                for (int j = -1;j < n;j++)
                    if (j == -1 || mp[j][k] == 'x')
                        head = tail = 500;
                    else
                    {
                        while (head < tail)
                        {
                            if (dp[i-1][Q[head]][k]-Q[head] < dp[i-1][j][k]-j)  head++;
                            else    break;
                        }
                        Q[--head] = j;
                        while (head < tail)
                        {
                            if (j-Q[tail-1] > si)   tail--;
                            else    break;
                        }
                        dp[i][j][k] = max(dp[i][j][k],dp[i-1][Q[tail-1]][k]+j-Q[tail-1]);
                    }
        }
        else if (di == 3)
        {
            for (int j = 0;j < n;j++)
                for (int k = m;k >= 0;k--)
                    if (k == m || mp[j][k] == 'x')
                        head = tail = 500;
                    else
                    {
                        while (head < tail)
                        {
                            if (dp[i-1][j][Q[head]]+Q[head] < dp[i-1][j][k]+k)  head++;
                            else    break;
                        }
                        Q[--head] = k;
                        while (head < tail)
                        {
                            if (Q[tail-1]-k > si)   tail--;
                            else    break;
                        }
                        dp[i][j][k] = max(dp[i][j][k],dp[i-1][j][Q[tail-1]]+Q[tail-1]-k);
                    }
        }
        else
        {
            for (int j = 0;j < n;j++)
                for (int k = -1;k < m;k++)
                    if (k == -1 || mp[j][k] == 'x')
                        head = tail = 500;
                    else
                    {
                        while (head < tail)
                        {
                            if (dp[i-1][j][Q[head]]-Q[head] < dp[i-1][j][k]-k)  head++;
                            else    break;
                        }
                        Q[--head] = k;
                        while (head < tail)
                        {
                            if (k-Q[tail-1] > si)   tail--;
                            else    break;
                        }
                        dp[i][j][k] = max(dp[i][j][k],dp[i-1][j][Q[tail-1]]+k-Q[tail-1]);
                    }
        }
    }
    int ans = 0;
    for (int i = 0;i <= w;i++)
        for (int j = 0;j < n;j++)
            for (int k = 0;k < m;k++)
                ans = max(ans,dp[i][j][k]);
    printf("%d\n",ans);
    return 0;
}
