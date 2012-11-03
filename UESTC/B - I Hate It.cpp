#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 200000;
struct node
{
    int l,r;
    int ltree,rtree;
    int max;
}buf[N*20];
int totn;

int max(int a,int b)
{
    if (a > b)  return a;
    return b;
}

void build(int root,int l,int r)
{
    int mid;
    mid = (l+r)>>1;
    buf[root].l = l;
    buf[root].r = r;
    buf[root].max = 0;
    if (l == r) return;
    totn++;
    buf[root].ltree = totn;
    build(totn,l,mid);
    totn++;
    buf[root].rtree = totn;
    build(totn,mid+1,r);
}

void modify(int root,int pos,int num)
{
    int l = buf[root].l;
    int r = buf[root].r;
    if (r < pos)    return;
    if (l > pos)    return;
    buf[root].max = max(buf[root].max,num);
    if (l < r)
    {
        modify(buf[root].ltree,pos,num);
        modify(buf[root].rtree,pos,num);
    }
}

int query_max(int root,int ql,int qr)
{
    int res = 0;
    int l = buf[root].l;
    int r = buf[root].r;
    if (r < ql) return 0;
    if (l > qr) return 0;
    if (l >= ql && r <= qr)
        res = max(res,buf[root].max);
    else
    {
        res = max(res,query_max(buf[root].ltree,ql,qr));
        res = max(res,query_max(buf[root].rtree,ql,qr));
    }
    return res;
}

int n,m;
char order[10];
int a,b;

int main()
{
    while (scanf("%d%d",&n,&m) != EOF)
    {
        totn = 0;
        build(0,1,n);
        for (int i = 1;i <= n;i++)
        {
            int temp;
            scanf("%d",&temp);
            modify(0,i,temp);
        }
        for (int i = 1;i <= m;i++)
        {
            scanf("%s%d%d",order,&a,&b);
            if (strcmp(order,"Q") == 0)
                printf("%d\n",query_max(0,a,b));
            else
                modify(0,a,b);
        }
    }
}
