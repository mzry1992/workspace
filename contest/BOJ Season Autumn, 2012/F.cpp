#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
int n,m;
int head[100005],e,S;
int id[200005][2];
struct M
{
    long long val;
    int from;
}dist[100005][2];
const long long inf = 1ll<<60;
struct N
{
    int u,v,next,num;
    long long len;
}edge[400005];
void addedge(int u,int v,int l,int k)
{
    edge[e].u=u;
    edge[e].v=v;
    edge[e].len=l;
    edge[e].num=k;
    edge[e].next=head[u];
    head[u]=e++;
}
bool vis[100005];
void SPFA()
{
    queue<int> q;
    int i,v;
    for(i=0;i<=n;i++)
    {
        vis[i]=false;
        dist[i][0].val=inf;
        dist[i][1].val=inf;
        dist[i][0].from=dist[i][1].from=-1;
    }
    dist[S][0].val=0;
    q.push(S);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        vis[u]=false;
        for(i=head[u];i!=-1;i=edge[i].next)
        {
            v=edge[i].v;
            if(u==S || (edge[id[dist[u][0].from][0]].v!=v && edge[id[dist[u][0].from][0]].u!=v))
            {
                if(dist[v][0].val>dist[u][0].val+edge[i].len)
                {
                    dist[v][1].val=dist[v][0].val;
                    dist[v][1].from=dist[v][0].from;

                    dist[v][0].val=dist[u][0].val+edge[i].len;
                    dist[v][0].from=edge[i].num;
                    if(!vis[v])
                    {
                        q.push(v);
                        vis[v]=true;
                    }
                }
                else if(dist[v][1].val>dist[u][0].val+edge[i].len)
                {
                    dist[v][1].val=dist[u][0].val+edge[i].len;
                    dist[v][1].from=edge[i].num;
                }
            }
            else
            {
                if(dist[v][0].val>dist[u][1].val+edge[i].len)
                {
                    dist[v][1].val=dist[v][0].val;
                    dist[v][1].from=dist[v][0].from;

                    dist[v][0].val=dist[u][1].val+edge[i].len;
                    dist[v][0].from=edge[i].num;
                    if(!vis[v])
                    {
                        q.push(v);
                        vis[v]=true;
                    }
                }
                else if(dist[v][1].val>dist[u][1].val+edge[i].len)
                {
                    dist[v][1].val=dist[u][1].val+edge[i].len;
                    dist[v][1].from=edge[i].num;
                }
            }
        }
    }
}
void Output(long long a)
{
    if(a==inf)
        printf("-1");
    else
        printf("%lld",a);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
	    scanf("%d%d",&n,&m);
	    int i;
	    e=0;S=0;
	    for(i=0;i<=n;i++)
            head[i]=-1;
        for(i=0;i<m;i++)
        {
            int a,b,c,d;
            scanf("%d",&a);
            id[i][0]=e;id[i][1]=a;
            if(a==1)
            {
                scanf("%d%d",&b,&c);
                addedge(S,b,c,i);
            }
            else
            {
                scanf("%d%d%d",&b,&c,&d);
                addedge(b,c,d,i);
                addedge(c,b,d,i);
            }
        }
        SPFA();
        for(i=0;i<m;i++)
        {
            if(id[i][1]==1)
            {
                int to=edge[id[i][0]].v;
                if(dist[to][0].from!=i)
                    Output(dist[to][0].val);
                else
                    Output(dist[to][1].val);
            }
            else
            {
                int k1=edge[id[i][0]].v;
                int k2=edge[id[i][0]+1].v;
                long long ans1,ans2;
                if(dist[k2][0].from!=i)
                    ans1=dist[k2][0].val;
                else
                    ans1=dist[k2][1].val;
                if(dist[k1][0].from!=i)
                    ans2=dist[k1][0].val;
                else
                    ans2=dist[k1][1].val;
                Output(ans1);
                printf(" ");
                Output(ans2);
            }
            puts("");
        }
	}
    return 0;
}

