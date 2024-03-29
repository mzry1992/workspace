#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MaxN = 110000;

struct Node
{
    int size, key;
    bool rev,same;

    int lsum, rsum, sum, maxsum,sa;

    Node *c[2];
    Node *p, *fa, *head;
} mem[MaxN], *cur, *nil, *pos[MaxN];

Node *newNode(int v, Node *p)
{
    cur->c[0] = cur->c[1] = cur->fa = nil, cur->p = p;
    cur->head = cur;
    cur->size = 1;
	cur->rev = false;

	cur->same = false;
	cur->sa = 0;
    cur->lsum = cur->rsum = cur->maxsum = 0;
    cur->sum = v;

    cur->key = v;
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
        Pushdown(x); Pushdown(x->c[0]); Pushdown(x->c[1]);
        x->size = x->c[0]->size + x->c[1]->size + 1;
        if (x->c[0] == nil)
            x->head = x;
        else
            x->head = x->c[0]->head;

        x->sum = x->c[0]->sum + x->c[1]->sum + x->key;
        x->lsum = max(x->c[0]->lsum, x->c[0]->sum + x->key + max(0, x->c[1]->lsum));
        x->rsum = max(x->c[1]->rsum, x->c[1]->sum + x->key + max(0, x->c[0]->rsum));
        x->maxsum = max(max(x->c[0]->maxsum, x->c[1]->maxsum),
                        x->key + max(0, x->c[0]->rsum) + max(0, x->c[1]->lsum));
    }
    void Pushdown(Node *x)
    {
        if (x == nil)   return;
        if (x->rev)
        {
            x->rev = 0;
            x->c[0]->rev ^= 1;
            x->c[1]->rev ^= 1;
            swap(x->c[0], x->c[1]);
        }
		if (x->same)
		{
			x->same = false;
			x->key = x->sa;
			x->sum = x->sa*x->size;
			x->lsum = x->rsum = x->maxsum = max(0,x->sum);
			if (x->c[0] != nil)
				x->c[0]->same = true,x->c[0]->sa = x->sa;
			if (x->c[1] != nil)
				x->c[1]->same = true,x->c[1]->sa = x->sa;
		}
    }
    void Rotate(Node *x, int f)
    {
        if (x == nil)   return;
        Node *y = x->p;
        y->c[f ^ 1] = x->c[f], x->p = y->p;
        if (x->c[f] != nil)
            x->c[f]->p = y;
        if (y->p != nil)
        {
            if (y->p->c[1] == y)
                y->p->c[1] = x;
            else if (y->p->c[0] == y)
                y->p->c[0] = x;
        }
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
    Node *Link(Node *u, Node *v)
    {
        v->fa = u;
    }
    void *Cut(Node *u)
    {
        Splay(u, nil);
        if (u->c[0] != nil)
            u->c[0] = u->c[0]->p = nil;
        u->fa = nil;
        Pushup(u);
    }
    void ChangeRoot(Node *u)
    {
        Access(u);
        u->rev ^= 1;
    }
    Node *GetRoute(Node *u, Node *v)
    {
        ChangeRoot(u);
        return Access(v);
    }
};

int n, m;
SplayTree sp;

int main(int argc, char const *argv[])
{
    freopen("data.in","r",stdin);
    while (scanf("%d", &n) != EOF)
    {
        Init();
        sp.Init();
        for (int i = 0; i < n; i++)
        {
            int v;
            scanf("%d", &v);
            pos[i] = newNode(v, nil);
        }
        for (int i = 0; i < n - 1; i++)
        {
            int u, v;
            scanf("%d%d", &u, &v);
			u--,v--;
			sp.Link(pos[u], pos[v]);
        }
        scanf("%d", &m);
        for (int i = 0; i < m; i++)
        {
            int typ, u, v, c;
            scanf("%d%d%d", &typ, &u, &v);
            u--,v--;
			if (typ == 1)
                printf("%d\n",sp.GetRoute(pos[u],pos[v])->maxsum);
            else
            {
                scanf("%d", &c);
				Node *p = sp.GetRoute(pos[u],pos[v]);
				p->same = true;
				p->sa = c;
            }
            // for (int j = 0;j < n;j++)
            //     printf("id = %d, c[0] = %d, c[1] = %d, p = %d, fa = %d\n",j+1,pos[j]->c[0]-mem,pos[j]->c[1]-mem,pos[j]->p-mem,pos[j]->fa-mem);
        }
    }
    return 0;
}
