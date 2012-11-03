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

    inline void Pushdown(int x)
    {
    }

    inline void Pushup(int x)
    {
        sz[x] = sz[ch[x][0]]+sz[ch[x][1]]+1;
    }

    inline void Rotate(int x)
    {
        int y = fa[x],z = fa[y]; 
        ch[z][y == ch[z][1]] = x;
        bool F = x==ch[y][0];
        int c = ch[x][F];
        fa[fa[fa[c] = y] = x] = z;
        ch[ch[x][F] = y][!F] = c;
        Pushup(y);
        Pushup(x);
    }

    inline void Splay(int x,int goal)
    {
        if (x == goal)  return;
        while (fa[x] != goal)
            Rotate(x);
        if (goal == 0)
            root = x;
    }

    void Init()
    {
        root = L = 0;
        sz[0] = ch[0][0] = ch[0][1] = fa[0] = 0;
        va[0] = 0;
    }

    int Insert(int v)
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
        return x;
    }

    int Pre(int k)
    {
        Splay(k,0);
        int x = ch[k][0];
        while (x && ch[x][1] != 0)
            x = ch[x][1];
        return x;
    }

    int Nxt(int k)
    {
        Splay(k,0);
        int x = ch[k][1];
        while (x && ch[x][0] != 0)
            x = ch[x][0];
        return x;
    }

    int Select(int k,int _root)
    {
        int x = _root;
        while (sz[ch[x][0]]+1 != k)
        {
            if (sz[ch[x][0]]+1 < k)
                k -= sz[ch[x][0]]+1,x = ch[x][1];
            else
                x = ch[x][0];
        }
        Splay(x,fa[_root]);
        return x;
    }

    int Rank(int k,int _root)
    {
        Splay(k,fa[_root]);
        return sz[ch[k][0]]+1;
    }

    void Delete(int k)
    {
        Splay(k,0);
        Pushdown(k);
        if (ch[k][0] == 0)
        {
            fa[ch[k][1]] = 0;
            root = ch[k][1];
        }
        else
        {
            Select(sz[ch[k][0]],ch[k][0]);
            fa[ch[k][1]] = ch[k][0];
            ch[ch[k][0]][1] = ch[k][1];
            fa[ch[k][0]] = 0;
            root = ch[k][0];
            Pushup(root);
        }
    }

    int maxdeep(int now,int deep)
    {
        int res = deep;
        if (ch[now][0]) res = maxdeep(ch[now][0],deep+1);
        if (ch[now][1]) res = max(res,maxdeep(ch[now][1],deep+1));
        return res;
    }
};

SplayTree sp;
int n,res,sta;
const int mod = 1000000;

int main()
{
    freopen("K.in","r",stdin);
    //freopen("K2.out","w",stdout);
    while (scanf("%d",&n) != EOF)
    {
        res = 0;
        sp.Init();
        for (int i = 0; i < n; ++i)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            if (sp.root == 0)
                sta = a;
            if (sta == a)
                sp.Insert(b);
            else
            {
                int now = sp.Insert(b);
                int pre = sp.Pre(now);
                int nxt = sp.Nxt(now);
                int pos;
                if (pre != 0 && nxt != 0)
                {
                    if (b-sp.va[pre] <= sp.va[nxt]-b)
                        pos = pre;
                    else
                        pos = nxt;
                }
                else if (pre != 0)
                    pos = pre;
                else
                    pos = nxt;
                res = (res+abs(b-sp.va[pos]))%mod;
                sp.Delete(now);
                sp.Delete(pos);
            }
            if (sp.root == 0)
                sp.Init();
            //printf("%d %d\n",i,sp.maxdeep(sp.root,0));
        }
        printf("%d\n",res);
    }
    return 0;
}
