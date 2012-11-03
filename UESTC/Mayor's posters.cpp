#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 10000;
int n;
int tN;
struct node
{
    int color;
    int lazy;
}buf[N*20];
int totn;
int color;
bool Count[N+10];
struct opera
{
    int l,r;
}o[N+10];
int ls[2*N+10];
int ys[N+10],ttot;

void build(int root,int bl,int br)
{
    buf[root].color = -1;
    buf[root].lazy = 0;
    if (bl < br)
    {
        int mid = (bl+br)>>1;
        build(root*2,bl,mid);
        build(root*2+1,mid+1,br);
    }
}

void lazy(int root,int l,int r)
{
    buf[root].color = buf[root].lazy;
    if (l < r)
        buf[root*2].lazy = buf[root*2+1].lazy = buf[root].lazy;
    buf[root].lazy = 0;
}

void cover(int root,int l,int r,int cl,int cr,int color)
{
    if (cl > r) return;
    if (cr < l) return;
    if (buf[root].lazy != 0)    lazy(root,l,r);
    if (cl <= l && r <= cr)
    {
        buf[root].lazy = color;
        return;
    }
    int mid = (l+r)>>1;
    cover(root*2,l,mid,cl,cr,color);
    cover(root*2+1,mid+1,r,cl,cr,color);
    if (buf[root*2].color == buf[root*2+1].color)
        buf[root].color = buf[root*2+1].color;
    else
        buf[root].color = -1;
}

void doquery(int root,int l,int r)
{
    if (buf[root].lazy != 0)    lazy(root,l,r);
    if (buf[root].color != -1)
    {
        Count[buf[root].color] = true;
        return;
    }
    if (l < r)
    {
        int mid = (l+r)>>1;
        doquery(root*2,l,mid);
        doquery(root*2+1,mid+1,r);
    }
}

int query()
{
    memset(Count,false,sizeof(Count));
    doquery(1,1,tN);
    int res = 0;
    for (int i = 1;i <= color;i++)
    if (Count[i] == true)   res++;
    return res;
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d",&n);
        for (int i = 1;i <= n;i++)
        {
            scanf("%d%d",&o[i].l,&o[i].r);
            ls[i*2-1] = o[i].l;
            ls[i*2] = o[i].r;
        }
        sort(ls+1,ls+n*2+1);
        ls[0] = ls[1]-1;
        ttot = 0;
        for (int i = 1;i <= 2*n;i++)
        if (ls[i] != ls[i-1])
        {
            ttot++;
            ys[ttot] = ls[i];
        }
        for (int i = 1;i <= n;i++)
        {
            int *pos = lower_bound(ys+1,ys+ttot+1,o[i].l);
            o[i].l = (int)(pos-ys);
            pos = lower_bound(ys+1,ys+ttot+1,o[i].r);
            o[i].r = (int)(pos-ys);
        }
        totn = 0;
        tN = ttot;
        build(1,1,tN);
        color = 0;
        for (int i = 1;i <= n;i++)
        {
            int a,b;
            a = o[i].l;
            b = o[i].r;
            color++;
            cover(1,1,tN,a,b,color);
        }
        printf("%d\n",query());
    }
}
