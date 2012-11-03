#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<stdlib.h>
using namespace std;
struct edges
{
       int to,next,key;
}edge[44000];
int head[22000],L,dp[22000],ans,v,k,K,flag[22000],f[22000],g[22000];
void add_edge(int x,int y,int z)
{
     edge[++L].to=y;
     edge[L].key=z;
     edge[L].next=head[x];
     head[x]=L;
}
void dfs2(int x,int y,int z)
{
     int i,max=0;dp[x]=1;
     for (i=head[x];i!=-1;i=edge[i].next)
     {
         if (edge[i].to==y || flag[edge[i].to]) continue;
         dfs2(edge[i].to,x,z);
         dp[x]+=dp[edge[i].to];
         if (max<dp[edge[i].to]) max=dp[edge[i].to];
     }
     if (max<z-dp[x]) max=z-dp[x];
     if (ans>max)
     {
        ans=max;
        v=x;
     }
}
void dfs3(int x,int y,int z)
{
     int i;
     //printf("x=%d fa[x]=%d\n",x,y);
     g[k++]=z;
     for (i=head[x];i!=-1;i=edge[i].next)
     {
         if (flag[edge[i].to] || edge[i].to==y) continue;
         dfs3(edge[i].to,x,z+edge[i].key);
     }
}
int dfs4(int x,int y)
{
    int i,res=1;
    for (i=head[x];i!=-1;i=edge[i].next)
    {
        if (flag[edge[i].to] || edge[i].to==y) continue;
        res+=dfs4(edge[i].to,x);
    }
    return res;
}
int dfs(int x)
{
     int y=dfs4(x,0);
     ans=y;
     dfs2(x,0,y);
     flag[v]=1;
     //printf("%d\n",v);
     int i,j,l,r,tot=0,res;
     for (j=k=0,i=head[v];i!=-1;i=edge[i].next,k=0)
     {
         if (flag[edge[i].to]) continue;
         dfs3(edge[i].to,v,edge[i].key);
         sort(g,g+k);
         for (r=0;r<k;r++)
             f[j++]=g[r];
         res=0;//printf("%d %d\n",edge[i].to,r);
         for (l=0,r=k-1;l<k-1;l++)
         {
               while (g[l]+g[r]>K && r>l+1)r--;
               if (g[l]+g[r]>K) break;
               res+=r-l;
         }
         //if (edge[i].to==3) printf("%d\n",g[0]);
         //printf("%d %d\n",edge[i].to,res);
         tot+=res;
     }
     sort(f,f+j);
     //printf("a%d %d\n",v,f[1]);
     res=0;
     for (l=0,r=j-1;l<j-1;l++)
     {
           while (f[l]+f[r]>K && r>l+1) r--;
           if (f[l]+f[r]>K) break;
           res+=r-l;
     }
     tot=res-tot;//printf("a%d %d\n",v,tot);
     //printf("a%d %d\n",v,tot);
     for (i=0;i<j;i++)
         if (f[i]<=K) tot++;
         else break;
     //for (i=0;i<j;i++) printf("a%d\n",f[i]);
     //printf("%d %d\n",v,tot);
     for (i=head[v];i!=-1;i=edge[i].next)
         if (!flag[edge[i].to]) tot+=dfs(edge[i].to);
     return tot;
}
int main()
{
    //freopen("1.out","r",stdin);
    //freopen("2.ans","w",stdout);
    int n,x,y,z,i;
    scanf("%d",&n);
    while (n)
    {
          scanf("%d",&K);
		  L=0;
          memset(flag,0,sizeof(flag));
          memset(head,255,sizeof(head));
          for (i=1;i<n;i++)
          {
              scanf("%d%d%d",&x,&y,&z);
              add_edge(x,y,z);
              add_edge(y,x,z);
          }
          printf("%d\n",dfs(1));
          scanf("%d",&n);
    }
    //system("pause");
    return 0;
}
