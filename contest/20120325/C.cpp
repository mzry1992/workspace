#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const long long inf=0x3fffffffffffffffLL;
struct event
{
    int x,y,ty,typ,id;
    long long ans;
    event() {}
    event(int _x,int _y,int _typ,int _id)
    {
        x = _x;
        y = _y;
        typ = _typ;
        id = _id;
    }
    bool operator<(const event &a) const
    {
        return x<a.x;
    }
};

long long tree[4][150000*4];

event e[150000];
int n,q,tot;
int y[150000],toty;

void build(int x,int l,int r)
{
    if (l<r)
    {
        int mid=l+r>>1;
        build(x<<1,l,mid);
        build((x<<1)+1,mid+1,r);
    }
    tree[0][x]=tree[1][x]=tree[2][x]=tree[3][x]=inf;
}

void update(int typ,int x,int l,int r,int p,long long value)
{
    if (l==r)
    {
        tree[typ][x]=value;
        return ;
    }
    int mid=l+r>>1;
    if (p<=mid)
        update(typ,x<<1,l,mid,p,value);
    else
        update(typ,(x<<1)+1,mid+1,r,p,value);
    tree[typ][x]=min(tree[typ][x<<1],tree[typ][(x<<1)+1]);
}

long long _query(int typ,int x,int l,int r,int s,int t)
{
    if (s<=l && r<=t)
        return tree[typ][x];
    long long ret=inf;
    int mid=l+r>>1;
    if (s<=mid)
        ret=_query(typ,x*2,l,mid,s,t);
    if (t>mid)
        ret=min(ret,_query(typ,x*2+1,mid+1,r,s,t));
    return ret;
}

long long query(int typ,int x,int l,int r,int s,int t)
{
    long long ret = _query(typ,x,l,r,s,t);
    return ret;
}

long long ans[50000];
int find(long long x)
{
    int l=0,r=toty-1;
    while (l<r)
    {
        int mid=l+r>>1;
        if (x<=y[mid])
            r=mid;
        else
            l=mid+1;
    }
    return l;
}
int main()
{
    //freopen("C.in","r",stdin);
    bool first = true;
    while (true)
    {
        scanf("%d",&n);
        if (n == -1)    break;
        tot = 0;
        for (int i = 0; i < n; i++)
        {
            long long u,v;
            scanf("%d%d",&u,&v);
            e[tot++] = event(u,v,0,0);
        }
        scanf("%d",&q);
        for (int i = 0; i < q; i++)
        {
            long long u,v;
            scanf("%d%d",&u,&v);
            e[tot++] = event(u,v,1,i);
        }
        for (int i = 0; i < tot; i++)
            y[i] = e[i].y;
        sort(y,y+tot);
        toty = unique(y,y+tot)-y;
        for (int i = 0; i < tot; i++)
            e[i].ty = find(e[i].y);
        sort(e,e+tot);
        build(1,0,toty-1);
        for (int i=0; i<tot; i++)
            if (!e[i].typ)
            {
                update(2,1,0,toty-1,e[i].ty,e[i].x-e[i].y);
                update(3,1,0,toty-1,e[i].ty,e[i].x+e[i].y);
            }
        for (int i=0;i<tot;i++)
            if (e[i].typ)
            {
                e[i].ans=e[i].x+e[i].y+query(0,1,0,toty-1,0,e[i].ty);
                e[i].ans=min(e[i].ans,e[i].x-e[i].y+query(1,1,0,toty-1,e[i].ty,toty-1));
                e[i].ans=min(e[i].ans,-e[i].x+e[i].y+query(2,1,0,toty-1,0,e[i].ty));
                e[i].ans=min(e[i].ans,-e[i].x-e[i].y+query(3,1,0,toty-1,e[i].ty,toty-1));
                ans[e[i].id] = e[i].ans;
            }
            else
            {
                update(0,1,0,toty-1,e[i].ty,-e[i].x-e[i].y);
                update(1,1,0,toty-1,e[i].ty,-e[i].x+e[i].y);
                update(2,1,0,toty-1,e[i].ty,inf);
                update(3,1,0,toty-1,e[i].ty,inf);
            }
        if (first == false) puts("");
        first = false;
        for (int i = 0;i < q;i++)
            printf("%lld\n",ans[i]);
    }
    return 0;
}
