#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n,m,k;
bool map[200][200];
int sgt;
int sgout[200];
int sgsort[200];
bool use[200];
int sc[200],sct;
int scin[200];
int sccount[200];
int dp[200][200];
int cc[200][200];

void DFS_1(int now)
{
    use[now] = true;
    for (int i = 1;i <= n;i++)
    if (use[i] == false)
    if (map[now][i] == true)
        DFS_1(i);
    sgt++;
    sgout[now] = sgt;
}

void DFS_2(int now)
{
    use[now] = true;
    sc[now] = sct;
    for (int i = 1;i <= n;i++)
    if (use[i] == false)
    if (map[i][now] == true)
        DFS_2(i);
}

int main()
{
    while (scanf("%d%d%d",&n,&m,&k) != EOF)
    {
        memset(map,false,sizeof(map));
        for (int i = 1;i <= m;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            map[u][v] = true;
        }
        sgt = 0;
        memset(use,false,sizeof(use));
        for (int i = 1;i <= n;i++)
        if (use[i] == false)
            DFS_1(i);
        for (int i = 1;i <= n;i++)
            sgsort[sgout[i]] = i;
        memset(use,false,sizeof(use));
        sct = 0;
        for (int i = 1;i <= n;i++)
        if (use[i] == false)
        {
            sct++;
            DFS_2(i);
        }
        memset(scin,0,sizeof(scin));
        memset(sccount,0,sizeof(sccount));
        for (int i = 1;i <= n;i++)
            sccount[sc[i]]++;
        for (int i = 1;i <= n;i++)
        for (int j = 1;j <= n;j++)
        if (sc[i] != sc[j])
        if (map[i][j] == true)
            scin[sc[j]]++;
        memset(dp,0,sizeof(dp));
        int sc0[200],sc0t;
        sc0t = 0;
        for (int i = 1;i <= sct;i++)
        if (scin[i] == 0)
        {
            sc0t++;
            sc0[sc0t] = i;
        }
        dp[0][0] = 1;
        for (int i = 1;i <= sc0t;i++)
        for (int j = 1;j <= k;j++)
        {
            dp[i][j] = 0;
            for (int q = 1;q <= sccount[i]&&j-q>=i-1;q++)
                dp[i][j] = dp[i][j]+dp[i-1][j-q]*
        }
    }
}
