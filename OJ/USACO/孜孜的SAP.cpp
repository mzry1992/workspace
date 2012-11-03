#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXEDGE 880000
#define MAXN 22000
struct edges
{
       int cap,to,next,flow;
}edge[MAXEDGE+100];
int L=-1,queue[MAXN+100],head[MAXN+100],mark[MAXN+100],N,pre[MAXN+100],gap[MAXN+100];
void add_edge(int x,int y,int z)
{
     edge[++L].cap=z;
     edge[L].flow=0;
     edge[L].to=y;
     edge[L].next=head[x];
     head[x]=L;
     edge[++L].cap=0;
     edge[L].flow=0;
     edge[L].to=x;
     edge[L].next=head[y];
     head[y]=L;
}
void bfs(int x)
{
     int s=0,t=0,i,u,v;
     memset(mark,255,sizeof(mark));
     queue[0]=x;mark[x]=0;
     gap[0]++;
     while (s<=t)
     {
           u=queue[s++];
           for (i=head[u];i!=-1;i=edge[i].next)
           {
               if (edge[i].cap) continue;
               v=edge[i].to;
               if (mark[v]!=-1) continue;
               mark[v]=mark[u]+1;
               gap[mark[v]]++;
               queue[++t]=v;
           }
     }
}
int maxflow(int s,int t)
{
    memset(gap,0,sizeof(gap));
    bfs(t);
    int u,i,v,flag,min,ans=0;
    u=s;pre[u]=-1;
    //gap[0]=N;
    while (mark[s]<N)
    {
          if (u==t)
          {
              min=200000000;
              for (i=pre[u];i!=-1;i=pre[edge[i^1].to])
                   if (min>edge[i].cap-edge[i].flow)
                      min=edge[i].cap-edge[i].flow;
              for (i=pre[u];i!=-1;i=pre[edge[i^1].to])
              {
                  edge[i].flow+=min;
                  edge[i^1].flow-=min;
              }
              u=s;
              ans+=min;
              continue;
          }
          min=N;flag=false;
          for (i=head[u];i!=-1;i=edge[i].next)
          {
              v=edge[i].to;
              if (edge[i].cap-edge[i].flow && mark[v]+1==mark[u])
              {
                 flag=true;
                 pre[v]=i;
                 break;
              }
              //if (edge[i].cap-edge[i].flow && mark[v]<min) if (u==0) printf("%d\n",edge[i].cap);
              if (edge[i].cap-edge[i].flow && mark[v]<min) min=mark[v];
          }
          if (flag)
          {
             u=v;
             continue;
          }
          //printf("%d\n",min);
          gap[mark[u]]--;
          if (!gap[mark[u]]) return ans;
          mark[u]=min+1;
          gap[mark[u]]++;
          if (u!=s) u=edge[pre[u]^1].to;
    }
    return ans;
}
int main()
{
    freopen("test.in","r",stdin);
    freopen("sap.txt","w",stdout);
    int n,m,x,y,z,i,T,cas=0;
    scanf("%d",&T);
    while (scanf("%d%d", &n, &m) == 2)
    {
    N=n;
    for (i=1;i<=n;i++)
        head[i]=mark[i]=-1;
    for (i=1;i<=m;i++)
    {
        scanf("%d%d%d",&x,&y,&z);
        add_edge(x,y,z);
    }
    printf("%d\n",cas,maxflow(1,n));
    }
    return 0;
}
