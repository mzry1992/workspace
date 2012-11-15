#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 200000;
int h,w,n;
struct node
{
    int l,r;
    int ltree,rtree;
    int max;
}buf[N*20];
int totn;

void build(int root,int bl,int br)
{
    buf[root].l = bl;
    buf[root].r = br;
    buf[root].max = w;
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

int query(int root,int num)
{
    int l = buf[root].l;
    int r = buf[root].r;
    if (l < r)
    {
        if (buf[buf[root].ltree].max >= num)    return query(buf[root].ltree,num);
        if (buf[buf[root].rtree].max >= num)    return query(buf[root].rtree,num);
        return -1;
    }
    if (buf[root].max >= num)   return l;
    return -1;
}

void add(int root,int pos,int num)
{
    int l = buf[root].l;
    int r = buf[root].r;
    if (l <= pos && pos <= r)
    {
        if (l < r)
        {
            add(buf[root].ltree,pos,num);
            add(buf[root].rtree,pos,num);
            buf[root].max = max(buf[buf[root].ltree].max,buf[buf[root].rtree].max);
        }
        else
            buf[root].max -= num;
    }
}

int main()
{
    while (scanf("%d%d%d",&h,&w,&n) != EOF)
    {
        totn = 0;
        build(0,1,min(h,n));
        for (int i = 1;i <= n;i++)
        {
            int wi;
            scanf("%d",&wi);
            int pos = query(0,wi);
            printf("%d\n",pos);
            add(0,pos,wi);
        }
    }
}
