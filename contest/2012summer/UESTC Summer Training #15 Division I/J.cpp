#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
int n,m,K,d;
int head[35],e;
int val[35];
struct N
{
    int v,next;
    int len;
}edge[2005];
void addedge(int u,int v)
{
    edge[e].v=v;
    edge[e].len=1;
    edge[e].next=head[u];
    head[u]=e++;

    edge[e].v=u;
    edge[e].len=1;
    edge[e].next=head[v];
    head[v]=e++;
}
int dist[35];
const int inf = 1<<30;
const int mod =1000000007;
bool vis[35];
void SPFA()
{
    memset(vis,false,sizeof(vis));
    int i;
    for(i=0;i<n;i++)
        dist[i]=inf;
    queue<int> q;
    q.push(K);dist[K]=0;vis[K]=true;
    while(!q.empty())
    {
        int now,v;
        now=q.front();
        q.pop();
        vis[now]=false;
        for(i=head[now];i!=-1;i=edge[i].next)
        {
            v=edge[i].v;
            if(dist[v]>dist[now]+edge[i].len)
            {
                dist[v]=dist[now]+edge[i].len;
                if(!vis[v])
                {
                    q.push(v);
                    vis[v]=true;
                }
            }
        }
    }
}
struct Matrix
{
    int n,m;
    int a[30][30];
    Matrix operator*(Matrix x)
    {
        Matrix ret;
        ret.n=n;
        ret.m=x.m;
        for (int i=0;i<n;i++)
            for (int j=0;j<x.m;j++)
            {
                ret.a[i][j]=0;
                for (int k=0;k<m;k++)
                {
                    ret.a[i][j]+=(long long)a[i][k]*x.a[k][j]%mod;
                    if (ret.a[i][j]>=mod)
                        ret.a[i][j]-=mod;
                }
            }
        return ret;
    }
    Matrix operator^(int x)
    {
        Matrix ret;
        ret.n=n;
        ret.m=m;
        memset(ret.a,0,sizeof(ret.a));
        for (int i=0;i<n;i++)
            ret.a[i][i]=1;
        for (;x;x>>=1,*this=(*this)*(*this))
            if (x&1)
                ret=ret*(*this);
        return ret;
    }
    void init()
    {
        memset(a,0,sizeof(a));
    }
}odd,even,sum;
int main()
{
	int t,cas=1;
	scanf("%d",&t);
	while(t--)
	{
	    scanf("%d%d%d%d",&n,&m,&K,&d);
	    int i,j;
	    memset(head,-1,sizeof(head));
	    e=0;
	    for(i=0;i<m;i++)
	    {
	        int a,b;
	        scanf("%d%d",&a,&b);
	        addedge(a,b);
	    }
	    SPFA();
	    memset(val,0,sizeof(val));
        odd.init();even.init();
        odd.n=odd.m=n;
        even.n=even.m=n;
        for(i=0;i<n;i++)
        {
            odd.a[i][i]=even.a[i][i]=1;
            int v;
            for(j=head[i];j!=-1;j=edge[j].next)
            {
                v=edge[j].v;
                if(dist[i]%2)
                    odd.a[v][i]=1;
                else
                    even.a[v][i]=1;
            }
        }
        sum=odd*even;
        sum=sum^(d/2);
        if(d&1)
            sum=sum*odd;
        printf("Case %d:",cas++);
        for(i=0;i<n;i++)
        {
            val[i]=sum.a[K][i];
            printf(" %d",val[i]);
        }
        printf("\n");
	}
	return 0;
}
