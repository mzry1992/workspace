#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
char buf[300];
bool g[300][300];
bool use[300];
int pre[300];

bool check(int u)
{
    for (int v = 0;v < n;v++)
        if (g[u][v] && !use[v])
        {
            use[v] = 1;
            if (pre[v] == -1 || check(pre[v]))
            {
                pre[v] = u;
                return 1;
            }
        }
    return 0;
}

int match()
{
    int ret = 0;
    memset(pre,-1,sizeof(pre));
    for (int u = 0;u < n;u++)
    {
        memset(use,0,sizeof(use));
        if (check(u))
            ret++;
    }
    return ret;
}

int main()
{
    while (scanf("%d",&n) != EOF)
    {
        memset(g,false,sizeof(g));
        for (int i = 0;i < n;i++)
        {
            scanf("%s",buf);
            for (int j = 0;j < n;j++)
                if (buf[j] == 'U')
                    g[i][j] = true;
        }

        if (match() == n)
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}

