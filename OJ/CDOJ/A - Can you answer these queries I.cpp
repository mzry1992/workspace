#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define ltree root*2,l,mid
#define rtree root*2+1,mid+1,r
using namespace std;

int n,m,a[50010],sum[50010],x,y;
struct segtree
{
    int lmax,rmax,max;
}tree[50010*4];

inline int getsum(int l,int r)
{
    return sum[r]-sum[l-1];
}

void build(int root,int l,int r)
{
    if (l == r)
        tree[root].lmax = tree[root].rmax = tree[root].max = a[l];
    else
    {
        int mid = (l+r)/2;
        build(ltree);
        build(rtree);
        tree[root].lmax = max(tree[root*2].lmax,getsum(l,mid)+tree[root*2+1].lmax);
        tree[root].rmax = max(tree[root*2+1].rmax,getsum(mid+1,r)+tree[root*2].rmax);
        tree[root].max = max(max(tree[root*2].max,tree[root*2+1].max),tree[root*2].rmax+tree[root*2+1].lmax);
    }
}

int queryl(int root,int l,int r,int ql,int qr)
{
    if (ql <= l && r <= qr)
        return tree[root].lmax;
    int mid = (l+r)/2;
    if (qr <= mid)  return queryl(ltree,ql,qr);
    if (ql > mid)   return queryl(rtree,ql,qr);
    return max(queryl(ltree,ql,mid),getsum(ql,mid)+queryl(rtree,mid+1,qr));
}

int queryr(int root,int l,int r,int ql,int qr)
{
    if (ql <= l && r <= qr)
        return tree[root].rmax;
    int mid = (l+r)/2;
    if (qr <= mid)  return queryr(ltree,ql,qr);
    if (ql > mid)   return queryr(rtree,ql,qr);
    return max(queryr(rtree,mid+1,qr),getsum(mid+1,qr)+queryr(ltree,ql,mid));
}

int query(int root,int l,int r,int ql,int qr)
{
    if (ql <= l && r <= qr)
        return tree[root].max;
    int mid = (l+r)/2;
    int res = -15007*50000;
    if (ql <= mid)  res = max(res,query(ltree,ql,min(qr,mid)));
    if (qr > mid)   res = max(res,query(rtree,max(ql,mid+1),qr));
    if (ql <= mid && qr > mid)
        res = max(res,queryl(1,1,n,mid+1,qr)+queryr(1,1,n,ql,mid));
    return res;
}

int main()
{
    scanf("%d",&n);
    sum[0] = 0;
    for (int i = 1;i <= n;i++)
    {
        scanf("%d",&a[i]);
        sum[i] = sum[i-1]+a[i];
    }
    build(1,1,n);
    scanf("%d",&m);
    for (int i = 1;i <= m;i++)
    {
        scanf("%d%d",&x,&y);
        printf("%d\n",query(1,1,n,x,y));
    }
}
