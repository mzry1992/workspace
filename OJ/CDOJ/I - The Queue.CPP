#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n;
struct graph
{
    int v;
    int next;
}g[5000];
int totg;
const long long mod = 1000000007LL;
long long f[2000];
long long t[2000];
long long c[2000][2000];
int ind[2000];

void addedge(int u,int v)
{
    totg++;
    g[totg].v = v;
    g[totg].next = g[u].next;
    g[u].next = totg;
}

void DFS(int now)
{
    bool isnull;
    isnull = true;
    long long tres = 1;
    long long tott = 0;
    int tots = 0;
    for (int tv = g[now].next;tv != -1;tv = g[tv].next)
    {
        isnull = false;
        int v = g[tv].v;
        DFS(v);
        tott += t[v];
        tots++;
        tres = (tres*f[v])%mod;
    }
    if (isnull == true)
        f[now] = t[now] = 1;
    else
    {
        t[now] = tott+1;
        for (int tv = g[now].next;tv != -1;tv = g[tv].next)
        {
            int v = g[tv].v;
            tres = (tres*c[tott][t[v]])%mod;
            tott -= t[v];
        }
        f[now] = tres;
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    memset(c,0,sizeof(c));
    c[0][0] = 1;
    for (int i = 1;i <= 1010;i++)
    {
        c[i][0] = 1;
        for (int j = 1;j <= i;j++)
            c[i][j] = (c[i-1][j-1]+c[i-1][j])%mod;
    }
    for (int ft = 1;ft <= T;ft++)
    {
        scanf("%d",&n);
        for (int i = 1;i <= n;i++)
            g[i].next = -1;
        totg = n;
        memset(ind,0,sizeof(ind));
        for (int i = 1;i <= n-1;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            addedge(u,v);
            ind[v]++;
        }
        int root;
        for (int i = 1;i <= n;i++)
        if (ind[i] == 0)    root = i;
        memset(f,0,sizeof(f));
        memset(t,0,sizeof(t));
        DFS(root);
        printf("Case %d: ",ft);
        cout << f[root] << endl;
    }
}
