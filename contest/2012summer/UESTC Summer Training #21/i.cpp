#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;
const int inf = 1<<30;
int n,m,ans;
int head[105],e;
int s[10005][2];
int sum[105],num;
stack<int> q;
struct N
{
    int v,next;
}edge[10005];
void addedge(int u,int v)
{
    edge[e].v=v;
    edge[e].next=head[u];
    head[u]=e++;
}
int dfn[105],low[105],ti;
bool vis[105];
void tarjan(int s)
{
    vis[s]=true;
    dfn[s]=low[s]=ti++;
    q.push(s);
    int i,v;
    for(i=head[s];i!=-1;i=edge[i].next)
    {
        v=edge[i].v;
        if(dfn[v]==-1)
        {
            tarjan(v);
            low[s]=min(low[s],low[v]);
        }
        else if(vis[v])
            low[s]=min(low[s],dfn[v]);
    }
    if(low[s]==dfn[s])
    {
        num++;
        do
        {
            v=q.top();
            q.pop();
            sum[num]++;
            vis[v]=false;
        }while(v!=s);
    }
}
void solve(int k)
{
    memset(head,-1,sizeof(head));
    e=0;
    int i;
    for(i=0;i<m;i++)
        if(s[i][0]!=k&&s[i][1]!=k)
            addedge(s[i][0],s[i][1]);
    memset(dfn,-1,sizeof(dfn));
    memset(vis,false,sizeof(vis));
    memset(low,0,sizeof(low));
    ti=0;num=0;
    memset(sum,0,sizeof(sum));
    for(i=0;i<n;i++)
        if(i!=k&&dfn[i]==-1)
            tarjan(i);
    int tmp=0;
    for(i=1;i<=num;i++)
        tmp=max(tmp,sum[i]);
    ans=min(ans,tmp);
}
int main()
{
	while(scanf("%d%d",&n,&m)==2)
	{
	    int i;
	    for(i=0;i<m;i++)
            scanf("%d%d",&s[i][0],&s[i][1]);
        ans=inf;
        for(i=0;i<n;i++)
            solve(i);
        if(ans<=1)
            printf("0\n");
        else
            printf("%d\n",ans);
	}
	return 0;
}
