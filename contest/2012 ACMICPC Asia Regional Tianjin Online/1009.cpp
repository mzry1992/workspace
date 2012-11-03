#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
#pragma comment(linker, "/STACK:1024000000,1024000000")
const int MaxN = 1000103;

struct Node
{
    int size,key;
    bool rev;

    Node *c[2];
    Node *p;
} mem[MaxN], *cur, *nil;

Node *newNode(int v, Node *p)
{
    cur->c[0] = cur->c[1] = nil, cur->p = p;
    cur->size = 1;
    cur->key = v;
    return cur++;
}

void Init()
{
    cur = mem;
    nil = newNode(0, cur);
    nil->size = 0;
}

bool first;

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

        if (x->rev)
        {
            x->rev = 0;
            x->c[0]->rev ^= 1;
            x->c[1]->rev ^= 1;
            swap(x->c[0], x->c[1]);
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
        //Recycle(root->c[1]->c[0]);
        root->c[1]->c[0] = nil;
        Splay(root->c[1], nil);
    }
};

SplayTree sp;
int n,m,L,R,a[500010];
char com[20],cu[20];

int main()
{
	int totcas;
	scanf("%d",&totcas);
	for (int cas = 1;cas <= totcas;cas++)
	{
	    Init();
	    sp.Init();
	    sp.Insert(0);
	    sp.Insert(0);

	    scanf("%d",&n);
	    for (int i = 0;i < n;i++)
            scanf("%d",&a[i]);
        sp.Insert(0,a,n);

        scanf("%d%d",&L,&R);
        L--,R--;
        scanf("%d",&m);
        for (int q = 0;q < m;q++)
        {
            scanf("%s",com);
            if (strcmp(com,"MoveLeft") == 0)
            {
                scanf("%s",cu);
                if (cu[0] == 'L')
                {
                    if (L == 0) continue;
                    L--;
                }
                else
                {
                    if (R == 0) continue;
                    if (R == L) continue;
                    R--;
                }
            }
            else if (strcmp(com,"MoveRight") == 0)
            {
                scanf("%s",cu);
                if (cu[0] == 'L')
                {
                    if (L == sp.root->size-3)   continue;
                    if (L == R) continue;
                    L++;
                }
                else
                {
                    if (R == sp.root->size-3)   continue;
                    R++;
                }
            }
            else if (strcmp(com,"Insert") == 0)
            {
                scanf("%s%d",cu,&a[0]);
                n++;
                if (cu[0] == 'L')
                    sp.Insert(L,a,1);
                else
                    sp.Insert(R+1,a,1);
                R++;
            }
            else if (strcmp(com,"Delete") == 0)
            {
                scanf("%s",cu);
                n--;
                if (cu[0] == 'L')
                    sp.Remove(L,L);
                else
                    sp.Remove(R,R);
                R--;
            }
            else if (strcmp(com,"Reverse") == 0)
            {
                sp.Select(L,R);
                sp.root->c[1]->c[0]->rev ^= 1;
                sp.Pushup(sp.root->c[1]),sp.Pushup(sp.root);
            }

            //printf("L = %d, R = %d\n",L,R);
        }
        for (int i = 0;i < n;i++)
        {
            if (i > 0)
                printf(" ");
            sp.Select(i,i);
            printf("%d",sp.root->c[1]->c[0]->key);
        }
        printf("\n");
//        first = true;
//        sp.Select(0,n-1);
//        sp.Travel(sp.root->c[1]->c[0]);
//        printf("\n");
	}
	return 0;
}
