#include "iostream"
#include "cstring"
#include "cstdio"
#include "algorithm"
using namespace std;

const int MaxN = 50003;

struct Node
{
    int size, key;

    Node *c[2];
    Node *p;
} mem[MaxN * 4], *cur, *nil;
int emp[MaxN * 4], totemp;

Node *newNode(int v, Node *p)
{
    cur = mem + emp[--totemp];
    cur->c[0] = cur->c[1] = nil, cur->p = p;
    cur->key = v;
    cur->size = 1;
    return cur;
}

void Init()
{
    for (int i = 0; i < MaxN * 4; i++)
        emp[i] = i;
    totemp = MaxN * 4;
    cur = mem + emp[--totemp];
    nil = newNode(0, cur);
    nil->size = 0;
}

void Recycle(Node *p)
{
    if (p == nil)   return;
    Recycle(p->c[0]), Recycle(p->c[1]);
    emp[totemp++] = p - mem;
}

struct SplayTree
{
    Node *root;
    void Init()
    {
        root = nil;
    }
    void Pushup(Node *x)
    {
        if (x == nil)   return;
        Pushdown(x); Pushdown(x->c[0]); Pushdown(x->c[1]);
        x->size = x->c[0]->size + x->c[1]->size + 1;
    }
    void Pushdown(Node *x)
    {
        if (x == nil)   return;
        //do something
    }
    void Rotate(Node *x, int f)
    {
        if (x == nil)   return;
        Node *y = x->p;
        y->c[f ^ 1] = x->c[f], x->p = y->p;
        if (x->c[f] != nil)
            x->c[f]->p = y;
        if (y->p != nil)
            y->p->c[y->p->c[1] == y] = x;
        x->c[f] = y, y->p = x;
        Pushup(y);
    }
    void Splay(Node *x, Node *f)
    {
        while (x->p != f)
        {
            Node *y = x->p;
            if (y->p == f)
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
        if (f == nil)
            root = x;
    }
    void Insert(int v)
    {
        Node *x = root, *y = nil;
        while (x != nil)
        {
            y = x;
            y->size++;
            x = x->c[v >= x->key];
        }
        y->c[v >= y->key] = x = newNode(v, y);
        Splay(x, nil);
    }
    void Insert(int pos,int v)
    {
        Select(pos,nil),Select(pos+1,root);
        root->c[1]->c[0] = newNode(v,root->c[1]);
        Splay(root->c[1]->c[0],nil);
    }
    void Select(int k, Node *f)
    {
        Node *x = root;
        Pushdown(x);
        int tmp;
        while ((tmp = x->c[0]->size) != k)
        {
            if (k < tmp)    x = x->c[0];
            else
                x = x->c[1], k -= tmp + 1;
            Pushdown(x);
        }
        Splay(x, f);
    }
    void Select(int l, int r)
    {
        Select(l, nil), Select(r + 2, root);
    }
    bool Ancestor(Node *x,Node *f)
    {
        if (x == f) return true;
        while (x->p != nil)
        {
            if (x->p == f)  return true;
            x = x->p;
        }
        return false;
    }
    void Insert(Node *pos, Node *v)
    {
        int pl;
        if (pos == nil)
        {
            Init();
            Insert(0), Insert(0);
            pl = 0;
        }
        else
        {
            Splay(pos, nil);
            pl = root->c[0]->size;
        }
        Select(pl, nil), Select(pl + 1, root);
        root->c[1]->c[0] = v;
        v->p = root->c[1];
        Splay(v, nil);
    }
    void Select(Node *l, Node *r)
    {
		Splay(l, nil);
        int pl = root->c[0]->size - 1;
        Splay(r, nil);
        int pr = root->c[0]->size - 1;
        Select(pl, pr);
    }
    Node *Split(Node *l, Node *r)
    {
        Select(l, r);
        Node *res = root->c[1]->c[0];
        root->c[1]->c[0] = res->p = nil;
        Splay(root->c[1], nil);
        if (root->size == 2)
        {
            Recycle(root);
            Init();
        }
        return res;
    }
};

Node *l[MaxN], *r[MaxN];
SplayTree sp;
int n;
char com[20];

int main(int argc, char const *argv[])
{
    freopen("P.in", "r", stdin);
    bool first = true;
    while (scanf("%d", &n) != EOF)
    {
        if (!first) puts("");
        first = false;
        Init();
        for (int i = 0; i < n; i++)
        {
            sp.Init();
            sp.Insert(0), sp.Insert(0);
            sp.Insert(0,i+1),sp.Insert(1,i+1);
            sp.Select(0, 0), l[i] = sp.root->c[1]->c[0];
            sp.Select(1, 1), r[i] = sp.root->c[1]->c[0];
        }
        for (int i = 0; i < n; i++)
        {
            int f;
            scanf("%d", &f);
            if (f != 0)
            {
                Node *pos = sp.Split(l[i], r[i]);
                sp.Insert(l[f - 1], pos);
            }
        }
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            scanf("%s", com);
            if (com[0] == 'Q')
            {
                int pos;
                scanf("%d", &pos);
                sp.Splay(l[pos - 1], nil);
                sp.Select(1, nil);
                printf("%d\n", sp.root->key);
            }
            else
            {
                int u, v;
                scanf("%d%d", &u, &v);
                if (v == 0)
                    sp.Insert(nil, sp.Split(l[u-1], r[u-1]));
                else
                {
                    sp.Select(l[u-1],r[u-1]);
                    if (sp.Ancestor(l[v-1],sp.root->c[1]->c[0]) == false)
                        sp.Insert(l[v - 1], sp.Split(l[u-1], r[u-1]));
                }
            }
        }
    }
    return 0;
}
