#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

int typ[100000],h[100000],last[100000],pre[100000];
int lazy[400000],tree[400000],mx[400000],td[400000];
void down(int x,int l,int r)
{
    if (lazy[x]==-1)
        return ;
    mx[x]=lazy[x];
    if (l<r)
        lazy[x*2]=lazy[x*2+1]=lazy[x];
    lazy[x]=0;
    tree[x]=td[x]+mx[x];
}
void update(int x,int l,int r,int p,int v)
{
    down(x,l,r);
    if (l==r)
    {
        td[x]=v;
        tree[x]=td[x]+mx[x];
        return ;
    }
    int mid=l+r>>1;
    if (p<=mid)
    {
        update(x*2,l,mid,p,v);
        down(x*2+1,mid+1,r);
    }
    else
    {
        update(x*2+1,mid+1,r,p,v);
        down(x*2,l,mid);
    }
    td[x]=min(td[x*2],td[x*2+1]);
    tree[x]=min(tree[x*2],tree[x*2+1]);
}
void update(int x,int l,int r,int s,int t,int v)
{
    down(x,l,r);
    if (s<=l && r<=t)
    {
        lazy[x]=v;
        down(x,l,r);
        return ;
    }
    int mid=l+r>>1;
    if (s<=mid)
        update(x*2,l,mid,s,t,v);
    else
        down(x*2,l,mid);
    if (t>mid)
        update(x*2+1,mid+1,r,s,t,v);
    else
        down(x*2+1,mid+1,r);
    mx[x]=min(mx[x*2],mx[x*2+1]);
    tree[x]=min(tree[x*2],tree[x*2+1]);
}
int query(int x,int l,int r,int s,int t)
{
    down(x,l,r);
    if (s<=l && r<=t)
        return tree[x];
    int mid=l+r>>1,ret=0x7fffffff;
    if (s<=mid)
        ret=query(x*2,l,mid,s,t);
    if (t>mid)
        ret=min(query(x*2+1,mid+1,r,s,t),ret);
    return ret;
}
int main()
{
    int t;
    scanf("%d",&t);
    for (int cas=1; cas<=t; cas++)
    {
        int n;
        scanf("%d",&n);
        memset(last,-1,sizeof(last));
        for (int i = 0; i < n; i++)
        {
            scanf("%d%d",&typ[i],&h[i]);
            typ[i]--;
            pre[i] = last[typ[i]];
            last[typ[i]] = i;
        }
    }
}
