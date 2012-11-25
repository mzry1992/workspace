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

    inline void Pushup(int x)
    {
        sz[x] = sz[ch[x][0]]+sz[ch[x][1]]+1;
    }

	inline void Zig(int x)
	{
		int y = fa[x],z = fa[y];
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
		if (x == goal)	return;
		while (fa[x] != goal)
		{
			if (fa[fa[x]] == goal)
				Zig(x);
			else if ((x == ch[fa[x]][1]) == (fa[x] == ch[fa[fa[x]]][1]))
				ZigZig(x);
			else
				Zig(x),Zig(x);
		}
		if (goal == 0)
			root = x;
	}

    void init()
    {
        root = L = 0;
        sz[0] = ch[0][0] = ch[0][1] = fa[0] = 0;
        va[0] = 0;
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

    void debug(int now,int deep)
    {
        if (ch[now][0] != 0)
            debug(ch[now][0],deep+1);
        for (int i = 0; i < deep; i++)
            printf("  ");
        printf("%2d: sz = %2d, va = %2d, fa = %2d\n",now,sz[now],va[now],fa[now]);
        if (ch[now][1] != 0)
            debug(ch[now][1],deep+1);
    }

    void output(int now)
    {
        if (ch[now][0] != 0)
            output(ch[now][0]);
        printf("%d\n",va[now]);
        if (ch[now][1] != 0)
            output(ch[now][1]);
    }

};

SplayTree sp;
int n,a,b;

int main()
{
    freopen("data.in","r",stdin);
    freopen("1.out","w",stdout);
    while (scanf("%d",&n) != EOF)
    {
        sp.init();
        for (int i = 0; i < n; i++)
        {
            scanf("%d%d",&a,&b);
            a++;
            int now = sp.newnode(b);
            if (a == 1)
            {
                sp.ch[now][1] = sp.root;
                sp.fa[sp.root] = now;
                sp.root = now;
                sp.Pushup(now);
            }
            else if (a == i+1)
            {
                sp.ch[now][0] = sp.root;
                sp.fa[sp.root] = now;
                sp.root = now;
                sp.Pushup(now);
            }
            else
            {
                sp.rank(a,sp.root);
                sp.rank(a-1,sp.ch[sp.root][0]);
                sp.ch[sp.ch[sp.root][0]][1] = now;
                sp.fa[now] = sp.ch[sp.root][0];
                sp.Pushup(sp.fa[now]);
                sp.Pushup(sp.fa[sp.fa[now]]);
            }
        }
        sp.output(sp.root);
        //printf("\n");
    }
    return 0;
}

