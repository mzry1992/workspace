#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int N,tmp;
bool am[35][35],use[35];
int pre[35];

bool check(int u)
{
    for (int v=1; v<=N; v++)
        if (am[u][v] && !use[v])
        {
            use[v]=1;
            if (pre[v]==-1 || check(pre[v]))
            {
                pre[v]=u;
                return 1;
            }
        }
    return 0;
}

int match()
{
    int ret=0;
    memset(pre,-1,sizeof(pre));
    for (int u=1; u<=N; u++)
    {
        memset(use,0,sizeof(use));
        if (check(u))
            ret++;
    }
    return ret;
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        memset(am,false,sizeof(am));
        scanf("%d",&N);
        for (int i = 1;i <= N;i++)
            for (int j = 1;j <= N;j++)
            {
                scanf("%d",&tmp);
                if (tmp == 1)
                    am[i][j] = true;
            }
        printf("%d\n",match());
    }
    return 0;
}
