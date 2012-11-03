#include "iostream"
#include "cstdio"
#include "cstring"
#include "algorithm"
using namespace std;

const int MaxN = 10001;

struct Node
{
    int size, key, mx;

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

    cur->key = cur->mx = v;
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
    int splaytime,rotatetime;
    void Init()
    {
        root = nil;
        splaytime = rotatetime = 0;
    }
    void Pushup(Node *x)
    {
        if (x == nil)   return;
        x->size = x->c[0]->size + x->c[1]->size + 1;
        if (x->c[0] == nil)
            x->head = x;
        else
            x->head = x->c[0]->head;
        
        x->mx = max(max(x->c[0]->mx, x->c[1]->mx), x->key);
    }
    void Rotate(Node *x, int f)
    {
        if (x == nil)   return;
        rotatetime++;
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
        splaytime++;
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
            pos[edge[i].to]->key = pos[edge[i].to]->mx = edge[i].cost;
            pos[edge[i].to]->fa = pos[now];
            edgepos[edge[i].id] = edge[i].to;
            DFS(edge[i].to, now);
        }
}

int main(int argc, char const *argv[])
{
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
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
            scanf("%d%d%d", &u, &v, &cost);
            u--, v--;
            addedge(u, v, cost, i);
            addedge(v, u, cost, i);
        }
        DFS(0, -1);
        while (true)
        {
            int u, v;
            scanf("%s", buf);
            if (buf[0] == 'Q')
            {
                scanf("%d%d", &u, &v);
                u--, v--;
                Node *lca = sp.LCA(pos[u], pos[v]);
                int res = lca->c[1]->mx;
                if (pos[u] != lca)
                {
                    sp.Splay(pos[u], nil);
                    res = max(res, pos[u]->mx);
                }
                //printf("%d\n", res);
            }
            else if (buf[0] == 'C')
            {
                scanf("%d%d", &u, &v);
                u--;
                sp.Splay(pos[edgepos[u]], nil);
                pos[edgepos[u]]->key = v;
            }
            else
                break;
        }
        printf("splaytime = %d, rotatetime = %d\n",sp.splaytime,sp.rotatetime);
    }
    return 0;
}