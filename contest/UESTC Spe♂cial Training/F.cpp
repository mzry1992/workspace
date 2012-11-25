#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
int n,m;
long long L;
int head[105],e;
bool vis[105];
long long dist[105][105];
long long mp[105][105];
long long ans1,ans2,tmp;
struct N
{
    int v,next;
    long long len;
    bool flag;
}edge[2005];
void addedge(int u,int v,long long l)
{
    edge[e].v=v;
    edge[e].flag=true;
    edge[e].len=l;
    edge[e].next=head[u];
    head[u]=e++;

    edge[e].v=u;
    edge[e].flag=true;
    edge[e].len=l;
    edge[e].next=head[v];
    head[v]=e++;
}
bool inq[105];
void SPFA(int s)
{
    queue<int> q;
    q.push(s);
    memset(inq,false,sizeof(inq));
    dist[s][s]=0;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        inq[u]=false;
        int i;
        for(i=head[u];i!=-1;i=edge[i].next)
        {
            int v=edge[i].v;
            if(edge[i].flag&&dist[s][v]>dist[s][u]+edge[i].len)
            {
                dist[s][v]=dist[s][u]+edge[i].len;
                if(!inq[v])
                {
                    inq[v]=true;
                    q.push(v);
                }
            }
        }
    }
}
int main()
{
	while(scanf("%d%d%lld",&n,&m,&L)==3)
	{
	    memset(head,-1,sizeof(head));
	    e=0;
	    int i,j;
	    for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                if(i==j)
                    mp[i][j]=0;
                else
                    mp[i][j]=L;
	    for(i=0;i<m;i++)
	    {
	        int a,b;
	        long long c;
	        scanf("%d%d%lld",&a,&b,&c);
	        addedge(a,b,c);
	        mp[a][b]=mp[b][a]=min(mp[b][a],c);
	    }
	    int k;
	    for(k=1;k<=n;k++)
            for(i=1;i<=n;i++)
                for(j=1;j<=n;j++)
                    mp[i][j]=min(mp[i][j],mp[i][k]+mp[k][j]);
        ans1=0;
        for(i=1;i<=n;i++)
            for(j=i+1;j<=n;j++)
                ans1+=mp[i][j];
        ans1*=2;
        ans2=0;
        for(i=0;i<m;i++)
        {
            long long d=edge[i*2].len;
            tmp=0;
            edge[i*2].flag=false;
            edge[(i*2)^1].flag=false;

            for(j=1;j<=n;j++)
                for(k=1;k<=n;k++)
                    if(j!=k)
                        dist[j][k]=L;
                    else
                        dist[j][k]=0;
            memset(vis,false,sizeof(vis));
            int a,b;
            a=edge[i*2].v;
            b=edge[(i*2)^1].v;
            SPFA(a);
            SPFA(b);
            tmp+=dist[a][b]*2;
            for(j=1;j<=n;j++)
            {
                if(j!=a&&j!=b)
                    tmp+=(dist[a][j]+dist[b][j])*2;
                for(k=1;k<=n;k++)
                    if(j!=k&&j!=a&&j!=b&&k!=a&&k!=b)
                    {
                        if(dist[a][j]+dist[b][k]+d>mp[j][k])
                            tmp+=mp[j][k];
                        else
                        {
                            if(vis[j])
                                tmp+=dist[j][k];
                            else if(vis[k])
                                tmp+=dist[k][j];
                            else
                            {
                                SPFA(j);
                                vis[j]=true;
                                tmp+=dist[j][k];
                            }
                        }
                    }
            }
            edge[i*2].flag=true;
            edge[(i*2)^1].flag=true;
            ans2=max(ans2,tmp);
        }
        printf("%lld %lld\n",ans1,ans2);
	}
    return 0;
}

