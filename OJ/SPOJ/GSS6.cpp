#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MaxN = 300000;

struct Node
{
    int size, key;
    int lsum, rsum, sum, maxsum;

    Node *c[2];
    Node *p;
} mem[MaxN], *cur, *nil;

int emp[MaxN], totemp;

Node *newNode(int v, Node *p)
{
    cur = mem + emp[--totemp];
    cur->c[0] = cur->c[1] = nil, cur->p = p;
    cur->size = 1;
    cur->key = cur->lsum = cur->rsum = cur->sum = cur->maxsum = v;
    return cur;
}

void Init()
{
    for (int i = 0; i < MaxN; ++i)
        emp[i] = i;
    totemp = MaxN;
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
        x->size = x->c[0]->size + x->c[1]->size + 1;

        x->sum = x->c[0]->sum + x->c[1]->sum + x->key;
        x->lsum = max(x->c[0]->lsum, x->c[0]->sum + x->key + max(0, x->c[1]->lsum));
        x->rsum = max(x->c[1]->rsum, x->c[1]->sum + x->key + max(0, x->c[0]->rsum));
        x->maxsum = x->key + max(0, x->c[0]->rsum) + max(0, x->c[1]->lsum);
        if (x->c[0] != nil)
            x->maxsum = max(x->maxsum, x->c[0]->maxsum);
        if (x->c[1] != nil)
            x->maxsum = max(x->maxsum, x->c[1]->maxsum);
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
    void Select(int k, Node *f)
    {
        Node *x = root;
        int tmp;
        while ((tmp = x->c[0]->size) != k)
        {
            if (k < tmp)    x = x->c[0];
            else
                x = x->c[1], k -= tmp + 1;
        }
        Splay(x, f);
    }
    void Select(int l, int r)
    {
        Select(l, nil), Select(r + 2, root);
    }
    Node *Make_tree(int a[], int l, int r, Node *p)
    {
        if (l > r)  return nil;
        int mid = l + r >> 1;
        Node *x = newNode(a[mid], p);
        x->c[0] = Make_tree(a, l, mid - 1, x);
        x->c[1] = Make_tree(a, mid + 1, r, x);
        Pushup(x);
        return x;
    }
    void Insert(int pos, int a[], int n)
    {
        Select(pos, nil), Select(pos + 1, root);
        root->c[1]->c[0] = Make_tree(a, 0, n - 1, root->c[1]);
        Splay(root->c[1]->c[0], nil);
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
    void Remove(int l, int r)
    {
        Select(l, r);
        Recycle(root->c[1]->c[0]);
        root->c[1]->c[0] = nil;
        Splay(root->c[1], nil);
    }
};

int n, m, a[MaxN];
SplayTree sp;
char com[2];

int main(int argc, char const *argv[])
{
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    while (scanf("%d", &n) != EOF)
    {
        Init();
        sp.Init();
        sp.Insert(0), sp.Insert(0);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        sp.Insert(0, a, n);
        scanf("%d", &m);
        for (int i = 0; i < m; i++)
        {
            int l, r;
            scanf("%s", com);
            if (com[0] == 'I')
            {
                scanf("%d%d", &l, &r);
                a[0] = r;
                sp.Insert(l - 1, a, 1);
            }
            else if (com[0] == 'D')
            {
                scanf("%d", &l);
                sp.Remove(l - 1, l - 1);
            }
            else if (com[0] == 'R')
            {
                scanf("%d%d", &l, &r);
                sp.Select(l - 1, l - 1);
                sp.root->c[1]->c[0]->key = r;
                sp.Pushup(sp.root->c[1]->c[0]);
            }
            else
            {
                scanf("%d%d", &l, &r);
                sp.Select(l - 1, r - 1);
                printf("%d\n", sp.root->c[1]->c[0]->maxsum);
            }
        }
    }
    return 0;
}
