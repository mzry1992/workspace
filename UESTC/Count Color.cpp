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
    int late;
}buf[N*20];
int l,t,o;
int totn;
char order;
int a,b,c;

void build(int root,int bl,int br)
{
    buf[root].l = bl;
    buf[root].r = br;
    buf[root].color = 1;
    buf[root].late = 0;
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
    if (buf[root].late == 0)    return;
    if (l < r)
    {
        buf[buf[root].ltree].late = buf[root].late;
        buf[buf[root].rtree].late = buf[root].late;
    }
    buf[root].color = 1<<(buf[root].late-1);
    buf[root].late = 0;
}

void cover(int root,int cl,int cr,int color)
{
    int l = buf[root].l;
    int r = buf[root].r;
    if (cl > r) return;
    if (cr < l) return;
    if (buf[root].late != 0)    lazy(root);
    if (cl <= l && r <= cr)
    {
        buf[root].late = color;
        return;
    }
    cover(buf[root].ltree,cl,cr,color);
    cover(buf[root].rtree,cl,cr,color);
    lazy(buf[root].ltree);
    lazy(buf[root].rtree);
    buf[root].color = buf[buf[root].ltree].color|buf[buf[root].rtree].color;
    //cout << l << ' ' << r << ' ' << buf[root].color << ' ' << buf[buf[root].ltree].color << ' ' << buf[buf[root].rtree].color << endl;
}

int doquery(int root,int ql,int qr)
{
    int l = buf[root].l;
    int r = buf[root].r;
    if (ql > r) return 0;
    if (qr < l) return 0;
    if (buf[root].late != 0)    lazy(root);
    if (ql <= l && r <= qr) return buf[root].color;
    int res = 0;
    res = doquery(buf[root].ltree,ql,qr)|doquery(buf[root].rtree,ql,qr);
    //cout << "doquery res = " << res << endl;
    return res;
}

int query(int ql,int qr)
{
    int res = 0;
    int tres = doquery(0,ql,qr);
    for (int i = 0;i < t;i++)
    if ((tres>>i)&1)    res++;
    return res;
}

int main()
{
    while (scanf("%d%d%d",&l,&t,&o) != EOF)
    {
        totn = 0;
        build(0,1,l);
        for (int i = 1;i <= o;i++)
        {
            scanf(" %c%d%d",&order,&a,&b);
            if (a > b)
            {
                int temp = a;
                a = b;
                b = temp;
            }
            if (order == 'C')
            {
                scanf("%d",&c);
                cover(0,a,b,c);
            }
            else
                printf("%d\n",query(a,b));
        }
    }
}
