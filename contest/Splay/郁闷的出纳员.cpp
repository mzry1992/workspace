#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 100001;

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
        int y = fa[x],z = fa[y],lc = ch[x][0],rc = ch[x][1];
        //pushdown(zyx);
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

    int Search(int val)//找比val小的最大数。注意va[0]要为inf
    {
        int res = 0, x = root;
        while (x != 0)
        {
            if (val > va[x])
                x = ch[x][1];
            else
            {
                if (va[x] <= va[res]) res = x;
                x = ch[x][0];
            }
        }
        return res;
    }

    int Select(int k)//找第k小。1~N
    {
        int x = root;
        while (sz[ch[x][0]] + 1 != k)
        {
            if (sz[ch[x][0]] + 1 < k)
                k -= sz[ch[x][0]] + 1, x = ch[x][1];
            else
                x = ch[x][0];
        }
        Splay(x,0);
        return x;
    }

};

SplayTree sp;
int n,d,ans,v,base;
char com;

int main()
{
    while (scanf("%d%d",&n,&base) != EOF)
    {
        sp.init();
        d = ans = 0;
        sp.insert(0x7fffffff);
        sp.va[0] = 0x7fffffff;
        for (int i = 0; i < n; i++)
        {
            scanf(" %c%d",&com,&v);
            if (com == 'I')
            {
                if (v >= base)
                {
                    v -= base-d;
                    sp.insert(v);
                }
            }
            else if (com == 'A')
                d -= v;
            else if (com == 'S')
            {
                d += v;
                sp.Splay(sp.Search(d),0);
                ans += sp.sz[sp.ch[sp.root][0]];
                sp.sz[sp.root] -= sp.sz[sp.ch[sp.root][0]];
                sp.ch[sp.root][0] = 0;
            }
            else
            {
                if (v >= sp.sz[sp.root])
                    printf("-1\n");
                else
                    printf("%d\n",sp.va[sp.Select(sp.sz[sp.root]-v)]+base-d);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
