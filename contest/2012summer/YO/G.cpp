#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
int n,num;
int mp[55][55];
int d[30*50*50*2][55];
int head[30*50*50*2],e;
int ind[30*50*50*2];
struct N
{
    int v,next;
}edge[30*50*50*4];
void addedge(int u,int v)
{
    edge[e].v=v;
    edge[e].next=head[u];
    head[u]=e++;
}
int que[30*50*50*2],seg[30*50*50*2];
bool vis[30*50*50*2];
int findseg(int x)
{
    if(seg[x]==x)
        return x;
    else
        return seg[x]=findseg(seg[x]);
}
void tarjan(int u,int s)
{
    vis[u]=true;
    seg[u]=u;
    int i,v;
    for(i=head[u];i!=-1;i=edge[i].next)
    {
        v=edge[i].v;
        if(!vis[v])
        {
            tarjan(v,s);
            seg[v]=u;
        }
    }
    if(u==s)
    {
        for(i=n+1;i<=num;i++)
            if(vis[i])
                que[i]=findseg(i);
    }
    else if(u>n&&vis[s])
        que[u]=findseg(s);
}
int main()
{
	while(1)
	{
	    scanf("%d",&n);
	    memset(mp,0,sizeof(mp));
	    if(n==0)
            break;
        int i,j,k;
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                scanf("%d",&mp[i][j]);
        memset(head,-1,sizeof(head));
        memset(ind,0,sizeof(ind));
        e=0;
        num=mp[1][2]+n-1;
        addedge(1,n+1);
        ind[n+1]++;
        for(i=n+1;i<num;i++)
        {
            addedge(i,i+1);
            ind[i]++;ind[i+1]++;
            d[i][1]=i-n;
            d[i][2]=mp[1][2]-d[i][1];
        }
        ind[num]++;
        d[num][1]=mp[1][2]-1;
        d[num][2]=1;
        addedge(num,2);
        for(i=3;i<=n;i++)
        {
            bool flag;
            int p,res;
            for(j=n+1;j<=num;j++)
            {
                flag=true;
                res=mp[i][1]-d[j][1];
                for(k=2;k<i;k++)
                    if(res!=mp[i][k]-d[j][k])
                        flag=false;
                if(flag)
                {
                    p=j;
                    break;
                }
            }
            int re=num+1;
            num+=res-1;
            if(res==1)
            {
                addedge(p,i);
                ind[p]++;
            }
            else
            {
                addedge(p,re);
                ind[p]++;ind[re]++;
                for(j=re;j<num;j++)
                {
                    addedge(j,j+1);
                    ind[j]++;ind[j+1]++;
                    for(k=1;k<i;k++)
                        d[j][k]=d[p][k]+j-re+1;
                }
                for(k=1;k<i;k++)
                    d[num][k]=d[p][k]+num-re+1;
                ind[num]++;
                addedge(num,i);
            }
            for(j=re;j<=num;j++)
                d[j][i]=res-(j-re+1);
            memset(vis,false,sizeof(vis));
            memset(que,0,sizeof(que));
            tarjan(1,p);
            for(j=n+1;j<re;j++)
                d[j][i]=d[j][1]+d[p][1]-2*d[que[j]][1]+res;
        }
        sort(ind+n+1,ind+num+1);
        for(i=n+1;i<=num;i++)
        {
            if(i==n+1)
                printf("%d",ind[i]);
            else
                printf(" %d",ind[i]);
        }
        printf("\n");
	}
	return 0;
}
