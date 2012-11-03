#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
int n,f,dd;
int head[200*4],e,S,T;
char s[205];
struct N
{
    int v,next;
    int c;
}edge[200*200*10];
void addedge(int u,int v,int c)
{
   // printf("%d %d %d\n",u,v,c);
    edge[e].v=v;
    edge[e].c=c;
    edge[e].next=head[u];
    head[u]=e++;

    edge[e].v=u;
    edge[e].c=0;
    edge[e].next=head[v];
    head[v]=e++;
}
const int inf = 1<<29;
int low[200*4],cur[200*4],d[200*4],gap[200*4],pre[200*4],pree[200*4];
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
int main()
{
	while(scanf("%d%d%d",&n,&f,&dd)!=EOF)
	{
	    memset(head,-1,sizeof(head));
	    e=0;S=0;T=n+f+dd+1;
	    int i;
	    for(i=1;i<=f;i++)
        {
            int a;
            scanf("%d",&a);
            addedge(S,i,a);
        }
        for(i=1;i<=dd;i++)
        {
            int a;
            scanf("%d",&a);
            addedge(n+f+i,T,a);
        }
        int j;
        for(i=1;i<=n;i++)
        {
            scanf("%s",s);
            for(j=0;j<f;j++)
                if(s[j]=='Y')
                    addedge(j+1,f+i,1);
        }
        for(i=1;i<=n;i++)
        {
            scanf("%s",s);
            for(j=0;j<dd;j++)
                if(s[j]=='Y')
                    addedge(f+i,n+f+j+1,1);
        }
        printf("%d\n",sap(S,T,T+1));
	}
	return 0;
}
