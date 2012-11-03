#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
const int MAXN = 500000;
int n,m;
int head[MAXN],e;
int sum[MAXN];
int num;
struct N
{
    int v,next;
} edge[500000],neg[500000];
int h[MAXN],ee;
void addedge(int u,int v)
{
    edge[e].v=v;
    edge[e].next=head[u];
    head[u]=e++;

    neg[ee].v=u;
    neg[ee].next=h[v];
    h[v]=ee++;
}
int seg[MAXN],len[MAXN];
int findseg(int x)
{
    if(seg[x]==x)
        return x;
    else
        return seg[x]=findseg(seg[x]);
}
int Seg[MAXN];
int findSeg(int x)
{
    if(Seg[x]==x)
        return x;
    else
        return Seg[x]=findSeg(Seg[x]);
}
bool vis[MAXN],loop[MAXN];
int isloop[MAXN];
int dfs(int u,int d)
{
    vis[u]=true;
    len[u]=d;
    int i,v;
    for(i=head[u]; i!=-1; i=edge[i].next)
    {
        v=edge[i].v;
        if(!vis[v])
        {
            int tmp=dfs(v,d+1);
            if(tmp!=-1)
            {
                isloop[u]=num;
                if(tmp==u)
                {
                    sum[num]-=d-1;
                    num++;
                    return -1;
                }
            }
            return tmp;
        }
        else
        {
            sum[num]=d;
            isloop[u]=num;
            return v;
        }
    }
    return -1;
}
int fa[MAXN][20],deep[MAXN];
void dfslca(int u,int ufa,int D)
{
    deep[u]=D;
    int i,v;
    fa[u][0]=ufa;
    for(i=1; i<20; i++)
        fa[u][i]=fa[fa[u][i-1]][i-1];
    for(i=h[u]; i!=-1; i=neg[i].next)
    {
        v=neg[i].v;
        if(isloop[v]==0)
        {
            isloop[v]=isloop[u];
            dfslca(v,u,D+1);
            Seg[v]=u;
        }
    }
}
int getLCA(int u,int v)
{
    if(deep[u]<deep[v])
        swap(u,v);
    int d=1<<19,i;
    for(i=19; i>=0; i--)
    {
        if(d<=deep[u]-deep[v])
            u=fa[u][i];
        d>>=1;
    }
    if(u==v)
        return u;
    for(i=19; i>=0; i--)
        if(fa[u][i]!=fa[v][i])
        {
            u=fa[u][i];
            v=fa[v][i];
        }
    return fa[u][0];
}
bool fffff[MAXN];
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        int i;
        e=ee=0;
        for(i=1; i<=n; i++)
        {
            Seg[i]=seg[i]=i;
            head[i]=h[i]=-1;
            vis[i]=loop[i]=false;
            deep[i]=len[i]=-1;
            isloop[i]=0;
            fffff[i]=false;
        }
        for(i=1; i<=n; i++)
        {
            int a,fa,fb;
            scanf("%d",&a);
            addedge(i,a);
            fa=findseg(i);
            fb=findseg(a);
            seg[fa]=fb;
        }
        num=1;
        for(i=1; i<=n; i++)
            if(!loop[findseg(i)])
            {
                dfs(i,0);
                loop[findseg(i)]=true;
            }
        for(i=1; i<=n; i++)
            if(isloop[i]>0)
                fffff[i]=true;
        for(i=1; i<=n; i++)
            if(fffff[i])
                dfslca(i,-1,0);
        int ans1,ans2;
        for(i=0; i<m; i++)
        {
            int k1,k2;
            scanf("%d%d",&k1,&k2);
            ans1=ans2=0;
            if(isloop[k1]!=isloop[k2])
                printf("-1 -1\n");
            else
            {
                int fa,fb;
                fa=findSeg(k1);
                fb=findSeg(k2);
                if(fa!=fb)
                {
                    int tmp1,tmp2;
                    ans1+=deep[k1];
                    ans2+=deep[k2];
                    int dist=abs(len[fa]-len[fb]);
                    if(len[fa]<len[fb])
                    {
                        ans1+=dist;
                        tmp1=deep[k1];
                        tmp2=deep[k2]+sum[isloop[k2]]-dist;
                    }
                    else
                    {
                        ans2+=dist;
                        tmp1=deep[k1]+sum[isloop[k2]]-dist;
                        tmp2=deep[k2];
                    }
                    if(max(tmp1,tmp2)<max(ans1,ans2))
                    {
                        ans1=tmp1;
                        ans2=tmp2;
                    }
                    else if(max(tmp1,tmp2)==max(ans1,ans2)&&min(tmp1,tmp2)<min(ans1,ans2))
                    {
                        ans1=tmp1;
                        ans2=tmp2;
                    }
                    else if(max(tmp1,tmp2)==max(ans1,ans2)&&min(tmp1,tmp2)==min(ans1,ans2))
                    {
                        if(ans1<ans2)
                            swap(ans1,ans2);
                    }
                }
                else
                {
                    int root=getLCA(k1,k2);
                    ans1=deep[k1]-deep[root];
                    ans2=deep[k2]-deep[root];
                }
                printf("%d %d\n",ans1,ans2);
            }
        }
    }
    return 0;
}
