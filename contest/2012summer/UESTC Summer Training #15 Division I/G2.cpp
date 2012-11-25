#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int MaxN = 2000005;

struct Node
{
    int key, size;
    long long s;
    Node* c[2];
    Node* p;
} memo[MaxN], *cur, *nil, *root;
int ax[MaxN];

struct Splay
{
    Node* newNode(int v, Node* p) const
    {
        cur->key = v, cur->s = v;
        cur->c[0] = cur->c[1] = nil, cur->p = p;
        cur->size = 1;
        return cur++;
    }
    void init() const
    {
        cur = nil = memo, nil = newNode(0, nil);
        nil->size = 0, root = newNode(0, nil);
        root->c[1] = newNode(0, root), update(root);
    }
    void update(Node* x) const
    {
        if (x == nil ) return;
        x->size = x->c[0]->size + x->c[1]->size + 1;
        x->s = x->c[0]->s + x->c[1]->s + x->key;
    }
    Node* make_tree(int l, int r, Node* p) const
    {
        if (l > r) return nil;
        int mid = (l + r) >> 1;
        Node* x = newNode(ax[mid], p);
        x->c[0] = make_tree(l, mid - 1, x);
        x->c[1] = make_tree(mid + 1, r, x);
        update(x);
        return x;
    }
    void rotate(Node* x, int f)
    {
        if (x == nil) return;
        Node* y = x->p;
        y->c[f ^ 1] = x->c[f], x->p = y->p;
        if (x->c[f] != nil) x->c[f]->p = y;
        if (y->p != nil) y->p->c[y->p->c[1] == y] = x;
        x->c[f] = y, y->p = x;
        update(y);
    }
    void splay(Node* x, Node* f)
    {
        while (x->p != f)
        {
            if (x->p->p == f)
            {
                rotate(x, x == x->p->c[0]);
            }
            else
            {
                Node* y = x->p;
                int fd = y->p->c[0] == y;
                if (y->c[fd] == x) rotate(x, fd ^ 1), rotate(x, fd);
                else rotate(y, fd), rotate(x, fd);
            }
        }
        update(x);
        if (f == nil) root = x;
    }
    void select(int k, Node* f)
    {
        Node* x = root;
        int tmp;
        while ((tmp = x->c[0]->size) != k)
        {
            if (k < tmp) x = x->c[0];
            else x = x->c[1], k -= tmp + 1;
        }
        splay(x, f);
    }
    void insert(int pos, int n)
    {
        select(pos, nil), select(pos + 1, root);
        root->c[1]->c[0] = make_tree(0, n - 1, root->c[1]);
        splay(root->c[1]->c[0], nil);
    }
} tr;

int main()
{
    int N, l, n, r,m,a,c;
    char op[15];
    int cas = 1;

    //freopen("in.txt", "r", stdin);

    freopen("G.in","r",stdin);
    freopen("G2.out","w",stdout);

    while (scanf("%d", &N) == 1 && N)
    {
        printf("Scenario %d:\n", cas++);
        tr.init();
        while (N--)
        {
            scanf("%s", op);
            if (op[0] == 'i')
            {
                scanf("%d%d%d%d%d%d", &l, &n, &r, &m, &a, &c);
                for (int i = 0; i < r; i++)
                    scanf("%d", &ax[i]);
                for (int i = r; i < n; i++)
                {
                    ax[i] = ((long long)ax[i - r] * a + c) % m;
                    c = (((long long)ax[i - r] * a + c) / m) % m;
                }
                tr.insert(l, n);
            }
            else if (op[0] == 's')
            {
                scanf("%d%d", &l, &r);
                tr.select(l, nil);
                tr.select(r + 2, root);
                printf("%lld\n", root->c[1]->c[0]->s);
            }
            else if (op[0] == 'd')
            {
                scanf("%d%d", &l, &r);
                tr.select(l, nil);
                tr.select(r + 2, root);
                root->c[1]->c[0] = nil;
                tr.splay(root->c[1], nil);
            }
        }
        puts("");
    }

    return 0;
}
