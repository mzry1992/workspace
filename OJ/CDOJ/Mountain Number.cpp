#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

long long dp[40][10][2][2][4];
char a[40],b[40],ta[40],tb[40];
int la,lb,l;

int checku(int u,int now,int num)
{
    if (u == 0) return 0;
    if (num == b[now]-'0')  return 1;
    else return 0;
}

int checkd(int d,int now,int num)
{
    if (d == 0) return 0;
    if (num == a[now]-'0')  return 1;
    else return 0;
}

long long DP(int now,int num,int u,int d,int sta)
{
    if (dp[now][num][u][d][sta] != -1)  return dp[now][num][u][d][sta];
    if (now == l)
    {
        dp[now][num][u][d][sta] = ((sta == 3)?1:0);
        return dp[now][num][u][d][sta];
    }
    int st,ed;
    st = (d == 0)?0:(a[now]-'0');
    ed = (u == 0)?9:(b[now]-'0');
    dp[now][num][u][d][sta] = 0;
    if (sta == 0)
    {
        if (st == 0)    dp[now][num][u][d][sta] += DP(now+1,0,checku(u,now,0),checkd(d,now,0),0);
        for (int i = max(st,num+1);i <= ed;i++)
            dp[now][num][u][d][sta] += DP(now+1,i,checku(u,now,i),checkd(d,now,i),1);
    }
    else if (sta == 1)
    {
        for (int i = max(st,num+1);i <= ed;i++)
        {
            dp[now][num][u][d][sta] += DP(now+1,i,checku(u,now,i),checkd(d,now,i),1);
            dp[now][num][u][d][sta] += DP(now+1,i,checku(u,now,i),checkd(d,now,i),2);
        }
    }
    else
    {
        for (int i = st;i <= min(ed,num-1);i++)
            dp[now][num][u][d][sta] += DP(now+1,i,checku(u,now,i),checkd(d,now,i),3);
    }
    return dp[now][num][u][d][sta];
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
        for (int i = 0;i < la;i++)
            a[l-la+i] = ta[i];
        for (int i = 0;i < lb;i++)
            b[l-lb+i] = tb[i];
        for (int i = 0;i < l-la;i++)    a[i] = '0';
        for (int i = 0;i < l-lb;i++)    b[i] = '0';
        memset(dp,-1,sizeof(dp));
        printf("Case #%d: %lld\n",ft,DP(0,0,1,1,0));
    }
}
