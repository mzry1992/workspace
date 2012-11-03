#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 100100;

struct SplayTree
{
    int sz[MAXN],ch[MAXN][2],fa[MAXN];
    int va[MAXN];
    int root,L;

    inline void pushup(int x)
    {
        sz[x] = sz[ch[x][0]]+sz[ch[x][1]]+1;
    }

    inline void Rotate(int x)
    {
        int y = fa[x],z = fa[y];
        //pushdown(zyx);
        ch[z][y == ch[z][1]] = x;
        bool F = x==ch[y][0];
        int c = ch[x][F];
        fa[fa[fa[c] = y] = x] = z;
        ch[ch[x][F] = y][!F] = c;
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

    void init()
    {
        root = L = 0;
        sz[0] = ch[0][0] = ch[0][1] = fa[0] = 0;
        va[0] = 0;
    }

    void insert(int v)
    {
        int x = root,y = 0;
        while (x != 0)
        {
            ++sz[y = x];
            x = ch[x][v >= va[x]];
        }
        x = ++L;
        sz[x] = 1,fa[x] = y,ch[x][0] = ch[x][1] = 0;
        va[x] = v;
        ch[y][v >= va[y]] = x;
        Splay(x,0);
    }

    int Pre(int k)
    {
        //pushdown(k);
        int x = ch[k][0];
        while (ch[x][1] != 0)
        {
            //pushdown(x);
            x = ch[x][1];
        }
        return x;
    }

    int Nxt(int k)
    {
        //pushdown(k);
        int x = ch[k][1];
        while (ch[x][0] != 0)
        {
            //pushdown(x);
            x = ch[x][0];
        }
        return x;
    }
};

SplayTree sp;

int main()
{
    freopen("data.in","r",stdin);
    freopen("data1.out","w",stdout);
    int n;
    while (scanf("%d",&n) != EOF)
    {
        sp.init();
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int v = 0;
            scanf("%d",&v);
            sp.insert(v);
            int mm = 0x7fffffff;
            if (i == 0) mm = v;
            else
            {
                if (sp.ch[sp.root][0] > 0)
                    mm = min(mm,v-sp.va[sp.Pre(sp.root)]);
                if (sp.ch[sp.root][1] > 0)
                    mm = min(mm,sp.va[sp.Nxt(sp.root)]-v);
            }
            ans += mm;
        }
        printf("%d\n",ans);
    }
    return 0;
}
