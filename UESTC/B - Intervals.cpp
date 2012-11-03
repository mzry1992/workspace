#include <iostream>
#include <cstdio>
#include <cstring>
#include <deque>
using namespace std;

const int maxn = 51000;
const int n = 50000;
int m;
struct graph
{
    int next;
    int to;
    int dis;
}g[maxn+maxn*3];
int totg;

void addedge(int u,int v,int dis)
{
    totg++;
    g[totg].to = v;
    g[totg].dis = dis;
    g[totg].next = g[u].next;
    g[u].next = totg;
}

int dis[maxn];
bool visit[maxn];
deque<int> Q;

int SPFA(int s)
{
    Q.clear();
    for (int i = 0;i <= n;i++)
    {
        visit[i] = false;
        dis[i] = 1992100500;
    }
    dis[s] = 0;
    visit[s] = true;
    Q.push_back(s);
    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop_front();
        visit[u] = false;
        for (int vv = g[u].next;vv != -1;vv = g[vv].next)
        {
            int v = g[vv].to;
            int dist = g[vv].dis;
            if (dis[v] > dis[u]+dist)
            {
                dis[v] = dis[u]+dist;
                if (visit[v] == false)
                {
                    visit[v] = true;
                    Q.push_back(v);
                }
            }
        }
    }
    return dis[0];
}

int main()
{
    while (scanf("%d",&m) != EOF)
    {
        for (int i = 0;i <= n;i++)
            g[i].next = -1;
        totg = n;
        for (int i = 1;i <= n;i++)
        {
            addedge(i,i+1,1);
            addedge(i,i-1,0);
        }
        int maxb = 0;
        for (int i = 1;i <= m;i++)
        {
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            addedge(b+1,a,-c);
            if (b+1 > maxb)   maxb = b+1;
        }
        printf("%d\n",-SPFA(maxb));
    }
}
