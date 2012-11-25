#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 2100000;

struct SplayTree
{
    int sz[MAXN],ch[MAXN][2],fa[MAXN];
    int va[MAXN];
    long long sum[MAXN];
    int root,L;

    inline void Pushup(int x)
    {
        sz[x] = sz[ch[x][0]]+sz[ch[x][1]]+1;
        sum[x] = sum[ch[x][0]]+sum[ch[x][1]]+va[x];
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
        if (x == goal)  return;
        while (fa[x] != goal)
            if (fa[fa[x]] == goal)
                Zig(x);
            else if ((x == ch[fa[x]][1]) == (fa[x] == ch[fa[fa[x]]][1]))
                ZigZig(x);
            else
                Zig(x),Zig(x);
        if (goal == 0)
            root = x;
    }

    void init()
    {
        root = L = 0;
        sz[0] = ch[0][0] = ch[0][1] = fa[0] = 0;
        va[0] = sum[0] = 0;
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

    int Select(int k)
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
char com[10];
int Q,b[2100000];

int main()
{
    //freopen("G.in","r",stdin);
    //freopen("G1.out","w",stdout);
    int cas = 1;
    while (true)
    {
        scanf("%d",&Q);
        if (Q == 0) break;
        sp.init();
        sp.insert(0x7fffffff);
        sp.insert(0x7fffffff);
        printf("Scenario %d:\n",cas++);
        for (int fQ = 0;fQ < Q;fQ++)
        {
            scanf("%s",com);
            if (com[0] == 's')
            {
                int l,r;
                scanf("%d%d",&l,&r);
                l = sp.Select(l+1);
                r = sp.Select(r+3);
                sp.Splay(l,0);
                sp.Splay(r,l);
                printf("%lld\n",sp.sum[sp.ch[r][0]]);
            }
            else if (com[0] == 'i')
            {
                int pos,n,r,m,a,c;
                scanf("%d%d%d%d%d%d",&pos,&n,&r,&m,&a,&c);
                for (int i = 0;i < r;i++)
                    scanf("%d",&b[i]);
                for (int i = r;i < n;i++)
                {
                    b[i] = ((long long)b[i-r]*a+c) % m;
                    c = (((long long)b[i-r]*a+c) / m) % m;
                }
                int tl,tr;
                tl = sp.Select(pos+1);
                tr = sp.Select(pos+2);
                sp.Splay(tl,0);
                sp.Splay(tr,tl);
                for (int i = n-1;i >= 0;i--)
                {
                    int now = ++sp.L;
                    sp.va[now] = b[i];
                    sp.ch[now][0] = sp.ch[now][1] = 0;
                    if (i < n-1)
                    {
                        sp.ch[now][1] = now-1;
                        sp.fa[now-1] = now;
                    }
                    sp.Pushup(now);
                }
                sp.ch[tr][0] = sp.L;
                sp.fa[sp.L] = tr;
                sp.Pushup(tr);
                sp.Pushup(sp.root);
            }
            else
            {
                int l,r;
                scanf("%d%d",&l,&r);
                l = sp.Select(l+1);
                r = sp.Select(r+3);
                sp.Splay(l,0);
                sp.Splay(r,l);
                sp.ch[r][0] = 0;
                sp.Pushup(r);
                sp.Pushup(sp.root);
            }
        }
        puts("");
    }
	return 0;
}
