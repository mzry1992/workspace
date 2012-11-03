#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int MAXN = 100000;
const int MAXM = 100000;
const int inf = 0x7fffffff;
int a[MAXN];
struct Treap
{
    int N;
    Treap()
    {
        N = 0;
        root = NULL;
    }
    void init()
    {
        N = 0;
        root = NULL;
    }
    struct Treap_Node
    {
        Treap_Node *son[2];//left & right
        int value, fix;
        bool lazy;
        int size;
        Treap_Node() {}
        Treap_Node(int _value)
        {
            son[0] = son[1] = NULL;
            value = _value;
            fix = rand() * rand();
            lazy = 0;
            size = 1;
        }
        int sonSize(bool flag)
        {
            if (son[flag] == NULL)
                return 0;
            else
                return son[flag]->size;
        }
    } node[MAXN], *root, *pos[MAXN];
    void up(Treap_Node *p)
    {
        p->size = p->sonSize(0) + p->sonSize(1) + 1;
    }
    void down(Treap_Node *p)
    {
        if (!p->lazy)
            return ;
        for (int i = 0; i < 2; i++)
            if (p->son[i])
                p->son[i]->lazy = !p->son[i]->lazy;
        swap(p->son[0], p->son[1]);
        p->lazy = 0;
    }
    Treap_Node *merge(Treap_Node *p, Treap_Node *q)
    {
        if (p == NULL)
            return q;
        else if (q == NULL)
            return p;
        if (p->fix <= q->fix)
        {
            down(p);
            p->son[1] = merge(p->son[1], q);
            up(p);
            return p;
        }
        else
        {
            down(q);
            q->son[0] = merge(p, q->son[0]);
            up(q);
            return q;
        }
    }
    pair<Treap_Node *, Treap_Node *> split(Treap_Node *p, int n)
    {
        if (p == NULL)
            return make_pair((Treap_Node *)NULL, (Treap_Node *)NULL);
        if (!n)
            return make_pair((Treap_Node *)NULL, p);
        if (n == p->size)
            return make_pair(p, (Treap_Node *)NULL);
        down(p);
        if (p->sonSize(0) >= n)
        {
            pair<Treap_Node *, Treap_Node *> ret = split(p->son[0], n);
            p->son[0] = ret.second;
            up(p);
            return make_pair(ret.first, p);
        }
        else
        {
            pair<Treap_Node *, Treap_Node *> ret = split(p->son[1], n - p->sonSize(0) - 1);
            p->son[1] = ret.first;
            up(p);
            return make_pair(p, ret.second);
        }
    }
    int smalls(Treap_Node *p,int value)
    {
        if (p==NULL)
            return 0;
        if (p->value<=value)
            return 1+p->sonSize(0)+smalls(p->son[1],value);
        else
            return smalls(p->son[0],value);
    }
    void insert(int value)
    {
        Treap_Node *p = &node[N++];
        *p = Treap_Node(value);
        pair<Treap_Node *, Treap_Node *> ret = split(root, smalls(root, value));
        root = merge(merge(ret.first, p), ret.second);
    }
    void remove(int value)
    {
        pair<Treap_Node *, Treap_Node *> ret = split(root, smalls(root, value) - 1);
        root = merge(ret.first, split(ret.second, 1).second);
    }
    Treap_Node *build(int s, int t)
    {
        int idx = t + s >> 1;
        Treap_Node *p = &node[N++];
        *p = Treap_Node(a[idx]);
        pos[a[idx]] = p;
        if (idx > s)
            p = merge(build(s, idx - 1), p);
        if (idx < t)
            p = merge(p, build(idx + 1, t));
        up(p);
        return p;
    }
    void build(int n)
    {
        root = build(0, n - 1);
    }
    void *reverse(int s, int t)
    {
        pair<Treap_Node *, Treap_Node *> tmp1, tmp2;
        tmp1 = split(root, s - 1);
        tmp2 = split(tmp1.second, t - s + 1);
        tmp2.first->lazy = !tmp2.first->lazy;
        root = merge(tmp1.first, merge(tmp2.first, tmp2.second));
    }
};
Treap treap;
int main()
{
    treap.init();
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    treap.build(n);
}
