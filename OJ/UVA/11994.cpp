#include "iostream"
#include "cstdio"
#include "cstring"
#include "algorithm"
using namespace std;

const int MaxN = 60000;

struct Node
{
    int size,key;

    int msk,lazy;

    Node *c[2];
    Node *p;
} mem[MaxN], *cur, *nil, *pos[MaxN];

Node *newNode(int v,Node *p)
{
    cur->c[0] = cur->c[1] = nil, cur->p = p;
    cur->size = 1;
    cur->key = v;

    cur->msk = 0;
    cur->lazy = -1;

    return cur++;
}

void Init()
{
    cur = mem;
    nil = newNode(0, cur);
    nil->size = 0;
}

struct SplayTree
{
    void Pushup(Node *x)
    {
        if (x == nil)	return;
        Pushdown(x);
        Pushdown(x->c[0]);
        Pushdown(x->c[1]);
        x->size = x->c[0]->size + x->c[1]->size + 1;

        x->msk = x->c[0]->msk | x->c[1]->msk | (1<<x->key);
    }
    void Pushdown(Node *x)
    {
        if (x == nil)	return;

        if (x->lazy != -1)
        {
            x->key = x->lazy;
            x->msk = (1<<x->key);
            x->c[0]->lazy = x->c[1]->lazy = x->lazy;
            x->lazy = -1;
        }
    }
    bool isRoot(Node *x)
    {
        return (x == nil) || (x->p->c[0] != x && x->p->c[1] != x);
    }
    void Rotate(Node *x, int f)
    {
        if (isRoot(x))	return;
        Node *y = x->p;
        y->c[f ^ 1] = x->c[f], x->p = y->p;
        if (x->c[f] != nil)
            x->c[f]->p = y;
        if (y != nil)
        {
            if (y == y->p->c[1])
                y->p->c[1] = x;
            else if (y == y->p->c[0])
                y->p->c[0] = x;
        }
        x->c[f] = y, y->p = x;
        Pushup(y);
    }
    void Splay(Node *x)
    {
        static Node *stack[MaxN];
        int top = 0;
        stack[top++] = x;
        for (Node *y = x; !isRoot(y); y = y->p)
            stack[top++] = y->p;
        while (top)
            Pushdown(stack[--top]);

        while (!isRoot(x))
        {
            Node *y = x->p;
            if (isRoot(y))
                Rotate(x, x == y->c[0]);
            else
            {
                int fd = y->p->c[0] == y;
                if (y->c[fd] == x)
                    Rotate(x, fd ^ 1), Rotate(x, fd);
                else
                    Rotate(y, fd), Rotate(x, fd);
            }
        }
        Pushup(x);
    }
    Node *Access(Node *u)
    {
        Node *v = nil;
        while (u != nil)
        {
            Splay(u);
            v->p = u;
            u->c[1] = v;
            Pushup(u);
            u = (v = u)->p;
            if (u == nil)	return v;
        }
    }
    Node *Root(Node *u)
    {
        Access(u);
        Splay(u);
        for (Pushdown(u); u->c[0] != nil; u = u->c[0])
            Pushdown(u);
        Splay(u);
        return u;
    }
    Node *LCA(Node *u, Node *v)
    {
        if (Root(u) != Root(v))
            return nil;
        Access(u);
        return Access(v);
    }
    void Cut(Node *u)
    {
        Access(u);
        Splay(u);
        u->c[0] = u->c[0]->p = nil;
        Pushup(u);
    }
    void Link(Node *u, Node *v, int val)
    {
        Access(u);
        Splay(u);
        u->p = v;
        u->key = val;
        Pushup(u);
    }
};

int cntbit(int msk)
{
    int res = 0;
    for (; msk; msk >>= 1)
        if (msk&1)
            res++;
    return res;
}

SplayTree sp;
int n,Q,f[MaxN];

int main(int argc, char const *argv[])
{
    while (scanf("%d%d",&n,&Q) != EOF)
    {
        Init();
        for (int i = 0; i < n; i++)
        {
            scanf("%d",&f[i]);
            pos[i] = newNode(0, nil);
        }
        for (int i = 0; i < n; i++)
        {
            int col;
            scanf("%d",&col);
            if (f[i] > 0)
                sp.Link(pos[i],pos[f[i]-1],col-1);
        }
        for (int q = 0; q < Q; q++)
        {
            int typ,x,y,c;
            scanf("%d%d%d",&typ,&x,&y);
            x--,y--;
            if (typ == 3)
            {
                Node *lca = sp.LCA(pos[x],pos[y]);
                if (lca == nil || x == y)
                {
                    printf("0 0\n");
                    continue;
                }
                int totedge = lca->c[1]->size;
                int msk = lca->c[1]->msk;

                if (pos[x] != lca)
                {
                    sp.Splay(pos[x]);
                    totedge += pos[x]->size;
                    msk |= pos[x]->msk;
                }

                printf("%d %d\n",totedge,cntbit(msk));
            }
            else
            {
                scanf("%d",&c);
                c--;
                if (typ == 1)
                {
                    if (x == y)	continue;

                    Node *lca = sp.LCA(pos[x],pos[y]);
                    if (pos[x] == lca)	continue;

                    sp.Cut(pos[x]);
                    sp.Link(pos[x],pos[y],c);

                }
                else
                {
                    Node *lca = sp.LCA(pos[x],pos[y]);

                    if (lca == nil || x == y)
                        continue;

                    lca->c[1]->lazy = c;
                    sp.Pushup(lca->c[1]);
                    sp.Pushup(lca);
                    if (pos[x] != lca)
                    {
                        sp.Splay(pos[x]);
                        pos[x]->lazy = c;
                        sp.Pushup(pos[x]);
                    }
                }
            }
        }
    }
    return 0;
}
