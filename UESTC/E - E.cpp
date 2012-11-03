#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <set>
#include <vector>
using namespace std;

int head[510],totg,g[510][510];
int n,m;

struct node
{
    int a,b,tim,pre;
    node(){}
    node(int _a,int _b,int _tim,int _pre)
        {
            a = _a;
            b = _b;
            tim = _tim;
            pre = _pre;
        }
}now;

bool hash[510][510];
node Q[510*510];
int qhead,qtail;
vector<int> resa,resb;

void BFS()
{
    qhead = qtail = 0;
    Q[qtail++] = node(1,n,0,0);
    memset(hash,false,sizeof(hash));
    hash[1][n] = true;
    while (qhead < qtail)
    {
        now = Q[qhead++];
        if (now.b == 1 && now.a == n)
        {
            printf("%d\n",now.tim);
            for (int cur = qhead-1;cur != 0;cur = Q[cur].pre)
            {
                resa.push_back(Q[cur].a);
                resb.push_back(Q[cur].b);
            }
            resa.push_back(1);
            resb.push_back(n);
            for (int i = now.tim;i >= 0;i--)
                printf("%d ",resa[i]);
            printf("\n");
            for (int i = now.tim;i >= 0;i--)
                printf("%d ",resb[i]);
            printf("\n");
            return;
        }
        for (int i = 0;i < head[now.a];i++)
            for (int j = 0;j < head[now.b];j++)
                if (g[now.a][i] != g[now.b][j])
                    if (hash[g[now.a][i]][g[now.b][j]] == false)
                    {
                        hash[g[now.a][i]][g[now.b][j]] = true;
                        Q[qtail++] = node(g[now.a][i],g[now.b][j],now.tim+1,qhead-1);
                    }
    }
    printf("-1\n");
}

int main()
{
    scanf("%d%d",&n,&m);
    totg = 0;
    for (int i = 1;i <= n;i++)
        head[i] = 0;
    for (int i = 1;i <= m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        g[u][head[u]++] = v;
        g[v][head[v]++] = u;
    }
    BFS();
    return 0;
}
