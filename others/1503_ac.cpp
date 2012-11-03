#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
#define Max 100005
#define inf 1000000000

struct node
{
    int money;
    int ss;      //  记录连上自己一共覆盖的点数
    bool operator < ( node tt)
    {
        return this->money < tt.money;
    }
};
struct Splay
{
    node key;
    int fa,l,r;
} sp[Max];
int root, s;
int minn, sum, out;

void zig(int k)
{
    int t = sp[k].fa;
    int mid = sp[t].key.ss;
    sp[t].key.ss = sp[t].key.ss - sp[k].key.ss + sp[sp[k].l].key.ss;
    sp[k].key.ss = mid;
    sp[t].r = sp[k].l;
    if(sp[k].l)
        sp[sp[k].l].fa = t;
    sp[k].fa = sp[t].fa;
    sp[k].l = t;
    if(sp[t].fa)
    {
        if(t == sp[sp[t].fa].l)
            sp[sp[t].fa].l = k;
        else
            sp[sp[t].fa].r = k;
    }
    sp[t].fa = k;
}
void zag(int k)
{
    int t = sp[k].fa;
    int mid = sp[t].key.ss;
    sp[t].key.ss = sp[t].key.ss - sp[k].key.ss + sp[sp[k].r].key.ss;
    sp[k].key.ss = mid;
    sp[t].l = sp[k].r;
    if(sp[k].r)
        sp[sp[k].r].fa = t;
    sp[k].fa = sp[t].fa;
    sp[k].r = t;
    if(sp[t].fa)
    {
        if(t == sp[sp[t].fa].l)
            sp[sp[t].fa].l = k;
        else
            sp[sp[t].fa].r = k;
    }
    sp[t].fa = k;
}
void splay(int k)
{
    int t;
    while(sp[k].fa)
    {
        t = sp[k].fa;
        if(sp[t].fa == 0)
        {
            if(k == sp[t].l)
                zag(k);
            else
                zig(k);
            break;
        }
        if(t == sp[sp[t].fa].l)
        {
            if(k == sp[t].l)
            {
                zag(t);
                zag(k);
            }
            else
            {
                zig(k);
                zag(k);
            }
        }
        else
        {
            if(k == sp[t].l)
            {
                zag(k);
                zig(k);
            }
            else
            {
                zig(t);
                zig(k);
            }
        }
    }
    root = k;
}

void insert(node x)
{
    int i,j;
    s++;
    sp[s].key = x;
    if(root == 0)
    {
        root = s;
        return ;
    }
    i = root;
    while(i)
    {
        j = i;
        if(x < sp[i].key)
            i = sp[i].l;
        else
            i = sp[i].r;
    }
    sp[s].fa = j;
    if(x < sp[j].key)
        sp[j].l = s;
    else
        sp[j].r = s;
    while(j)
    {
        sp[j].key.ss += 1;
        j = sp[j].fa;
    }
    splay(s);
}

void add(int m, int rot)
{
    sp[rot].key.money += m;
    if(sp[rot].l)
        add(m,sp[rot].l);
    if(sp[rot].r)
        add(m,sp[rot].r);
}

int find(int rank, int rot)
{
    if(sp[rot].key.ss == rank)
    {
        while(sp[rot].r)
        {
            rot = sp[rot].r;
        }
        return sp[rot].key.money;
    }
    else if( sp[sp[rot].l].key.ss >= rank)
    {
        find(rank, sp[rot].l);
    }
    else
    {
        if(sp[sp[rot].l].key.ss+1 == rank)
            return sp[rot].key.money;
        else
            find(rank-(sp[sp[rot].l].key.ss+1), sp[rot].r);
    }
}

void Del(int rot)
{
    if(sp[rot].key.money < minn)
    {
        root = sp[rot].r;
        sp[sp[rot].r].fa = 0;
        out += sp[rot].key.ss - sp[sp[rot].r].key.ss;
        if(sp[rot].r)
            Del(root);
    }
    else
    {
        if(sp[rot].l)
        {
            int i = sp[rot].l;
            while(i)
            {
                if(sp[i].key.money < minn)
                    break;
                i = sp[i].l;
            }
            if(i)
            {
                splay(i);
                Del(root);
            }
        }
    }
}

int main()
{
    freopen("1503.in","r",stdin);
    freopen("1503_ac.out","w",stdout);
    int n,a,i,ac;
    char c[3];
    node mid;
    while(scanf("%d%d", &n,&minn) != EOF)
    {
        memset(sp, 0, sizeof(sp));
        sum = out = 0;
        ac = s = root = 0;
        for(i=0; i<n; i++)
        {
            scanf("%s%d", c,&a);
            if(c[0] == 'I')
            {
                if(a >= minn)
                {
                    mid.money = a-ac;    //这里改了就A了
                    mid.ss = 1;
                    insert(mid);
                    sum++;
                }
            }
            else if(c[0] == 'A')
            {
                ac += a;         //这里做了压缩
            }
            else if(c[0] == 'S')
            {
                ac -= a;
                add(ac, root);
                Del(root);
                ac = 0;
            }
            else
            {
                if(sum-out < a)
                    printf("-1\n");
                else
                {
                    printf("%d\n", find(sum-out-a+1,root)+ac);
                }
            }
        }
        printf("%d\n", out);
    }
    return 0;
}
