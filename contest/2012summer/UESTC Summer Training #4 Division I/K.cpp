#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int inf = 2147483647;
int n,m;
int head[50005],e;
int s[100005],val[50005];
int pos[50005][2],num;
bool vis[50005];
struct N
{
    int v,next;
}edge[50005];
struct M
{
    int l,r,mid;
    int val;
}node[50005*4];

void addedge(int u,int v)
{
    edge[e].v=v;
    edge[e].next=head[u];
    head[u]=e++;
}
void init(int p,int l,int r)
{
    node[p].l=l;
    node[p].r=r;
    node[p].mid=(l+r)>>2;
    if(l==r)
        node[p].val=s[l];
    else
    {
        init(p<<1,l,node[p].mid);
        init(p<<1|1,node[p].mid+1,r);
        node[p].val=inf;
    }
}
void dfs(int u)
{
    s[num]=val[u];
    pos[u][0]=num;
    num++;
    vis[u]=true;
    int i,v;
    for(i=head[u];i!=-1;i=edge[i].next)
    {
        v=edge[i].v;
        if(!vis[v])
            dfs(v);
    }
    s[num]=inf;
    pos[u][1]=num;
    num++;
}
int main()
{
	while(scanf("%d%d",&n,&m)==2)
	{
	    int i;
	    memset(head,-1,sizeof(head));
	    e=0;val[1]=inf;
	    for(i=2;i<=n;i++)
	    {
	        val[i]=inf;
	        int a;
	        scanf("%d",&a);
	        addedge(a,i);
	    }
	    for(i=0;i<m;i++)
            scanf("%d",&val[n-m+1+i]);
	    memset(vis,false,sizeof(vis));
	    num=0;
	    dfs(1);
	    init(1,0,num-1);

	}
	return 0;
}
