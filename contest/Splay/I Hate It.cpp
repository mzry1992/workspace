#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 200100;

struct SplayTree
{
    int sz[MAXN],ch[MAXN][2],fa[MAXN],va[MAXN];
    int root;
    int mx[MAXN];

    inline void pushup(int x)
    {
        sz[x] = sz[ch[x][0]]+sz[ch[x][1]]+1;
        mx[x] = max(va[x],max(mx[ch[x][0]],mx[ch[x][1]]));
    }

    inline void Rotate(int x)
    {
        int y = fa[x],z = fa[y],lc = ch[x][0],rc = ch[x][1];
        //pushdown(z);pushdown(y);pushdown(x);
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

    int get(int l,int r)
    {
        if (l > r)  swap(l,r);
        r = r+2;
        Splay(l,0);
        Splay(r,l);
        return mx[ch[r][0]];
    }

    void set(int a,int b)
    {
        a = a+1;
        Splay(a,0);
        va[a] = b;
        pushup(a);
    }

    void travel(int now)
    {
        //pushdown(now);
        if (ch[now][0])
            travel(ch[now][0]);
        printf("%d ",va[now]);
        //printf("%d ",va[now]-1);
        if (ch[now][1])
            travel(ch[now][1]);
    }

};

int n,m,a[MAXN];
SplayTree sp;

int main()
{
	while (scanf("%d%d",&n,&m) != EOF)
	{
		for (int i = 2;i <= n+1;i++)
			scanf("%d",&a[i]);
		a[1] = a[n+2] = -0x7fffffff;
		for (int i = 1;i <= n+2;i++)
		{
			sp.va[i] = a[i];
			sp.fa[i] = i-1;
			sp.ch[i][0] = sp.ch[i][1] = 0;
			sp.ch[i-1][1] = i;
			sp.sz[i] = n+2-i+1;
		}
		for (int i = n+2;i >= 1;i--)
			sp.pushup(i);
		sp.root = 1;
		int l,r;
		char com;
		for (int i = 0;i < m;i++)
		{
			scanf(" %c%d%d",&com,&l,&r);
			if (com == 'Q')
				printf("%d\n",sp.get(l,r));
			else
				sp.set(l,r);
		}
	}
	return 0;
}
