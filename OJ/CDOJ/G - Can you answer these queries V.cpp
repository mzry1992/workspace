#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int MaxN = 10001;
int n,a[MaxN],sum[MaxN],q,x1,x2,y1,y2,res;
struct segtree
{
    int lmax,rmax,mmax;
}tree[MaxN*4];

inline int getsum(int l,int r)
{
    return sum[r]-sum[l-1];
}

void build(int root,int l,int r)
{
    if (l == r)
    {
        tree[root].lmax = tree[root].rmax = tree[root].mmax = a[l];
        return;
    }
    int mid = (l+r)/2;
    build(root*2,l,mid);
    build(root*2+1,mid+1,r);
    tree[root].lmax = max(tree[root*2].lmax,getsum(l,mid)+tree[root*2+1].lmax);
    tree[root].rmax = max(tree[root*2+1].rmax,getsum(mid+1,r)+tree[root*2].rmax);
    tree[root].mmax = max(max(tree[root*2].mmax,tree[root*2+1].mmax),tree[root*2].rmax+tree[root*2+1].lmax);
}

int queryl(int root,int l,int r,int ql,int qr)
{
    if (ql <= l && r <= qr)
        return tree[root].lmax;
    int mid = (l+r)/2;
    if (qr <= mid)  return queryl(root*2,l,mid,ql,qr);
    if (ql > mid)   return queryl(root*2+1,mid+1,r,ql,qr);
    return max(queryl(root*2,l,mid,ql,mid),getsum(ql,mid)+queryl(root*2+1,mid+1,r,mid+1,qr));
}

int queryr(int root,int l,int r,int ql,int qr)
{
    if (ql <= l && r <= qr)
        return tree[root].rmax;
    int mid = (l+r)/2;
    if (qr <= mid)  return queryr(root*2,l,mid,ql,qr);
    if (ql > mid)   return queryr(root*2+1,mid+1,r,ql,qr);
    return max(queryr(root*2+1,mid+1,r,mid+1,qr),getsum(mid+1,qr)+queryr(root*2,l,mid,ql,mid));
}

int querym(int root,int l,int r,int ql,int qr)
{
    if (ql <= l && r <= qr)
        return tree[root].mmax;
    int mid = (l+r)/2;
    int res = -19921005;
    if (ql <= mid)  res = max(res,querym(root*2,l,mid,ql,min(qr,mid)));
    if (qr > mid)   res = max(res,querym(root*2+1,mid+1,r,max(ql,mid+1),qr));
    if (ql <= mid && qr > mid)
        res = max(res,queryl(1,1,n,mid+1,qr)+queryr(1,1,n,ql,mid));
    return res;
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d",&n);
        sum[0] = 0;
        a[0] = 0;
        for (int i = 1;i <= n;i++)
        {
            scanf("%d",&a[i]);
            sum[i] = sum[i-1]+a[i];
        }
        build(1,1,n);
        scanf("%d",&q);
        for (int i = 1;i <= q;i++)
        {
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            if (y1 < x2)
                res = getsum(y1+1,x2-1)+queryl(1,1,n,x2,y2)+queryr(1,1,n,x1,y1);
            else
            {
                res = querym(1,1,n,x2,y1);
                if (x1 <= x2-1)
                    res = max(res,queryl(1,1,n,x2,y2)+queryr(1,1,n,x1,x2-1));
                if (y1+1 <= y2)
                    res = max(res,queryl(1,1,n,y1+1,y2)+queryr(1,1,n,x1,y1));
            }
            printf("%d\n",res);
        }
    }
}
