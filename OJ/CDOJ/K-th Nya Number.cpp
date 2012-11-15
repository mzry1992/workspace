#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

long long ilow,iup,k;
int x,y,n;
long long dp[25][2][2][21][21],tot;
char low[25],up[25];

int getu(int preu,int now,int up)
{
    if (preu == 0)  return 0;
    if (now == up)  return 1;
    return 0;
}

int getd(int pred,int now,int low)
{
    if (pred == 0)  return 0;
    if (now == low) return 1;
    return 0;
}

long long DP(int pos,int u,int d,int nowx,int nowy)
{
    if (dp[pos][u][d][nowx][nowy] != -1)    return dp[pos][u][d][nowx][nowy];
    if (pos == 22)
    {
        if (nowx == x && nowy == y) return 1;
        else
            return 0;
    }
    else
    {
        dp[pos][u][d][nowx][nowy] = 0;
        int op,ed;
        op = (d == 1)?(low[pos]-'0'):0;
        ed = (u == 1)?(up[pos]-'0'):9;
        for (int i = op;i <= ed;i++)
            if (i == 4)
                dp[pos][u][d][nowx][nowy] += DP(pos+1,getu(u,i,up[pos]-'0'),getd(d,i,low[pos]-'0'),nowx+1,nowy);
            else if (i == 7)
                dp[pos][u][d][nowx][nowy] += DP(pos+1,getu(u,i,up[pos]-'0'),getd(d,i,low[pos]-'0'),nowx,nowy+1);
            else
                dp[pos][u][d][nowx][nowy] += DP(pos+1,getu(u,i,up[pos]-'0'),getd(d,i,low[pos]-'0'),nowx,nowy);
    }
    return dp[pos][u][d][nowx][nowy];
}

void Gao(long long k,int prezero,int pos,int u,int d,int nowx,int nowy)
{
    if (pos == 22)  return;
    int op,ed;
    long long tot = 0,pretot;
    op = (d == 1)?(low[pos]-'0'):0;
    ed = (u == 1)?(up[pos]-'0'):9;
    for (int i = op;i <= ed;i++)
    {
        pretot = tot;
        if (i == 4)
            tot += DP(pos+1,getu(u,i,up[pos]-'0'),getd(d,i,low[pos]-'0'),nowx+1,nowy);
        else if (i == 7)
            tot += DP(pos+1,getu(u,i,up[pos]-'0'),getd(d,i,low[pos]-'0'),nowx,nowy+1);
        else
            tot += DP(pos+1,getu(u,i,up[pos]-'0'),getd(d,i,low[pos]-'0'),nowx,nowy);
        if (tot >= k)
        {
            if (prezero == 0 || i != 0)
                printf("%d",i);
            if (i == 4)
                Gao(k-pretot,0,pos+1,getu(u,i,up[pos]-'0'),getd(d,i,low[pos]-'0'),nowx+1,nowy);
            else if (i == 7)
                Gao(k-pretot,0,pos+1,getu(u,i,up[pos]-'0'),getd(d,i,low[pos]-'0'),nowx,nowy+1);
            else
                Gao(k-pretot,(prezero == 0 || i != 0)?0:1,pos+1,getu(u,i,up[pos]-'0'),getd(d,i,low[pos]-'0'),nowx,nowy);
            return;
        }
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%I64d%I64d%d%d",&ilow,&iup,&x,&y);
        ilow++;
        sprintf(low,"%022I64d",ilow);
        sprintf(up,"%022I64d",iup);
        memset(dp,-1,sizeof(dp));
        tot = DP(0,1,1,0,0);
        scanf("%d",&n);
        printf("Case #%d:\n",ft);
        for (int fq = 1;fq <= n;fq++)
        {
            scanf("%I64d",&k);
            if (k > tot)
                printf("Nya!");
            else
                Gao(k,1,0,1,1,0,0);
            puts("");
        }
    }
    return 0;
}
