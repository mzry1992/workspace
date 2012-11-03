#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n,m,p[10],v[10][10],b[10][10];
int dp[1<<10][1<<10];
int ni,nj,nk;
bool visit[1<<10][1<<10];

int rem[10][1<<10];
bool hasrem[10][1<<10];

int Calc(int pos,int sta)
{
    if (hasrem[pos][sta] == true)
        return rem[pos][sta];
    hasrem[pos][sta] = true;
    int res = 0;
    for (int i = 0; i < n; i++)
        if (((sta>>i)&1) == 0)
        {
            res -= p[pos];
            res += v[i][pos];
            for (int j = i; j < n; j++)
                if (((sta>>j)&1) == 0)
                    res += b[i][j];
        }
    rem[pos][sta] = res;
    return res;
}

int main()
{
    //freopen("in.txt","r",stdin);
    while (true)
    {
        scanf("%d%d",&n,&m);
        if (n == 0 && m == 0)   break;
        for (int i = 0; i < m; i++)
            scanf("%d",&p[i]);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                scanf("%d",&v[i][j]);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                scanf("%d",&b[i][j]);
        memset(dp,0,sizeof(dp));
        memset(visit,false,sizeof(visit));
        memset(hasrem,false,sizeof(hasrem));
        visit[0][0] = true;
        for (int i = 0;i < (1<<m);i++)
        {
            for (int j = 0;j < (1<<n);j++)
                if (visit[i][j] == true)
                    for (int k = 0;k < n;k++)
                        if (((j>>k)&1) == 0)
                        {
                            nj = j|(1<<k);
                            if (visit[i][nj] == false)
                            {
                                dp[i][nj] = dp[i][j];
                                visit[i][nj] = true;
                            }
                            else
                                dp[i][nj] = max(dp[i][nj],dp[i][j]);
                        }
            for (int j = 0;j < (1<<n);j++)
                if (visit[i][j] == true)
                    for (int k = 0;k < m;k++)
                        if (((i>>k)&1) == 0)
                        {
                            ni = i|(1<<k);
                            nk = Calc(k,j);
                            if (visit[ni][j] == false)
                            {
                                dp[ni][j] = dp[i][j]+nk;
                                visit[ni][j] = true;
                            }
                            else
                                dp[ni][j] = max(dp[ni][j],dp[i][j]+nk);
                            break;
                        }
        }
        int res = 0;
        for (int i = (1<<m)-1;i < (1<<m);i++)
            for (int j = 0;j < (1<<n);j++)
                if (visit[i][j] == true)
                    res = max(res,dp[i][j]);
        if (res == 0)
            puts("STAY HOME");
        else
            printf("%d\n",res);
    }
    return 0;
}
