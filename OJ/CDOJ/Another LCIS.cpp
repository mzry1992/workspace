#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 100000;
int n,q;
struct node
{
    int l,r;
    int ltree,rtree;
    int lmax,rmax,max,dis;
    int numl,numr;
    int lazy;
}buf[N*20];
int totn;
char order;
int a,b,c;

void build(int root,int bl,int br)
{
    buf[root].l = bl;
    buf[root].r = br;
    buf[root].lmax = buf[root].rmax = buf[root].max = buf[root].dis = br-bl+1;
    buf[root].lazy = buf[root].numl = buf[root].numr = 0;
    if (bl < br)
    {
        int mid = (bl+br)>>1;
        totn++;
        buf[root].ltree = totn;
        build(buf[root].ltree,bl,mid);
        totn++;
        buf[root].rtree = totn;
        build(buf[root].rtree,mid+1,br);
    }
}

void lazy(int root)
{
    int l = buf[root].l;
    int r = buf[root].r;
    buf[root].numl += buf[root].lazy;
    buf[root].numr += buf[root].lazy;
    if (l < r)
    {
        buf[buf[root].ltree].lazy += buf[root].lazy;
        buf[buf[root].rtree].lazy += buf[root].lazy;
    }
    buf[root].lazy = 0;
}

void maintain(int root)
{
    if (buf[buf[root].ltree].lazy != 0) lazy(buf[root].ltree);
    if (buf[buf[root].rtree].lazy != 0) lazy(buf[root].rtree);
    buf[root].max = max(buf[buf[root].ltree].max,buf[buf[root].rtree].max);
    if (buf[buf[root].ltree].numr < buf[buf[root].rtree].numl)
        buf[root].max = max(buf[root].max,buf[buf[root].ltree].rmax+buf[buf[root].rtree].lmax);
    buf[root].lmax = buf[buf[root].ltree].lmax;
    buf[root].rmax = buf[buf[root].rtree].rmax;
    buf[root].numl = buf[buf[root].ltree].numl;
    buf[root].numr = buf[buf[root].rtree].numr;
    if (buf[buf[root].ltree].max == buf[buf[root].ltree].dis)
        if (buf[buf[root].ltree].numr < buf[buf[root].rtree].numl)
            buf[root].lmax += buf[buf[root].rtree].lmax;
    if (buf[buf[root].rtree].max == buf[buf[root].rtree].dis)
        if (buf[buf[root].ltree].numr < buf[buf[root].rtree].numl)
            buf[root].rmax += buf[buf[root].ltree].rmax;
}

void add(int root,int al,int ar,int num)
{
    int l = buf[root].l;
    int r = buf[root].r;
    if (buf[root].lazy != 0)    lazy(root);
    if (al > r) return;
    if (ar < l) return;

    if (al <= l && r <= ar)
    {
        if (l < r)
            buf[root].lazy = num;
        else
        {
            buf[root].numl += num;
            buf[root].numr += num;
        }
        return;
    }
    if (l < r)
    {
        add(buf[root].ltree,al,ar,num);
        add(buf[root].rtree,al,ar,num);
        maintain(root);
    }
    else
        buf[root].numl = buf[root].numr = num;
}

int query(int root,int ql,int qr)
{
    int l = buf[root].l;
    int r = buf[root].r;
    int mid = (l+r)>>1;
    if (ql > r) return 0;
    if (qr < l) return 0;
    if (buf[root].lazy != 0)    lazy(root);
    if (ql <= l && r <= qr) return buf[root].max;
    if (qr <= mid)  return query(buf[root].ltree,ql,qr);
    if (ql > mid)   return query(buf[root].rtree,ql,qr);
    int res = max(query(buf[root].ltree,ql,mid),query(buf[root].rtree,mid+1,qr));
    if (buf[buf[root].ltree].numr < buf[buf[root].rtree].numl)
        res = max(res,min(mid-ql+1,buf[buf[root].ltree].rmax)+min(qr-mid,buf[buf[root].rtree].lmax));
    return res;
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d%d",&n,&q);
        totn = 0;
        build(0,1,n);
        for (int i = 1;i <= n;i++)
        {
            int temp;
            scanf("%d",&temp);
            add(0,i,i,temp);
        }
        printf("Case #%d:\n",ft);
        for (int ii = 1;ii <= q;ii++)
        {
            scanf(" %c",&order);
            if (order == 'q')
            {
                scanf("%d%d",&a,&b);
                printf("%d\n",query(0,a,b));
            }
            else
            {
                scanf("%d%d%d",&a,&b,&c);
                add(0,a,b,c);
            }
        }
    }
}
