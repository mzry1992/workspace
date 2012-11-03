#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 1100000;

struct SplayTree
{
    int sz[MAXN],ch[MAXN][2],fa[MAXN];
    int va[MAXN],id[MAXN];
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

    void init()
    {
        root = L = 0;
        sz[0] = ch[0][0] = ch[0][1] = fa[0] = 0;
        va[0] = id[0] = 0;
    }

    void insert(int v,int idx)
    {
        int x = root,y = 0;
        while (x != 0)
        {
            ++sz[y = x];
            x = ch[x][v >= va[x]];
        }
        x = ++L;
        sz[x] = 1,fa[x] = y,ch[x][0] = ch[x][1] = 0;
        va[x] = v,id[x] = idx;
        ch[y][v >= va[y]] = x;
        Splay(x,0);
    }

    int rank(int k,int _root)//注意k的范围
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

    void del()//删除root
    {
        if (ch[root][0] == 0)
        {
            fa[ch[root][1]] = 0;
            root = ch[root][1];
        }
        else
        {
            rank(sz[ch[root][0]],ch[root][0]);
            fa[ch[root][1]] = ch[root][0];
            ch[ch[root][0]][1] = ch[root][1];
            fa[ch[root][0]] = 0;
            root = ch[root][0];
            pushup(root);
        }
    }

    void debug(int now,int deep)
    {
        if (ch[now][0] != 0)
            debug(ch[now][0],deep+1);
        for (int i = 0; i < deep; i++)
            printf("  ");
        printf("%2d: sz = %2d, va = %2d, id = %2d\n",now,sz[now],va[now],id[now]);
        if (ch[now][1] != 0)
            debug(ch[now][1],deep+1);
    }


};

SplayTree sp;
int com,a,b;

int main()
{
    sp.init();
    sp.insert(0x7fffffff,-1);//插入一个inf节点防止树被清空
    while (true)
    {
        scanf("%d",&com);
        if (com == 0)	break;
        if (com == 1)
        {
            scanf("%d%d",&a,&b);
            sp.insert(b,a);
        }
        else if (sp.sz[sp.root] == 1)
            puts("0");
        else
        {
            int now;
            if (com == 2)
                now = sp.rank(sp.sz[sp.root]-1,sp.root);
            else
                now = sp.rank(1,sp.root);
            printf("%d\n",sp.id[now]);
            sp.del();
        }
    }
    return 0;
}
