#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
const int MAXN=100;
const int MAXM=1000;
int N,L;
int head[MAXN];
struct edges
{
    int to,next,cost;
} edge[MAXM];
int dist[MAXN];
class states
{
public:
    int id,wait;
    int cost[10];
};
class cmp
{
public:
    bool operator ()(const states &i,const states &j)
    {
        return i.cost>j.cost;
    }
};
void init(int n)
{
    N=n;
    L=0;
    for (int i=0; i<n; i++)
        head[i]=-1;
}
void add_edge(int x,int y,int cost)
{
    edge[L].to=y;
    edge[L].cost=cost;
    edge[L].next=head[x];
    head[x]=L++;
}
int dijkstra(int s,int t)
{
    memset(dist,63,sizeof(dist));
    states u;
    u.id=s;
    u.cost=0;
    dist[s]=0;
    priority_queue<states,vector<states>,cmp> q;
    q.push(u);
    while (!q.empty())
    {
        u=q.top();
        q.pop();
        if (u.id==t) return dist[t];
        if (u.cost!=dist[u.id]) continue;
        for (int i=head[u.id]; i!=-1; i=edge[i].next)
        {
            states v=u;
            v.id=edge[i].to;
            if (dist[v.id]>dist[u.id]+edge[i].cost)
            {
                v.cost=dist[v.id]=dist[u.id]+edge[i].cost;
                q.push(v);
            }
        }
    }
    return -1;
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    init(n);
    for (int i=0; i<m; i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        add_edge(x,y,z);
        add_edge(y,x,z);
    }
    int s,t;
    scanf("%d%d",&s,&t);
    printf("%d\n",dijkstra(s,t));
    return 0;
}
