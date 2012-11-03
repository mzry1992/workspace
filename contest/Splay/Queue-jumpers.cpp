#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 300000;

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
        //pushdown(z->y->x);
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
        if (x == goal)	return;
        while (fa[x] != goal)
            Rotate(x);
        if (goal == 0)
            root = x;
    }

    int newnode(int val)
    {
        sz[++L] = 1;
        ch[L][0] = ch[L][1] = fa[L] = 0;
        va[L] = val;
        return L;
    }

    int rank(int k,int _root)//×¢ÒâkµÄ·¶Î§
    {
        int x = _root,cnt = 0;
        while (true)
        {
            //pushdown(x);
            if (cnt+sz[ch[x][0]]+1 == k)
            {
                Splay(x,fa[_root]);
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

};

SplayTree sp;
int n,m;

int main()
{
    int totcas;
    scanf("%d",&totcas);
    for (int cas = 1;cas <= totcas;cas++)
    {
        scanf("%d%d",&n,&m);
    }
    return 0;
}

