#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 5000;
int n;
struct node
{
    int l,r;
    int ltree,rtree;
    int sum;
}buf[N*20];
int totn;
int a[N+10];

void build(int root,int bl,int br)
{
    buf[root].l = bl;
    buf[root].r = br;
    buf[root].sum = 0;
    if (bl < br)
    {
        int mid = (bl+br)>>1;
        totn++;
        buf[root].ltree = totn;
        build(totn,bl,mid);
        totn++;
        buf[root].rtree = totn;
        build(totn,mid+1,br);
    }
}

void add(int root,int pos)
{
    int l = buf[root].l;
    int r = buf[root].r;
    if (l <= pos && pos <= r)
    {
        if (l < r)
        {
            add(buf[root].ltree,pos);
            add(buf[root].rtree,pos);
        }
        buf[root].sum++;
    }
}

int query(int root,int ql,int qr)
{
    int l = buf[root].l;
    int r = buf[root].r;
    if (ql > r) return 0;
    if (qr < l) return 0;
    if (ql <= l && r <= qr) return buf[root].sum;
    int res = 0;
    if (l < r)
    {
        res += query(buf[root].ltree,ql,qr);
        res += query(buf[root].rtree,ql,qr);
    }
    return res;
}

int main()
{
    while (scanf("%d",&n) != EOF)
    {
        totn = 0;
        build(0,1,n);
        int sum = 0;
        for (int i = 1;i <= n;i++)
        {
            scanf("%d",&a[i]);
            a[i]++;
            sum += query(0,a[i],n);
            add(0,a[i]);
        }
        int res = sum;
        for (int i = 1;i <= n;i++)
        {
            sum = sum-(a[i]-1)+(n-a[i]);
            if (res > sum)  res = sum;
        }
        printf("%d\n",res);
    }
}
