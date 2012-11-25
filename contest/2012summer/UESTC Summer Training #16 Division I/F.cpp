#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
int n,m;
int head[2005],e;
long long ans;
struct N
{
    int v,next;
}edge[200005];
void addedge(int u,int v)
{
    edge[e].v=v;
    edge[e].next=head[u];
    head[u]=e++;

    edge[e].v=u;
    edge[e].next=head[v];
    head[v]=e++;
}
bool vis[2005],cha[2005];
int num[2005],de[2005];
long long tmp[2005];
void dfs(int s,int pre,int deep)
{
    de[s]=deep;
    num[s]=0;
    vis[s]=true;
    int i,v;
    for(i=head[s];i!=-1;i=edge[i].next)
    {
        v=edge[i].v;
        if ((pre^1)==i||de[v]>de[s])
            continue;
        if(!vis[v])
            dfs(v,i,deep+1);
        else
        {
            num[s]++;
            num[v]--;
        }
    }
}
void DFS(int s)
{
    vis[s]=true;
    int i,v;
    bool flag=false;
    for(i=head[s];i!=-1;i=edge[i].next)
    {
        v=edge[i].v;
        if(!vis[v])
        {
            DFS(v);
            num[s]+=num[v];
        }
    }
}
void Gao(int s,int fa,int pre)
{
    vis[s]=true;
    int i,v;
    tmp[s]=1;
    for(i=head[s];i!=-1;i=edge[i].next)
    {
        v=edge[i].v;
        cha[s]=true;
        if((pre^1)==i)
            continue;
        if(!vis[v])
        {
            Gao(v,s,i);
            if(num[s]!=0&&num[s]==num[v]&&cha[s])
            {
                ans+=tmp[v];
                tmp[s]=tmp[v]+1;
            }
        }
        else
            cha[v]=false;
    }
}
int main()
{
	while(scanf("%d%d",&n,&m)==2)
	{
	    int i;
	    memset(head,-1,sizeof(head));
	    e=0;
	    for(i=0;i<m;i++)
	    {
	        int a,b;
	        scanf("%d%d",&a,&b);
	        addedge(a,b);
	    }
	    memset(vis,false,sizeof(vis));
	    memset(de,-1,sizeof(de));
	    dfs(1,-1,0);
	    memset(vis,false,sizeof(vis));
	    DFS(1);
	    memset(vis,false,sizeof(vis));
	    memset(cha,false,sizeof(cha));
	    memset(tmp,0,sizeof(tmp));
	    ans=0;
	    Gao(1,0,-1);
	    long long sum=0;
	    for(i=2;i<=n;i++)
	    {
            if(num[i]==0)
            {
                ans+=(m-n+1);
                sum++;
            }
            if(num[i]==1)
                ans++;
	    }
	    ans+=sum*(sum-1)/2+sum*(n-1-sum);
	    printf("%I64d\n",ans);
	}
	return 0;
}
