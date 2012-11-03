#include "iostream"
#include "cstdio"
#include "cstring"
#include "algorithm"
using namespace std;

const int MaxN = 10001;

struct Node
{
    int size, key, sum;

    Node *c[2];
    Node *p,*fa;
    Node *head;
} mem[MaxN], *cur, *nil, *pos[MaxN];

int n;

Node *newNode(int v, Node *p)
{
    cur->c[0] = cur->c[1] = nil, cur->p = p;
    cur->fa = nil;
    cur->head = cur;
    cur->size = 1;

    cur->key = cur->sum = v;
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
        root = nil;
    }
    void Pushup(Node *x)
    {
        if (x == nil)   return;
        x->size = x->c[0]->size + x->c[1]->size + 1;
        if (x->c[0] == nil)
            x->head = x;
        else
            x->head = x->c[0]->head;

        x->sum = x->c[0]->sum + x->c[1]->sum + x->key;
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
    Node *Select (int k, Node *f)
    {
        Node *x = f ;
        //Pushdown (x);
        int tmp;
        while ((tmp = x->c[0]-> size) != k)
        {
            if (k < tmp) x = x->c [0];
            else
                x = x->c[1] , k -= tmp + 1;
            //Pushdown (x);
        }
        return x;
    }
    Node *Access(Node *u)
    {
        Node *v = nil;
        while (u != nil)
        {
            Splay(u, nil);
            v->p = u;
            u->c[1]->p = nil;
            u->c[1] = v;
            Pushup(u);
            v = u;
            u = u->head->fa;
            if (u == nil)   return v;
        }
    }
    Node *LCA(Node *u, Node *v)
    {
        Access(u);
        return Access(v);
    }
};

struct Edge
{
    int to, next, cost, id;
} edge[MaxN * 2];
int head[MaxN], L, edgepos[MaxN * 2];

void addedge(int u, int v, int cost, int id)
{
    edge[L].id = id;
    edge[L].to = v;
    edge[L].cost = cost;
    edge[L].next = head[u];
    head[u] = L++;
}

SplayTree sp;
char buf[20];

void DFS(int now, int fa)
{
    for (int i = head[now]; i != -1; i = edge[i].next)
        if (edge[i].to != fa)
        {
            pos[edge[i].to]->key = pos[edge[i].to]->sum = edge[i].cost;
            pos[edge[i].to]->fa = pos[now];
            edgepos[edge[i].id] = edge[i].to;
            DFS(edge[i].to, now);
        }
}

int main(int argc, char const *argv[])
{
    int totcas;
    scanf("%d", &totcas);
    for (int cas = 1; cas <= totcas; cas++)
    {
        Init();
        sp.Init();

        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            pos[i] = newNode(0, nil);
            head[i] = -1;
        }
        L = 0;
        for (int i = 0; i < n - 1; i++)
        {
            int u, v, cost;
            scanf("%d%d%d",&u,&v,&cost);
            u--, v--;
            addedge(u, v, cost, i);
            addedge(v, u, cost, i);
        }
        DFS(0, -1);
        while (true)
        {
            int u, v, k;
            scanf("%s", buf);
            if (strcmp(buf, "DIST") == 0)
            {
                scanf("%d%d",&u,&v);
                u--, v--;
                Node *lca = sp.LCA(pos[u], pos[v]);
                int res = lca->c[1]->sum;
                if (pos[u] != lca)
                {
                    sp.Splay(pos[u], nil);
                    res += pos[u]->sum;
                }
                printf("%d\n", res);
            }
            else if (strcmp(buf, "KTH") == 0)
            {
                scanf("%d%d%d",&u,&v,&k);
                u--, v--, k--;
                Node *lca = sp.LCA(pos[u], pos[v]);
                Node *res;
                if (pos[u] == lca)
                {
                    if (k == 0)
                        res = lca;
                    else
                        res = sp.Select(k - 1, lca->c[1]);
                }
                else
                {
                    sp.Splay(pos[u], nil);
                    if (k < pos[u]->size)
                        res = sp.Select(pos[u]->size-k-1, pos[u]);
                    else
                    {
                        k -= pos[u]->size;
                        if (k == 0)
                            res = lca;
                        else
                            res = sp.Select(k - 1, lca->c[1]);
                    }
                }
                printf("%d\n", res - mem);
            }
            else
                break;
        }
    }
    return 0;
}