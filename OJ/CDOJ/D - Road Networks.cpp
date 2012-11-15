#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

vector<int> e[1200];
int n,m;
int state[1200],low[1200],id[1200],bel[1200];
stack<int> s;

void dfs(int u,int t,int &clr)
{
    low[u] = id[u] = t++;
    state[u] = 1;
    s.push(u);
    for (int i = 0;i < e[u].size();i++)
        if (state[e[u][i]] == 0)
        {
            dfs(e[u][i],t,clr);
            low[u] = min(low[e[u][i]],low[u]);
        }
        else if (state[e[u][i]] == 1)
            low[u] = min(low[e[u][i]],low[u]);
    if (low[u] == id[u])
    {
        int v;
        clr++;
        do
        {
            v = s.top(); s.pop();
            state[v] = 2;
            bel[v] = clr;
        }while (v != u);
    }
}

int tarjan()
{
    int cnt = 0;
    memset(state,0,sizeof(state));
    memset(low,0,sizeof(low));
    memset(id,0,sizeof(id));
    for (int i = 1;i <= n;i++)
        if (!state[i])  dfs(i,1,cnt);
    return cnt;
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d%d",&n,&m);
        for (int i = 1;i <= n;i++)
            e[i].clear();
        for (int i = 1;i <= m;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            e[u].push_back(v);
        }
        printf("%d\n",tarjan());
        scanf("%d",&n);
    }
}
