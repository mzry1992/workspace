#include <iostream>
#include <cstdio>
#include <cstring>
#include <deque>
using namespace std;

const int N = 50000;
struct node
{
    int l,r;
    int ltree,rtree;
    int lmax,rmax,max,dis;
}buf[N*20];
int totn;
int n,m;
deque<int> S;
char order;
int a;

void build(int root,int bl,int br)
{
    buf[root].l = bl;
    buf[root].r = br;
    buf[root].lmax = buf[root].rmax = buf[root].max = buf[root].dis = br-bl+1;
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

void maintain(int root)
{
    buf[root].max = max(buf[buf[root].ltree].max,max(buf[buf[root].rtree].max,buf[buf[root].ltree].rmax+buf[buf[root].rtree].lmax));
    buf[root].lmax = buf[buf[root].ltree].lmax;
    buf[root].rmax = buf[buf[root].rtree].rmax;
    if (buf[buf[root].ltree].max == buf[buf[root].ltree].dis)
        buf[root].lmax += buf[buf[root].rtree].lmax;
    if (buf[buf[root].rtree].max == buf[buf[root].rtree].dis)
        buf[root].rmax += buf[buf[root].ltree].rmax;
}

void cover(int root,int pos,int num)
{
    int l = buf[root].l;
    int r = buf[root].r;
    if (l <= pos && pos <= r)
    {
        if (l < r)
        {
            cover(buf[root].ltree,pos,num);
            cover(buf[root].rtree,pos,num);
            maintain(root);
        }
        else
            buf[root].max = buf[root].lmax = buf[root].rmax = num;
    }
}

int query(int root,int pos)
{
    int l = buf[root].l;
    int r = buf[root].r;
    int mid = (l+r)>>1;
    if (buf[root].max == 0) return 0;
    if (buf[root].max == buf[root].dis) return buf[root].max;
    if (pos <= mid)
    {
        if (buf[buf[root].ltree].r-buf[buf[root].ltree].rmax+1 <= pos)
            return query(buf[root].ltree,pos)+query(buf[root].rtree,mid+1);
        else
            return query(buf[root].ltree,pos);
    }
    else
    {
        if (buf[buf[root].rtree].l+buf[buf[root].rtree].lmax-1 >= pos)
            return query(buf[root].rtree,pos)+query(buf[root].ltree,mid);
        else
            return query(buf[root].rtree,pos);
    }
}

int main()
{
    while (scanf("%d%d",&n,&m) != EOF)
    {
        totn = 0;
        build(0,1,n);
        S.clear();
        for (int i = 1;i <= m;i++)
        {
            scanf(" %c",&order);
            if (order == 'D')
            {
                scanf("%d",&a);
                S.push_back(a);
                cover(0,a,0);
            }
            else if (order == 'Q')
            {
                scanf("%d",&a);
                printf("%d\n",query(0,a));
            }
            else
            {
                a = S.back();
                S.pop_back();
                cover(0,a,1);
            }
        }
    }
}
