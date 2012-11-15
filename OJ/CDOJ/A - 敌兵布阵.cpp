#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

struct node
{
    int l,r;
    int ltree,rtree;
    int sum;
}buf[1000000];
int totn;
int n;
char order[10];
int a,b;

void build(int root,int l,int r)
{
    int mid;
    mid = (l+r)>>1;
    buf[root].l = l;
    buf[root].r = r;
    buf[root].sum = 0;
    if (l == r) return;
    totn++;
    buf[root].ltree = totn;
    build(totn,l,mid);
    totn++;
    buf[root].rtree = totn;
    build(totn,mid+1,r);
}

void add(int root,int pos,int num)
{
    int l = buf[root].l;
    int r = buf[root].r;
    if (r < pos)    return;
    if (l > pos)    return;
    buf[root].sum += num;
    if (l < r)
    {
        add(buf[root].ltree,pos,num);
        add(buf[root].rtree,pos,num);
    }
}

int query(int root,int ql,int qr)
{
    int res = 0;
    int l = buf[root].l;
    int r = buf[root].r;
    if (r < ql) return 0;
    if (l > qr) return 0;
    if (l >= ql && r <= qr)
        res += buf[root].sum;
    else
    {
        res += query(buf[root].ltree,ql,qr);
        res += query(buf[root].rtree,ql,qr);
    }
    return res;
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        totn = 0;
        scanf("%d",&n);
        build(0,1,n);
        for (int i = 1;i <= n;i++)
        {
            int temp;
            scanf("%d",&temp);
            add(0,i,temp);
        }
        printf("Case %d:\n",ft);
        while (true)
        {
            scanf("%s",order);
            if (strcmp(order,"End") == 0)   break;
            scanf("%d%d",&a,&b);
            if (strcmp(order,"Query") == 0)
                printf("%d\n",query(0,a,b));
            else if (strcmp(order,"Add") == 0)
                add(0,a,b);
            else add(0,a,-b);
        }
    }
}
