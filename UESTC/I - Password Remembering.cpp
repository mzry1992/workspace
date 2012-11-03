#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char ta[30],tb[30];
int la,lb,l,a[30],b[30];
unsigned long long dp[30][30][2][2][2][2],res;

inline int checkd(int now,int num,int pred)
{
    if (pred == 0)  return 0;
    if (num > a[now])   return 0;
    return 1;
}

inline int checku(int now,int num,int preu)
{
    if (preu == 0)  return 0;
    if (num < b[now])   return 0;
    return 1;
}

inline int checkrd(int len,int now,int num,int prerd)
{
    if (prerd == 0)
    {
        if (num < a[l-1-(now-len)]) return 1;
        return 0;
    }
    else
    {
        if (num > a[l-1-(now-len)]) return 0;
        return 1;
    }
}

inline int checkru(int len,int now,int num,int preru)
{
    if (preru == 0)
    {
        if (num > b[l-1-(now-len)]) return 1;
        return 0;
    }
    else
    {
        if (num < b[l-1-(now-len)]) return 0;
        return 1;
    }
}

unsigned long long DP(int len,int now,int num,int d,int u,int rd,int ru)
{
    if (dp[len][now][d][u][rd][ru] != -1)
        return dp[len][now][d][u][rd][ru];
    if (now == l)
    {
        int cand,canu;
        cand = canu = 0;
        for (int i = 0;i < len;i++)
        {
            if (a[i] > 0)   cand = 1;
            if (b[i] > 0)   canu = 1;
        }
        if (cand) dp[len][now][d][u][rd][ru] = 0;
        else
        {
            if (!rd&& ru <= canu)
                dp[len][now][d][u][rd][ru] = 1;
            else
                dp[len][now][d][u][rd][ru] = 0;
        }
    }
    else
    {
        int op,ed;
        op = (d == 1)?a[now]:0;
        ed = (u == 1)?b[now]:9;
        dp[len][now][d][u][rd][ru] = 0;
        if (now < len)
        {
            if (op == 0)
                dp[len][now][d][u][rd][ru] = DP(len,now+1,0,checkd(now,0,d),checku(now,0,u),0,0);
        }
        else
        {
            if (now == len && op == 0)  op = 1;
            for (int i = op;i <= ed;i++)
                dp[len][now][d][u][rd][ru] += DP(len,now+1,i,checkd(now,i,d),checku(now,i,u),checkrd(len,now,i,rd),checkru(len,now,i,ru));
        }
    }
    return dp[len][now][d][u][rd][ru];
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%s%s",ta,tb);
        la = strlen(ta);
        lb = strlen(tb);
        l = max(la,lb);
        for (int i = 0;i < l-la;i++)    a[i] = 0;
        for (int i = 0;i < l-lb;i++)    b[i] = 0;
        for (int i = l-la;i < l;i++)    a[i] = ta[i-(l-la)]-'0';
        for (int i = l-lb;i < l;i++)    b[i] = tb[i-(l-lb)]-'0';
        memset(dp,-1,sizeof(dp));
        res = 0;
        for (int i = 0;i < l;i++)
            res += DP(i,0,0,1,1,0,0);
        printf("Case %d: %llu\n",ft,res);
    }
}
