#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n;
struct node
{
    int a,b;
}m[300];
bool map[300][300];
bool visit[300];

void DFS(int now)
{
    visit[now] = true;
    for (int i = 1;i <= n;i++)
    if (map[now][i])
    if (!visit[i])
    if (now != i)
        DFS(i);
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d",&n);
        memset(map,false,sizeof(map));
        for (int i = 1;i <= n;i++)
            scanf("%d%d",&m[i].a,&m[i].b);
        for (int i = 1;i <= n;i++)
        for (int j = 1;j <= n;j++)
        if (i != j)
        {
            if (m[i].b == m[j].a)
                map[i][j] = true;
        }
        int res = 0;
        for (int i = 1;i <= n;i++)
        {
            memset(visit,false,sizeof(visit));
            DFS(i);
            for (int j = 1;j <= n;j++)
            if (visit[j])
            if (res < m[i].a*m[j].b)
                res = m[i].a*m[j].b;
        }
        printf("%d\n",res);
    }
}
