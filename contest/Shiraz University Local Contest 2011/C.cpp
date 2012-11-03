#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n;
int head[10005],e;
struct N
{
    int v,next;
}edge[20005];
void addedge(int u,int v)
{
    edge[e].v=v;
    edge[e].next=head[u];
    head[u]=e++;
}
bool vis[10005];
int mx,pos;
void dfs(int u,int deep)
{
    vis[u]=true;
    if(deep>mx)
    {
        mx=deep;
        pos=u;
    }
    int i,v;
    for(i=head[u];i!=-1;i=edge[i].next)
    {
        v=edge[i].v;
        if(!vis[v])
            dfs(v,deep+1);
    }
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
	    scanf("%d",&n);
	    int i,j;
	    memset(head,-1,sizeof(head));
	    e=0;
	    for(i=1;i<=n;i++)
	    {
	        int a;
	        scanf("%d",&a);
            for(j=0;j<a;j++)
            {
                int b;
                scanf("%d",&b);
                addedge(i,b);
            }
	    }
	    memset(vis,false,sizeof(vis));
	    mx=-1;
	    dfs(1,0);
	    memset(vis,false,sizeof(vis));
	    mx=-1;
	    dfs(pos,0);
	    printf("%d\n",2*n-2-mx);
	}
    return 0;
}

