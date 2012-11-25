#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int inf = 1<<30;
int n,m;
int peo[205];
int head[205],e,S,T;
int h[205],ee;
int fin[205],ans,cc;
bool vis[205];
int num1,num2,num3;
struct N
{
    int u,v,w,id;
    N (){}
    N(int _u,int _v,int _w,int _id)
    {
        u=_u;
        v=_v;
        w=_w;
        id=_id;
    }
}e1[2005],e2[55],e3[25];
struct M
{
    int v,next;
    int c,kind;
}edge[4005],ned[2005];
void addedge(int u,int v,int c)
{
    edge[e].v=v;
    edge[e].c=c;
    edge[e].next=head[u];
    head[u]=e++;

    edge[e].v=u;
    edge[e].c=0;
    edge[e].next=head[v];
    head[v]=e++;
}
void addned(int u,int v,int kind)
{
    ned[ee].v=v;
    ned[ee].kind=kind;
    ned[ee].next=h[u];
    h[u]=ee++;
}
void dfs(int s,int fa)
{
    int i,v;
    vis[s]=true;
    for(i=h[s];i!=-1;i=ned[i].next)
    {
        v=ned[i].v;
        if(!vis[v])
            dfs(v,fa);
        if(ned[i].kind!=-1)
            fin[fa]|=(1<<ned[i].kind);

    }
}
int low[250],gap[250],d[250],cur[250],pre[250],pree[250];
int sap(int ss,int tt,int all)
{
	int ret=0;
	bool fail;
	all+=ss;
	memset(low,0,sizeof(low));
	memset(gap,0,sizeof(gap));
	memset(d,0,sizeof(d));
	for(int i=ss;i<all;i++)
		cur[i]=head[i];
	low[ss]=inf;
	gap[ss]=all;
	int u=ss;
	while(d[ss]<all)
	{
		fail=true;
		for(int i=cur[u];i!=-1;i=edge[i].next)
		{
			int v=edge[i].v;
			cur[u]=i;
			if(edge[i].c&&d[u]==d[v]+1)
			{
				pre[v]=u;
				pree[v]=i;
				low[v]=min(low[u],edge[i].c);
				u=v;
				if(u==tt)
				{
					do
					{
						edge[pree[u]].c-=low[tt];
						edge[pree[u]^1].c+=low[tt];
						u=pre[u];
					}while(u!=ss);
					ret+=low[tt];
				}
				fail=false;
				break;
			}
		}
		if(fail)
		{
			gap[d[u]]--;
			if(!gap[d[u]])
				return ret;
			d[u]=all;
			for(int i=head[u];i!=-1;i=edge[i].next)
				if(edge[i].c)
					d[u]=min(d[u],d[edge[i].v]+1);
			gap[d[u]]++;
			cur[u]=head[u];
			if(u!=ss)
				u=pre[u];
		}
	}
	return ret;
}
void solve(int cho)
{
    memset(h,-1,sizeof(h));
    ee=0;
    int i,j,cost=0;
    for(i=0;i<num1;i++)
        addned(e1[i].u,e1[i].v,-1);
    for(i=0;i<num2;i++)
        addned(e2[i].u,e2[i].v,e2[i].id);
    for(i=0;i<num3;i++)
        if(cho&(1<<i))
        {
            cost+=e3[i].w;
            addned(e3[i].u,e3[i].v,-1);
        }
    memset(fin,0,sizeof(fin));
    for(i=1;i<=n;i++)
    {
        memset(vis,false,sizeof(vis));
        dfs(i,i);
    }
    memset(head,-1,sizeof(head));
    e=0;S=0;T=n+num2+1;
    for(i=1;i<=n;i++)
    {
        addedge(S,i,peo[i]);
        for(j=0;j<num2;j++)
            if(fin[i]&(1<<j))
                addedge(i,n+j+1,inf);
    }
    for(j=0;j<num2;j++)
        addedge(n+1+j,T,e2[j].w);
    int ma=sap(S,T,n+num2+2);
    if(ma>ans)
    {
        ans=ma;
        cc=cost;
    }
    else if(ma==ans)
        cc=min(cc,cost);
}
int main()
{
	while(scanf("%d%d",&n,&m)==2)
	{
	    int i;
	    ans=-1;cc=inf;
	    for(i=1;i<=n;i++)
            scanf("%d",&peo[i]);
        num1=num2=num3=0;
        for(i=0;i<m;i++)
        {
            int a,b,c,d;
            scanf("%d%d%d%d",&a,&b,&c,&d);
            if(d<0)
            {
                e2[num2]=N(a,b,c,num2);
                num2++;
            }
            if(d==0)
            {
                e1[num1]=N(a,b,c,num1);
                num1++;
            }
            if(d>0)
            {
                e3[num3]=N(a,b,c,num3);
                num3++;
            }
        }
        int sum=1<<num3;
        for(i=0;i<sum;i++)
            solve(i);
        if(ans==0)
            printf("Poor Heaven Empire\n");
        else
            printf("%d %d\n",ans,cc);
	}
	return 0;
}
