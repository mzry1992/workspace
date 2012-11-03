#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 100000;
struct node
{
    int l,r;
    int ltree,rtree;
    int color;
}buf[N*20];
int totn;

void build(int root,int l,int r)
{
    int mid;
    mid = (l+r)>>1;
    buf[root].l = l;
    buf[root].r = r;
    buf[root].color = 1;
    if (l < r)
    {
        totn++;
        buf[root].ltree = totn;
        build(totn,l,mid);
        totn++;
        buf[root].rtree = totn;
        build(totn,mid+1,r);
    }
}

void modify(int root,int pl,int pr,int num)
{
    int l = buf[root].l;
    int r = buf[root].r;
    if (r < pl)    return;
    if (l > pr)    return;
    if (pl <= l && r <= pr)
    {
        buf[root].color = num;
        return;
    }
    else
    {
        if (buf[root].color != 0)
        {
            if (l < r)
            {
                modify(buf[root].ltree,buf[root].l,buf[root].r,buf[root].color);
                modify(buf[root].rtree,buf[root].l,buf[root].r,buf[root].color);
            }
        }
        buf[root].color = 0;
    }
    if (l < r)
    {
        modify(buf[root].ltree,pl,pr,num);
        modify(buf[root].rtree,pl,pr,num);
    }
}

int max(int a,int b)
{
    if (a > b)  return a;
    return b;
}

int min(int a,int b)
{
    if (a > b)  return b;
    return a;
}

int query_sum(int root,int ql,int qr)
{
    int res = 0;
    int l = buf[root].l;
    int r = buf[root].r;
    if (r < ql) return 0;
    if (l > qr) return 0;
    if (buf[root].color != 0)
    {
        int com = min(r,qr)-max(l,ql)+1;
        res += com*buf[root].color;
    }
    else
    {
        if (l < r)
        {
            res += query_sum(buf[root].ltree,ql,qr);
            res += query_sum(buf[root].rtree,ql,qr);
        }
    }
    return res;
}

int n,m;
char order[10];
int a,b,c;

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d%d",&n,&m);
        totn = 0;
        build(0,1,n);
        for (int i = 1;i <= m;i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            modify(0,a,b,c);
        }
        printf("Case %d: The total value of the hook is %d.\n",ft,query_sum(0,1,n));
    }
}
