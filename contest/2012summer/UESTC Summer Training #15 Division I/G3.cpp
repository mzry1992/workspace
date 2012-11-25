#include "iostream"
#include "cstring"
#include "cstdio"
#include "algorithm"
using namespace std;

const int MaxN = 2000005;

struct Node
{
    int key, size;
    long long sum;
    Node *c[2];
    Node *p;
} mem[MaxN], *cur, *nil;

Node *newNode(int v, Node *p)
{
    cur->key = cur->sum = v;
    cur->c[0] = cur->c[1] = nil, cur->p = p;
    cur->size = 1;
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
    Node *root;
    void Init()
    {
        root = newNode(0, nil);
    }
    void Update(Node *x)
    {
        if (x == nil)   return;
        x->size = x->c[0]->size + x->c[1]->size + 1;
        x->sum = x->c[0]->sum + x->c[1]->sum + x->key;
    }
    Node *Make_tree(int a[], int l, int r, Node *p)
    {
        if (l > r)  return nil;
        int mid = l + r >> 1;
        Node *x = newNode(a[mid], p);
        x->c[0] = Make_tree(a, l, mid - 1, x);
        x->c[1] = Make_tree(a, mid + 1, r, x);
        Update(x);
        return x;
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
        Update(y);
    }
    void Splay(Node *x, Node *f)
    {
        while (x->p != f)
        {
            if (x->p->p == f)
                Rotate(x, x == x->p->c[0]);
            else
            {
                Node *y = x->p;
                int fd = y->p->c[0] == y;
                if (y->c[fd] == x)  Rotate(x, fd ^ 1), Rotate(x, fd);
                else
                    Rotate(y, fd), Rotate(x, fd);
            }
        }
        Update(x);
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
    void Insert(int pos, int a[], int n)
    {
        Select(pos, nil), Select(pos + 1, root);
        root->c[1]->c[0] = Make_tree(a, 0, n - 1, root->c[1]);
        Splay(root->c[1]->c[0], nil);
    }
    void Insert(int v)
    {
        Node *x = root, * y = nil;
        while (x != nil)
        {
            y = x;
            y->size++;
            x = x->c[v >= x->key];
        }
        y->c[v >= y->key] = x = newNode(v, y);
        Splay(x, nil);
    }
};

SplayTree sp;
int Q, b[2100000];
char com[20];

int main(int argc, char const *argv[])
{
    freopen("G.in", "r", stdin);
    freopen("G1.out", "w", stdout);

    int cas = 1;
    while (scanf("%d", &Q) != EOF)
    {
        if (Q == 0) break;
        Init();
        sp.Init();
        sp.Insert(0x7fffffff);
        printf("Scenario %d:\n", cas++);
        while (Q--)
        {
            scanf("%s", com);

            if (com[0] == 's')
            {
                int l, r;
                scanf("%d%d", &l, &r);
                sp.Select(l, nil);
                sp.Select(r + 2, sp.root);
                printf("%lld\n", sp.root->c[1]->c[0]->sum);
            }
            else if (com[0] == 'i')
            {
                int pos, n, r, m, a, c;
                scanf("%d%d%d%d%d%d", &pos, &n, &r, &m, &a, &c);
                for (int i = 0; i < r; i++)
                    scanf("%d", &b[i]);
                for (int i = r; i < n; i++)
                {
                    b[i] = ((long long)b[i - r] * a + c) % m;
                    c = (((long long)b[i - r] * a + c) / m) % m;
                }
                sp.Insert(pos, b, n);
            }
            else
            {
                int l, r;
                scanf("%d%d", &l, &r);
                sp.Select(l, nil);
                sp.Select(r + 2, sp.root);
                sp.root->c[1]->c[0] = nil;
                sp.Splay(sp.root->c[1], nil);
            }
        }
        puts("");
    }
    return 0;
}
