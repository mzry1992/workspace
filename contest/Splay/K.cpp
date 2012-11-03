#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 100100;

/*
 * 喜闻乐见的Splay
 * 函数都是从各个题目里面东拼西凑拿过来的
 * 暂未测试正确性
 */

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

    inline void Zig(int x)
    {
        int y = fa[x],z = fa[y];
        Pushdown(z);
        Pushdown(y);
        Pushdown(x);
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
        Pushdown(zz);
        Pushdown(z);
        Pushdown(y);
        Pushdown(x);
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

    /*
     * 把_root这颗子树的第k大节点转到_root这里
     * 注意k的范围不要超了
     */
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

    /*
     * 返回k在_root中的排名
     */
    int Rank(int k,int _root)
    {
        Splay(k,fa[_root]);
        return sz[ch[k][0]]+1;
    }

    /*
     * 删除k这个节点
     * 先把k转到根然后删除根节点合并左右子树
     */
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

    /*
     * 由数组建立一个Splay
     * 类似于线段树的建立方式
     */
    int Build(pair<int,int> a[],int l,int r,int father)
    {
        if (l > r)  return 0;
        int mid = l+r>>1;
        int now = a[mid].second;//方便直接读取第i个数
        fa[now] = father;
        ch[now][0] = Build(a,l,mid-1,now);
        ch[now][1] = Build(a,mid+1,r,now);
        Pushup(now);
        //变量
        va[now] = a[now].first;
        return now;
    }
};

SplayTree sp;
int n,res,sta;
const int mod = 1000000;

int main()
{
    freopen("K.in","r",stdin);
    freopen("K2.out","w",stdout);
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
		}
        printf("%d\n",res);
    }
    return 0;
}
