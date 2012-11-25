#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

int n,s;
bool g[50][50];
int vis[50];
int cnt = 0;

void BFS(int now)
{
    queue<int> Q;
    memset(vis,-1,sizeof(vis));
    Q.push(now);
    vis[now] = 0;
    vector<int> res;
    while (!Q.empty())
    {
        int now = Q.front();
        Q.pop();
        if (vis[now] > 2)   continue;
        if (vis[now] == 2)
            res.push_back(now+1);
        for (int i = 0;i < n;i++)
            if (g[now][i] == true)
                if (vis[i] == -1)
                {
                    vis[i] = vis[now]+1;
                    Q.push(i);
                }
    }
    sort(res.begin(),res.end());
    printf("%d\n",res.size());
    if (res.size() == 0)    return;
    printf("%d",res[0]);
    for (int i = 1;i < res.size();i++)
        printf(" %d",res[i]);
    printf("\n");
}

int main()
{
    while (scanf("%d%d",&n,&s) != EOF)
    {
        s--;
        memset(g,false,sizeof(g));
        for (int i = 0;i < n;i++)
        {
            int tot = 0;
            scanf("%d",&tot);
            for (int j = 0;j < tot;j++)
            {
                int v;
                scanf("%d",&v);
                v--;
                g[i][v] = g[v][i] = true;
            }
        }
        BFS(s);
    }
	return 0;
}
