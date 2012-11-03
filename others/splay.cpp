#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 32768;
struct Splay
{
    int key[maxn],s[maxn],l[maxn],r[maxn],f[maxn],root,L;

    inline void updata(int x)
    {
        s[x] = s[l[x]]+s[r[x]]+1;
    }
    inline void zig(int x)
    {
        int y = f[x];
        l[y] = r[x];
        f[r[x]] = y;
        f[x] = f[y];
        if (f[x] != 0)
        {
            if (l[f[x]] == y)   l[f[x]] = x;
            else    r[f[x]] = x;
        }
        r[x] = y;
        f[y] = x;
        updata(y);
        updata(x);
    }
    inline void zag(int x)
    {
        int y = f[x];
        r[y] = l[x];
        f[l[x]] = y;
        f[x] = f[y];
        if (f[x] != 0)
        {
            if (l[f[x]] == y)   l[f[x]] = x;
            else    r[f[x]] = x;
        }
        l[x] = y;
        f[y] = x;
        updata(y);
        updata(x);
    }
    inline void splay(int x)
    {
        while (f[x] != 0)
        {
            int y = f[x],z = f[f[x]];
            if (z == 0)
            {
                if (x == l[y])  zig(x);
                else    zag(x);
            }
            else if (x == l[y] && y == l[z])
            {
                zig(x);
                zig(x);
            }
            else if (x == r[y] && y == r[z])
            {
                zag(x);
                zag(x);
            }
            else if (x == l[y] && y == r[z])
            {
                zig(x);
                zag(x);
            }
            else if (x == r[y] && y == l[z])
            {
                zag(x);
                zig(x);
            }
        }
        root = x;
    }
    void init()
    {
        root = L = 0;
        memset(s,0,sizeof(s));
        memset(key,0,sizeof(key));
        memset(l,0,sizeof(l));
        memset(r,0,sizeof(r));
        memset(f,0,sizeof(f));
    }
    void insert(int& now,int fa,int x)
    {
        if (now == 0)
        {
            now = ++L;
            s[now] = 1;
            key[now] = x;
            f[now] = fa;
            splay(now);
        }
        else
        {
            s[now]++;
            if (x < key[now])
                insert(l[now],now,x);
            else
                insert(r[now],now,x);
        }
    }

    /////////////////////////////////////////
    void debug(int now,int deep)
    {
        if (now == 0)   return;
        debug(l[now],deep+1);
        for (int i = 0; i < deep; i++)
            printf("  ");
        printf("f = %4d ,l = %4d ,r = %4d ,s = %4d ,key = %4d\n",f[now],l[now],r[now],s[now],key[now]);
        debug(r[now],deep+1);
    }

    /////////////////////////////////////////
    int pred()
    {
        int now = l[root];
        while (r[now] != 0)
            now = r[now];
        return now;
    }
    int succ()
    {
        int now = r[root];
        while (l[now] != 0)
            now = l[now];
        return now;
    }
};

Splay tree;

int main()
{
    tree.init();
    int n;
    scanf("%d",&n);
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        int a;
        scanf("%d",&a);
        tree.insert(tree.root,0,a);

        int pred = tree.pred();
        int succ = tree.succ();
        int minres;
        if (i == 0) minres = a;
        else    minres = 1992100500;
        if (pred != 0)
            minres = min(minres,abs(tree.key[pred]-a));
        if (succ != 0)
            minres = min(minres,abs(tree.key[succ]-a));

        res += minres;
    }
    printf("%d\n",res);
    return 0;
}
