#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 60000;

///Splay Tree
int sz[MAXN],ch[MAXN][2],fa[MAXN];
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

void init(int n)
{
    for (int i = 1; i <= n+2; i++)
    {
        fa[i] = i-1;
        ch[i][0] = ch[i][1] = 0;
        ch[i-1][1] = i;
        sz[i] = n+2-i+1;
        ///Notice : i = 1 and i = n+2

    }
    for (int i = n+2; i >= 1; i--)
        pushup(i);
    root = 1;
}

int get(int l,int r)
{
    if (l > r)  swap(l,r);
    r = r+2;
    Splay(l,0);
    Splay(r,l);
    return ch[r][0];
}
///End

int n,m;

int main()
{
    while (scanf("%d%d",&n,&m) != EOF)
    {
        init(n);
    }
    return 0;
}
