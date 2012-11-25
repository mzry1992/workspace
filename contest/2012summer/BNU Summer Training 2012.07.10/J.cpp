#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
int n,m;
int head[100005],e;
int ind[100005];
bool vis[100005];
int mrk[100005];
queue<int> q;
vector<int> k1,k2;
struct N
{
    int v,next;
}edge[600005];
void addedge(int u,int v)
{
    edge[e].v=v;
    edge[e].next=head[u];
    head[u]=e++;

    edge[e].v=u;
    edge[e].next=head[v];
    head[v]=e++;
}
bool bfs()
{
    int i,now,v;
    while(!q.empty())
    {
        now=q.front();
        q.pop();
        int num=0;
        for(i=head[now];i!=-1;i=edge[i].next)
        {
            v=edge[i].v;
            if(mrk[v]==-1)
            {
                mrk[v]=mrk[now]^1;
                q.push(v);
            }
            else if(mrk[v]==mrk[now])
            {
                num++;
                if(num>=2)
                    return false;
            }
        }
    }
    return true;
}
void solve(int st)
{
    memset(mrk,-1,sizeof(mrk));
    mrk[st]=0;
    while(!q.empty())
        q.pop();
    q.push(st);
    if(bfs())
    {
        int i;
        for(i=1;i<=n;i++)
        {
            if(mrk[i]==0)
                k1.push_back(i);
            if(mrk[i]==1)
                k2.push_back(i);
            if(mrk[i]!=-1)
                vis[i]=true;
        }
        return;
    }
    else
    {
        int i,v;
        for(i=head[st];i!=-1;i=edge[i].next)
        {
            memset(mrk,-1,sizeof(mrk));
            v=edge[i].v;
            mrk[st]=0;mrk[v]=0;
            while(!q.empty())
                q.pop();
            q.push(st);q.push(v);
            if(bfs())
            {
                int i;
                for(i=1;i<=n;i++)
                {
                    if(mrk[i]==0)
                        k1.push_back(i);
                    if(mrk[i]==1)
                        k2.push_back(i);
                    if(mrk[i]!=-1)
                        vis[i]=true;
                }
                return;
            }
        }
    }
}
int main()
{
	while(scanf("%d%d",&n,&m)==2)
	{
	    int i;
	    memset(ind,0,sizeof(ind));
	    memset(head,-1,sizeof(head));
	    e=0;
	    for(i=0;i<m;i++)
	    {
	        int a,b;
	        scanf("%d%d",&a,&b);
	        addedge(a,b);
	        ind[a]++;ind[b]++;
	    }
	    bool flag=true;
	    for(i=1;i<=n;i++)
            if(ind[i]>1)
                flag=false;
        if(flag)
        {
            printf("1\n");
            for(i=1;i<n;i++)
                printf("%d ",i);
            printf("%d\n",n);
            continue;
        }
        k1.clear();k2.clear();
	    memset(vis,false,sizeof(vis));
	    for(i=1;i<=n;i++)
            if(!vis[i])
                solve(i);
        sort(k1.begin(),k1.end());
        sort(k2.begin(),k2.end());
        printf("2\n");
        for(i=0;i<k1.size();i++)
        {
            if(i==0)
                printf("%d",k1[i]);
            else
                printf(" %d",k1[i]);
        }
        printf("\n");
        for(i=0;i<k2.size();i++)
        {
            if(i==0)
                printf("%d",k2[i]);
            else
                printf(" %d",k2[i]);
        }
        printf("\n");
	}
	return 0;
}
