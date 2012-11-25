#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int inf = 0x7fffffff;
bool flag[20000][3],isprime[20000];
int dp[20000][3][3],prime[20000],tot;

void Gao(int now,int pla)
{
    if (flag[now][pla] == true)
        return;
    for (int i = 0;i < 3;i++)
        dp[now][pla][i] = inf;
    if (isprime[now])
        dp[now][pla][pla] = 1;
    else
    {
        Gao(now+1,(pla+1)%3);
        for (int i = 0;i < 3;i++)
            dp[now][pla][i] = dp[now+1][(pla+1)%3][i];
        dp[now][pla][pla] = min(dp[now][pla][pla],now+1);
        for (int i = 0;i < tot && prime[i] < now;i++)
            if (now%prime[i] == 0)
            {
                Gao(now/prime[i],(pla+1)%3);
                int minv = min(dp[now/prime[i]][(pla+1)%3][pla],now/prime[i]);
                if (minv <= dp[now][pla][pla])
                {
                    for (int j = 0;j < 3;j++)
                        dp[now][pla][j] = dp[now/prime[i]][(pla+1)%3][j];
                    dp[now][pla][pla] = minv;
                }
            }
    }
    flag[now][pla] = true;
}

int main()
{
    tot = 0;
    for (int i = 2;i < 20000;i++)
    {
        isprime[i] = true;
        for (int j = 2;j*j <= i && isprime[i];j++)
            if (i%j == 0)
                isprime[i] = false;
        if (isprime[i])
            prime[tot++] = i;
    }
    memset(flag,false,sizeof(flag));
    int n;
    while (scanf("%d",&n) != EOF)
    {
        int ans[3];
        for (int i = 0;i < 3;i++)   ans[i] = 0;
        for (int i = 0;i < n;i++)
        {
            char ch;
            int now;
            scanf(" %c%d",&ch,&now);
            int op = 0;
            if (ch == 'E')  op = 1;
            if (ch == 'I')  op = 2;
            Gao(now,op);
            for (int j = 0;j < 3;j++)
            {
                if (dp[now][op][j] == inf)
                    ans[j] += now;
                else
                    ans[j] += dp[now][op][j];
            }
        }
        for (int i = 0;i < 3;i++)
            printf("%d ",ans[i]);
        printf("\n");
    }
	return 0;
}
