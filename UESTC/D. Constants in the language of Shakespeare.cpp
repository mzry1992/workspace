#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char s[1000010];
int len,dp[1000010],sum[1000010],Q[1000010],head,tail,pre[1000010];

int main()
{
    scanf("%s",s+1);
    len = strlen(s+1);
    dp[0] = sum[0] = 0;
    for (int i = 1; i <= len; i++)
        sum[i] = sum[i-1]+((s[i] == '0')?1:0);
    head = tail = 1000010;
    for (int i = 1; i <= len; i++)
    {
        dp[i] = dp[i-1]+((s[i] == '1')?1:0);
        pre[i] = i-1;
        if (i >= 2)
        {
            while (head < tail)
            {
                if (dp[Q[head]]+2-sum[Q[head]] >= dp[i-2]+2-sum[i-2])   head++;
                else    break;
            }
            Q[--head] = i-2;
        }
        if (head < tail && dp[i] > dp[Q[tail-1]]+2-sum[Q[tail-1]]+sum[i])
        {
            dp[i] = dp[Q[tail-1]]+2-sum[Q[tail-1]]+sum[i];
            pre[i] = Q[tail-1];
        }
    }
    printf("%d\n",dp[len]);
    int now = len,tpre;
    while (now > 0)
    {
        tpre = pre[now];
        if (tpre == now-1)
        {
            if (s[now] == '1')
                printf("+2^%d\n",len-now);
        }
        else
        {
            printf("+2^%d\n",len-tpre);
            printf("-2^%d\n",len-now);
            for (int i = tpre+1;i <= now;i++)
                if (s[i] == '0')
                    printf("-2^%d\n",len-i);
        }
        now = tpre;
    }
    return 0;
}
