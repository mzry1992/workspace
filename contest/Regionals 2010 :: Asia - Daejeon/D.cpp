#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct Edge
{
    int to,next;
};
Edge edge[4000000];
int head[2000],L;
int x[2000],y[2000],d[2000];
int n;

void addedge(int u,int v)
{
    edge[L].to = v;
    edge[L].next = head[u];
    head[u] = L++;
}

int dfsnum[2000];
int low[2000];
int stack[2000];
int top;
int ans;
int an;
int be[2000];
int flag[2000];
void dfs(int x)
{
    dfsnum[x] = low[x] = ans++;
    stack[++top] = x;
    flag[x] = 1;
    for (int i = head[x];i != -1;i = edge[i].next)
    {
        int y = edge[i].to;
        if (dfsnum[y] == -1)
        {
            dfs(y);
            low[x] = min(low[x],low[y]);
        }
        else if (flag[y] == 1)
            low[x] = min(low[x],dfsnum[y]);
    }
    if (dfsnum[x] == low[x])
    {
        while (stack[top] != x)
        {
            flag[stack[top]] = 0;
            be[stack[top]] = an;
            top--;
        }
        flag[x] = 0;
        be[x] = an++;
        top--;
    }
}
void SC()
{
    memset(dfsnum,-1,sizeof(dfsnum));
    memset(flag,0,sizeof(flag));
    top = 0;
    an = 0;
    ans = 0;
    for (int i = 0;i < n;i++)
        if (dfsnum[i] == -1)
            dfs(i);
}
int ind[2000];

int main()
{
    int totcas;
    scanf("%d",&totcas);
    for (int cas = 1;cas <= totcas;cas++)
    {
        scanf("%d",&n);
        for (int i = 0;i < n;i++)
        {
            scanf("%d%d%d",&x[i],&y[i],&d[i]);
            head[i] = -1;
        }
        L = 0;
        for (int i = 0;i < n;i++)
            for (int j = 0;j < n;j++)
                if (i != j)
                {
                    if (2*abs(x[i]-x[j]) <= d[i] && 2*abs(y[i]-y[j]) <= d[i])
                        addedge(i,j);
                }

        SC();
        for (int i = 0;i < an;i++)
            ind[i] = 0;
        for (int i = 0;i < n;i++)
            for (int j = 0;j < n;j++)
                if (be[i] != be[j])
                {
                    if (2*abs(x[i]-x[j]) <= d[i] && 2*abs(y[i]-y[j]) <= d[i])
                        ind[be[j]]++;
                }
        int cnt = 0;
        for (int i = 0;i < an;i++)
            if (ind[i] == 0)
                cnt++;
        printf("%d\n",cnt);
    }
    return 0;
}

