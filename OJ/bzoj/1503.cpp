#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 100005;
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
    void insert(int x)
    {
        _insert(root,0,x);
    }
    void _insert(int& now,int fa,int x)
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
                _insert(l[now],now,x);
            else
                _insert(r[now],now,x);
        }
    }
    int findk(int k,int sum)
    {
        if (s[root] < k)    return -1;
        return _findk(root,k)+sum;
    }
    int _findk(int now,int k)
    {
        if (k == s[r[now]]+1)   return key[now];
        if (k <= s[r[now]]) return _findk(r[now],k);
        else    return _findk(l[now],k-s[r[now]]-1);
    }
    int findbig(int now,int min)
    {
        if (now == 0)   return 0;
        if (min <= key[now])
        {
            int pos = findbig(l[now],min);
            return (pos == 0)?now:pos;
        }
        else
            return findbig(r[now],min);
    }
    void delet(int min)
    {
        int pos = findbig(root,min);
        if (pos == 0)   root = 0;
        else
        {
            splay(pos);
            l[root] = 0;
            updata(root);
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
};

Splay tree;

int main()
{
    freopen("1503.in","r",stdin);
    freopen("1503.out","w",stdout);
    int n,m,a,sum;
    char s;
    while (scanf("%d%d",&n,&m) != EOF)
    {
        tree.init();
        sum = 0;
        int toti = 0;
        for (int i = 0; i < n; i++)
        {
            scanf(" %c%d",&s,&a);
            if (s == 'I')
            {
                if (a >= m)
                {
                    toti++;
                    tree.insert(a-sum);
                }
            }
            else if (s == 'A')
                sum += a;
            else if (s == 'S')
            {
                sum -= a;
                tree.delet(m-sum);
            }
            else if (s == 'F')
                printf("%d\n",tree.findk(a,sum));
            //printf("size = %d\n",tree.s[tree.root]);
        }
        printf("%d\n",toti-tree.s[tree.root]);
    }
    return 0;
}
