#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct edge
{
    int to,next;
    bool bri;
}g[1000000];
int head[100000],L;
int n,m,u,v;

void init(int n)
{
    L = 0;
    memset(head,-1,4*n);
}

void addedge(int u,int v)
{
    g[L].to = v;
    g[L].next = head[u];
    g[L].bri = false;
    head[u] = L++;
}

int C[100000],D[100000],ance[100000],tim,Root;
bool cut[100000];

void DFS(int k,int fk,int deep)
{
    int i,tot;
    C[k] = 1;
    D[k] = deep;
    ance[k] = deep;
    tot = 0;
    for (int j = head[k];j != -1;j = g[j].next)
    {
        i = g[j].to;
        if (i != fk && C[i] == 1)
            ance[k] = min(ance[k],D[i]);
        if (C[i] == 0)
        {
            DFS(i,k,deep+1);
            tot++;
            ance[k] = min(ance[k],ance[i]);
            if (((k == Root) && (tot > 1)) ||
                ((k != Root) && (ance[i] >= D[k])))
                    cut[k] = true;
            if (ance[i] > D[k])
                g[j].bri = true;
        }
    }
}

void Gao(int n)
{
    memset(C,0,4*n);
    tim = 0;
    for (int i = 0;i < n;i++)
        if (C[i] == 0)
        {
            Root = i;
            DFS(i,-1,0);
        }
}

int main()
{
    while (scanf("%d%d",&n,&m) != EOF)
    {
        init(n);
        for (int i = 0;i < m;i++)
        {
            scanf("%d%d",&u,&v);
            u--;
            v--;
            addedge(u,v);
            addedge(v,u);
        }
        Gao(n);
        for (int i = 0;i < n;i++)
            if (cut[i] == true)
                cout << "Cut : " << i << endl;
    }
}
