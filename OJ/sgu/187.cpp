#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 130003;

struct SplayTree
{
    int sz[MAXN],ch[MAXN][2],fa[MAXN],va[MAXN];
    int root;
    bool rev[MAXN];

    inline void pushdown(int x)
    {
        if (!x) return;
        if (rev[x])
        {
            rev[x] ^= 1;
            if (ch[x][0])   rev[ch[x][0]] ^= 1;
            if (ch[x][1])   rev[ch[x][1]] ^= 1;
            swap(ch[x][0],ch[x][1]);
        }
    }

    inline void pushup(int x)
    {
        sz[x] = sz[ch[x][0]]+sz[ch[x][1]]+1;
    }

    inline void Rotate(int x)
    {
        int y = fa[x], z = fa[y], lc = ch[x][0], rc = ch[x][1];
        pushdown(z);
        pushdown(y);
        pushdown(x);
        ch[z][y == ch[z][1]] = x;
        if (x == ch[y][0])
        {
            fa[fa[fa[rc] = y] = x] = z;
            ch[ch[x][1] = y][0] = rc;
        }
        else
        {
            fa[fa[fa[lc] = y] = x] = z;
            ch[ch[x][0] = y][1] = lc;
        }
        pushup(y);
        pushup(x);
    }

    inline void Splay(int x,int goal)
    {
        if (x == goal)  return;
        while (fa[x] != goal)
            Rotate(x);
        if (goal == 0)
            root = x;
    }

    int rank(int k)
    {
        int x = root,cnt = 0;
        while (true)
        {
            pushdown(x);
            if (cnt+sz[ch[x][0]]+1 == k)
            {
                Splay(x,0);
                return x;
            }
            else if (cnt+sz[ch[x][0]]+1 < k)
            {
                cnt += sz[ch[x][0]]+1;
                x = ch[x][1];
            }
            else
                x = ch[x][0];
        }
    }

    void travel(int now)
    {
        pushdown(now);
        if (ch[now][0])
            travel(ch[now][0]);
        printf("%d ",va[now]-1);
        if (ch[now][1])
            travel(ch[now][1]);
    }
};

SplayTree sp;
int n,m;

int main()
{
    scanf("%d%d",&n,&m);
    for (int i = 1;i <= n+2;i++)
    {
        sp.va[i] = i;
        sp.fa[i] = i-1;
        sp.ch[i][0] = sp.ch[i][1] = 0;
        sp.ch[i-1][1] = i;
        sp.sz[i] = n+2-i+1;
    }
    sp.root = 1;
    int l,r;
    for (int i = 0;i < m;i++)
    {
        scanf("%d%d",&l,&r);
        l = sp.rank(l);
        r = sp.rank(r+2);
        sp.Splay(l,0);
        sp.Splay(r,l);
        sp.rev[sp.ch[r][0]] ^= 1;
    }
    l = sp.rank(1);
    r = sp.rank(n+2);
    sp.Splay(l,0);
    sp.Splay(r,l);
    sp.travel(sp.ch[r][0]);
    printf("\n");
    return 0;
}
