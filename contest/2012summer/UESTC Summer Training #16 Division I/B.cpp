#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
#pragma comment(linker, "/STACK:1024000000,1024000000")

int n,m,sum,pos;
int head[100005],e;
int s[100005],from[100005];
int fa[100005][21],deep[100005],num[100005];
int solid[100005],p[100005],fp[100005];
struct N
{
    int l,r,mid;
    int w;
}nod[100005*4];
struct M
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
void LCA(int st,int f,int d)
{
    deep[st]=d;
    fa[st][0]=f;
    num[st]=1;
    int i,v;
    for(i=1;i<21;i++)
        fa[st][i]=fa[fa[st][i-1]][i-1];
    for(i=head[st];i!=-1;i=edge[i].next)
    {
        v=edge[i].v;
        if(v!=f)
        {
            LCA(v,st,d+1);
            num[st]+=num[v];
            if(solid[st]==-1||num[v]>num[solid[st]])
                solid[st]=v;
        }
    }
}
void getpos(int st,int sp)
{
    from[st]=sp;
    if(solid[st]!=-1)
    {
        p[st]=pos++;
        fp[p[st]]=st;
        getpos(solid[st],sp);
    }
    else
    {
        p[st]=pos++;
        fp[p[st]]=st;
        return;
    }
    int i,v;
    for(i=head[st];i!=-1;i=edge[i].next)
    {
        v=edge[i].v;
        if(v!=solid[st]&&v!=fa[st][0])
            getpos(v,v);
    }
}
int getLCA(int u,int v)
{
    if(deep[u]<deep[v])
        swap(u,v);
    int d=1<<20,i;
    for(i=20;i>=0;i--)
    {
        if(d<=deep[u]-deep[v])
            u=fa[u][i];
        d>>=1;
    }
    if(u==v)
        return u;
    for(i=20;i>=0;i--)
        if(fa[u][i]!=fa[v][i])
        {
            u=fa[u][i];
            v=fa[v][i];
        }
    return fa[u][0];
}
void init(int p,int l,int r)
{
    nod[p].l=l;
    nod[p].r=r;
    nod[p].mid=(l+r)>>1;
    if(l==r)
        nod[p].w=s[fp[l]];
    else
    {
        init(p<<1,l,nod[p].mid);
        init(p<<1|1,nod[p].mid+1,r);
        nod[p].w=max(nod[p<<1].w,nod[p<<1|1].w);
    }
}
void update(int p,int l,int r,int v)
{
    if(nod[p].l==l&&nod[p].r==r)
    {
        nod[p].w+=v;
        return;
    }
    if(nod[p].mid<l)
        update(p<<1|1,l,r,v);
    else if(nod[p].mid>=r)
        update(p<<1,l,r,v);
    nod[p].w=max(nod[p<<1].w,nod[p<<1|1].w);
}
int read(int p,int l,int r)
{
    if(nod[p].l==l&&nod[p].r==r)
        return nod[p].w;
    if(nod[p].mid<l)
        return read(p<<1|1,l,r);
    else if(nod[p].mid>=r)
        return read(p<<1,l,r);
    else
    {
        int k1,k2;
        k1=read(p<<1,l,nod[p].mid);
        k2=read(p<<1|1,nod[p].mid+1,r);
        return max(k1,k2);
    }
}
const int inf = 1<<30;
int jump(int st,int ed)
{
    int res=-inf;
    while(deep[st]>=deep[ed])
    {
        int tmp=from[st];
        if(deep[tmp]<deep[ed])
            tmp=ed;
        res=max(res,read(1,p[tmp],p[st]));
        st=fa[tmp][0];
    }
    return res;
}
int getans(int st,int ed)
{
    int res=-inf;
    int lca=getLCA(st,ed);
    res=max(res,jump(st,lca));
    res=max(res,jump(ed,lca));
    return res;
}
int main()
{
    while(scanf("%d",&n)==1)
    {
        memset(head,-1,sizeof(head));
        e=0;
        int i;
        pos=0;deep[0]=-1;
        memset(s,0,sizeof(s));
        memset(solid,-1,sizeof(solid));
        for(i=0;i<n-1;i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            addedge(a,b);
        }
        LCA(1,0,0);
        getpos(1,1);
        init(1,0,pos-1);
        int Q;
        scanf("%d",&Q);
        for(i=0;i<Q;i++)
        {
            char que[5];
            scanf("%s",que);
            if(que[0]=='I')
            {
                int a,b;
                scanf("%d%d%d",&a,&b);
                update(1,p[a],p[a],b);
            }
            else
            {
                int a,b;
                scanf("%d%d",&a,&b);
                printf("%d\n",getans(a,b));
            }
        }
    }
	return 0;
}
