#include "iostream"
#include "cstdio"
#include "cstring"
#include "algorithm"
using namespace std;

const int MaxN = 2000000;

struct Node
{
    int size, key;
    int rev;

    Node *c[2];
    Node *p;
} mem[MaxN], *cur, *nil;

int emp[MaxN], totemp;

Node *newNode(int v, Node *p)
{
    cur = mem + emp[--totemp];
    cur->c[0] = cur->c[1] = nil, cur->p = p;
    cur->size = 1;
    cur->key = v;
    cur->rev = 0;
    return cur;
}

void Init()
{
    for (int i = 0; i < MaxN; i++)
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
        Pushdown(x);
        Pushdown(x->c[0]);
        Pushdown(x->c[1]);
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
            if (k < tmp)  x = x->c[0];
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
    Node *Make_tree(char a[], int l, int r, Node *p)
    {
        if (l > r)  return nil;
        int mid = l + r >> 1;
        Node *x = newNode(a[mid], p);
        x->c[0] = Make_tree(a, l, mid - 1, x);
        x->c[1] = Make_tree(a, mid + 1, r, x);
        Pushup(x);
        return x;
    }
    void Insert(int pos, char a[], int n)
    {
        Select(pos, nil), Select(pos + 1, root);
        root->c[1]->c[0] = Make_tree(a, 0, n - 1,root->c[1]);
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

int n,curpos;
SplayTree sp;
char com[20], a[MaxN];

int main(int argc, char const *argv[])
{
	freopen("M.in","r",stdin);
    while (scanf("%d", &n) != EOF)
    {
        Init();
        sp.Init();
        sp.Insert(0);
        sp.Insert(0);
        curpos = 0;
        for (int q = 0; q < n; q++)
        {
        	//printf("curpos = %d\n",curpos);
        	scanf("%s",com);
        	if (com[0] == 'M')
        		scanf("%d",&curpos);
        	else if (com[0] == 'I')
        	{
        		int len;
        		scanf("%d",&len);
        		gets(a);
        		gets(a);
        		sp.Insert(curpos,a,len);
        	}
        	else if (com[0] == 'D')
        	{
        		int len;
        		scanf("%d",&len);
        		sp.Remove(curpos,curpos+len-1);
        	}
        	else if (com[0] == 'R')
        	{
        		int len;
        		scanf("%d",&len);
        		sp.Select(curpos,curpos+len-1);
        		sp.root->c[1]->c[0]->rev ^= 1;
        		sp.Pushup(sp.root->c[1]),sp.Pushup(sp.root);
        	}
        	else if (com[0] == 'G')
        	{
        		sp.Select(curpos,curpos);
        		printf("%c\n",sp.root->c[1]->c[0]->key);
        	}
        	else if (com[0] == 'P')
        		curpos--;
        	else
        		curpos++;
        }
    }
    return 0;
}
