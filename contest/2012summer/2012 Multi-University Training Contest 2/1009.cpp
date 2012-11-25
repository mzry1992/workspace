#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const double inf = 1e20;
int n;
int head[50005],e,S,T;
double M;
struct N
{
    int v,next;
    double cost;
}edge[2500005];
void addedge(int u,int v,double c)
{
    edge[e].v=v;
    edge[e].cost=c;
    edge[e].next=head[u];
    head[u]=e++;
}
double dist[500005];
bool vis[500005];
class cmp
{
    public:
        bool operator()(const int a,const int b) const
            {
                return dist[a]<dist[b];
            }
};
void dij()
{
    int i,now,v;
    for(i=1;i<=n;i++)
    {
        vis[i]=false;
        dist[i]=-inf;
    }
    dist[S]=M;
    priority_queue<int,vector<int>,cmp> q;
    q.push(S);
    while(!q.empty())
    {
        now=q.top();
        q.pop();
        if(now==T) break;
        if(vis[now]) continue;
        vis[now]=true;
        for(i=head[now];i!=-1;i=edge[i].next)
        {
            v=edge[i].v;
            if(dist[v]<dist[now]*edge[i].cost)
            {
                dist[v]=dist[now]*edge[i].cost;
                q.push(v);
            }
        }
    }
}
int main()
{
	while(scanf("%d",&n)!=EOF)
    {
        int i,j;
        e=0;
        for(i=1;i<=n;i++)
        {
            head[i]=-1;
            int k;
            scanf("%d",&k);
            for(j=0;j<k;j++)
            {
                int a;
                double b;
                scanf("%d%lf",&a,&b);
                addedge(i,a,1.0-b/100.0);
            }
        }
        scanf("%d%d%lf",&S,&T,&M);
        dij();
        if(dist[T]==-inf)
            printf("IMPOSSIBLE!\n");
        else
            printf("%.2f\n",M-dist[T]);
    }
	return 0;
}
