#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 110000;

struct SplayTree
{
    int sz[MAXN],ch[MAXN][2],fa[MAXN],va[MAXN];
    int root,L;
    bool rev[MAXN];

    inline void Pushdown(int x)//下传懒标记（例题是区间翻转）
    {
        if (!x)	return;
        if (rev[x])
        {
            rev[x] ^= 1;
            if (ch[x][0])	rev[ch[x][0]] ^= 1;
            if (ch[x][1])	rev[ch[x][1]] ^= 1;
            swap(ch[x][0],ch[x][1]);
        }
    }

    inline void Pushup(int x)//更新节点信息
    {
        sz[x] = sz[ch[x][0]]+sz[ch[x][1]]+1;
    }

    inline void Zig(int x)
    {
        int y = fa[x],z = fa[y];
        Pushdown(z);
        Pushdown(y);
        Pushdown(x);
        ch[z][y == ch[z][1]] = x;
        bool F = x==ch[y][1];
        int b = ch[x][!F];
        fa[fa[fa[b] = y] = x] = z;
        ch[ch[x][!F] = y][F] = b;
        Pushup(y);
        Pushup(x);
    }

    inline void ZigZig(int x)
    {
        int y = fa[x],z = fa[y],zz = fa[z];
        ch[zz][z == ch[zz][1]] = x;
        bool F = x==ch[y][1];
        int b = ch[x][!F],c = ch[y][!F];
        fa[fa[fa[fa[c] = z] = y] = x] = zz;
        ch[ch[ch[x][!F] = y][!F] = z][F] = c;
        fa[b] = y;
        ch[y][F] = b;
        Pushup(z);
        Pushup(y);
        Pushup(x);
    }

    inline void Splay(int x,int goal)
    {
        if (x == goal)  return;
        while (fa[x] != goal)
            if (fa[fa[x]] == goal)
                Zig(x);
            else
            {
                Pushdown(fa[fa[fa[x]]]);
                Pushdown(fa[fa[x]]);
                Pushdown(fa[x]);
                Pushdown(x);
                if ((x == ch[fa[x]][1]) == (fa[x] == ch[fa[fa[x]]][1]))
                    ZigZig(x);
                else
                    Zig(x),Zig(x);
            }
        if (goal == 0)
            root = x;
    }

    int Select(int k,int _root)//求中序遍历k大节点
    {
        int x = _root;
        Pushdown(x);
        while (sz[ch[x][0]]+1 != k)
        {
            if (sz[ch[x][0]]+1 < k)
                k -= sz[ch[x][0]]+1,x = ch[x][1];
            else
                x = ch[x][0];
            Pushdown(x);
        }
        Splay(x,fa[_root]);
        return x;
    }

    void debug(int now,int deep)
    {
        if (ch[now][0])	debug(ch[now][0],deep+1);
        for (int i = 0; i < deep; i++)
            printf("  ");
        printf("id = %d, fa = %d, sz = %d, va = %d, rev = %d, ch = (%d, %d)\n",now,fa[now],sz[now],va[now],rev[now],ch[now][0],ch[now][1]);
        if (ch[now][1]) debug(ch[now][1],deep+1);
    }

    void init()
    {
        L = 0;
        fa[0] = va[0] = ch[0][0] = ch[0][1] = sz[0] = 0;
        rev[0] = 0;
        //各种memset
    }

    int build(pair<int,int> a[],int l,int r,int father)//由数组建立splay
    {
        for (int i = l; i <= r; i++)
        {
            int now = a[i].second;
            fa[now] = now-1;
            ch[now][0] = 0;
            ch[now][1] = now+1;
            sz[now] = r-i;
            va[now] = a[now].first;
            rev[now] = 0;
        }
        ch[r][1] = 0;
        return l;
    }

    int Get(int l,int r)
    {
        l = sp.Select(l,sp.root);
        r = sp.Select(r+2,sp.root);

        sp.Splay(l,0);
        sp.Splay(r,l);

        return sp.ch[r][0];
    }
};

SplayTree sp;
pair<int,int> a[MAXN];
int n;

int main(int argc, char const *argv[])
{
    while (true)
    {
        scanf("%d",&n);
        if (n == 0)	break;
        for (int i = 2; i <= n+1; i++)
        {
            scanf("%d",&a[i].first);
            a[i].second = i;
        }
        a[1].second = 1;
        a[n+2].second = n+2;

        sp.init();
        sp.root = sp.build(a,1,n+2,0);

        sort(a+2,a+n+2);
        int l,r;
        for (int i = 0; i < n; i++)
        {
            l = i+1;
            sp.Splay(a[i+2].second,0);
            r = sp.sz[sp.ch[sp.root][0]];

            printf("%d",r);
            if (i < n-1)	printf(" ");

            l = sp.Select(l,sp.root);
            r = sp.Select(r+2,sp.root);

            sp.Splay(l,0);
            sp.Splay(r,l);

            sp.rev[sp.ch[r][0]] ^= 1;
        }
        printf("\n");
    }
    return 0;
}
