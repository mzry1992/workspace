#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

struct Edge
{
	int to,next,cost;
	bool dir;
};

Edge edge[200000];
int head[1000],L,dist[1000];
bool inq[1000];
int n,m,A,B,T,xs,xe,k;

struct node
{
    int now,dis,f;
    node(){}
    node(int _now,int _dis)
    {
        now = _now,dis = _dis;
        f = dis+dist[now];
    }
    friend bool operator <(const node& a,const node& b)
    {
        return a.f > b.f;
    }
};

void init()
{
    for (int i = 0;i < n;i++)
    {
        head[i] = dist[i] = -1;
        inq[i] = false;
    }
    L = 0;
}

void addedge(int u,int v,int c,bool dir)
{
    edge[L].to = v;
    edge[L].cost = c;
    edge[L].dir = dir;
    edge[L].next = head[u];
    head[u] = L++;
}

void SPFA()
{
    queue<int> Q;
    Q.push(xe);
    dist[xe] = 0;
    inq[xe] = true;
    while (!Q.empty())
    {
        int now = Q.front();
        Q.pop();
        inq[now] = false;
        for (int i = head[now];i != -1;i = edge[i].next)
            if (edge[i].dir == 1)
            {
                if (dist[edge[i].to] == -1 || dist[edge[i].to] > dist[now]+edge[i].cost)
                {
                    dist[edge[i].to] = dist[now]+edge[i].cost;
                    if (inq[edge[i].to] == false)
                    {
                        Q.push(edge[i].to);
                        inq[edge[i].to] = true;
                    }
                }
            }
    }
}

int AStar()
{
    priority_queue<node> Q;
    Q.push(node(xs,0));
    int kth = 0;
    while (!Q.empty())
    {
        node now = Q.top();
        Q.pop();
        if (now.now == xe)
        {
            kth++;
            if (kth == k)   return now.dis;
        }
        for (int i = head[now.now];i != -1;i = edge[i].next)
            if (edge[i].dir == 0)
                Q.push(node(edge[i].to,now.dis+edge[i].cost));
    }
    return -1;
}

int main()
{
    while (scanf("%d%d",&n,&m) != EOF)
    {
        init();
        for (int i = 0;i < m;i++)
        {
            scanf("%d%d%d",&A,&B,&T);
            A--;
            B--;
            addedge(A,B,T,0);
            addedge(B,A,T,1);
        }
        scanf("%d%d%d",&xs,&xe,&k);
        if (xs == xe)   k++;
        xs--;
        xe--;
        SPFA();
        printf("%d\n",AStar());
    }
	return 0;
}
