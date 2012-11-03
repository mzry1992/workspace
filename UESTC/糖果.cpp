#include <stdio.h>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <deque>
#include <algorithm>
using namespace std;

const int maxn = 100010;
const int maxk = 100010;
struct graph
{
    int to,next,dis;
}g[maxn*2+maxk*2];
int totg;
int n,m;
int d[maxn],tim[maxn];
bool visit[maxn];
deque<int> Q;

void addedge(int u,int v,int dis)
{
    totg++;
    g[totg].to = v;
    g[totg].dis = dis;
    g[totg].next = g[u].next;
    g[u].next = totg;
}

bool SPFA()
{
    Q.clear();
    memset(visit,false,sizeof(visit));
    memset(d,127,sizeof(d));
    memset(tim,0,sizeof(tim));
    d[0] = 0;
    Q.push_back(0);
    visit[0] = true;
    while (!Q.empty())
    {
        int now = Q.back();
        Q.pop_back();
        tim[now]++;
        if (tim[now] == n)  return false;
        visit[now] = false;
        for (int i = g[now].next;i != -1;i = g[i].next)
        {
            int to = g[i].to;
            if (d[to] > d[now]+g[i].dis)
            {
                d[to] = d[now]+g[i].dis;
                if (visit[to] == false)
                {
                    visit[to] = true;
                    Q.push_back(to);
                }
            }
        }
    }
    return true;
}

int main()
{
    while (scanf("%d%d",&n,&m) != EOF)
    {
        totg = n;
        for (int i = 0;i <= n;i++)  g[i].next = -1;
        for (int i = 1;i <= n;i++)  addedge(0,i,-1);
        for (int i = 1;i <= m;i++)
        {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            if (x == 1)
            {
                addedge(y,z,0);
                addedge(z,y,0);
            }
            else if (x == 2)
                addedge(y,z,-1);
            else if (x == 3)
                addedge(z,y,0);
            else if (x == 4)
                addedge(z,y,-1);
            else addedge(y,z,0);
        }
        bool hasres = SPFA();
        if (hasres == true)
        {
            long long res = 0;
            for (int i = 1;i <= n;i++)
                res += (long long)(-d[i]);
            printf("%lld\n",res);
        }
        else printf("-1\n");
    }
}
