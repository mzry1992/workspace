#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 100000;
int n,q;
struct node
{
    int l,r;
    int ltree,rtree;
    long long sum;
    long long late;
}buf[N*20];
int totn;
int a,b,c;
char order;

void build(int root,int bl,int br)
{
    buf[totn].l = bl;   buf[totn].r = br;
    buf[totn].sum = buf[totn].late = 0;
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

void lazy(int root)
{
    int l = buf[root].l;
    int r = buf[root].r;
    buf[root].sum += buf[root].late*(r-l+1);
    if (l < r)
    {
        buf[buf[root].ltree].late += buf[root].late;
        buf[buf[root].rtree].late += buf[root].late;
    }
    buf[root].late = 0;
}

void add(int root,int ql,int qr,int num)
{
    int l = buf[root].l;
    int r = buf[root].r;
    if (ql > r) return;
    if (qr < l) return;
    if (buf[root].late != 0)    lazy(root);
    if (ql <= l && r <= qr)
    {
        buf[root].late += num;
        return;
    }
    add(buf[root].ltree,ql,qr,num);
    add(buf[root].rtree,ql,qr,num);
    lazy(buf[root].ltree);
    lazy(buf[root].rtree);
    buf[root].sum = buf[buf[root].ltree].sum+buf[buf[root].rtree].sum;
}

long long query(int root,int ql,int qr)
{
    int l = buf[root].l;
    int r = buf[root].r;
    if (ql > r) return 0;
    if (qr < l) return 0;
    if (buf[root].late != 0)    lazy(root);
    if (ql <= l && r <= qr) return buf[root].sum;
    long long res = 0;
    res = query(buf[root].ltree,ql,qr)+query(buf[root].rtree,ql,qr);
    return res;
}

int main()
{
    while (scanf("%d%d",&n,&q) != EOF)
    {
        totn = 0;
        build(0,1,n);
        for (int i = 1;i <= n;i++)
        {
            int temp;
            scanf("%d",&temp);
            add(0,i,i,temp);
        }
        for (int i = 1;i <= q;i++)
        {
            scanf(" %c",&order);
            if (order == 'Q')
            {
                scanf("%d%d",&a,&b);
                printf("%lld\n",query(0,a,b));
            }
            else
            {
                scanf("%d%d%d",&a,&b,&c);
                add(0,a,b,c);
            }
        }
    }
}
