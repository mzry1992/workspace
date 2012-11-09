#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 210000;
struct Node
{
    int size,key;

    int rev,add;

    Node *c[2];
    Node *p;
}mem[maxn],*cur,*nil;

Node *newNode(int v,Node *p)
{
    cur->c[0] = cur->c[1] = nil,cur->p = p;
    cur->size = 1;
    cur->key = v;

    cur->rev = cur->add = 0;

    return cur++;
}
void Init()
{
    cur = mem;
    nil = newNode(0,cur);
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
        x->size = x->c[0]->size+x->c[1]->size+1;
    }
    void Pushdown(Node *x)
    {
        if (x == nil)   return;

        if (x->rev)
        {
            x->rev = 0;
            x->c[0]->rev ^= 1;
            x->c[1]->rev ^= 1;
            swap(x->c[0],x->c[1]);
        }
        x->key += x->add;
        x->c[0]->add += x->add;
        x->c[1]->add += x->add;
        x->add = 0;
    }
    void Rotate(Node *x,int f)
    {
        if (x == nil)   return;
        Node *y = x->p;
        y->c[f^1] = x->c[f], x->p = y->p;
        if (x->c[f] != nil)
            x->c[f]->p = y;
        if (y->p != nil)
            y->p->c[y->p->c[1] == y] = x;
        x->c[f] = y, y->p = x;
        Pushup(y);
    }
    void Splay(Node *x,Node *f)
    {
        while (x->p != f)
        {
            Node *y = x->p;
            if (y->p == f)
                Rotate(x,x == y->c[0]);
            else
            {
                int fd = y->p->c[0] == y;
                if (y->c[fd] == x)
                    Rotate(x,fd^1), Rotate(x,fd);
                else
                    Rotate(y,fd), Rotate(x,fd);
            }
        }
        Pushup(x);
        if (f == nil)
            root = x;
    }
    void Select(int k,Node *f)
    {
        Node *x = root;
        Pushdown(x);
        int tmp;
        while ((tmp = x->c[0]->size) != k)
        {
            if (k < tmp)    x = x->c[0];
            else
                x = x->c[1], k -= tmp+1;
            Pushdown(x);
        }
        Splay(x,f);
    }
    void Select(int l,int r)
    {
        Select(l, nil), Select(r+2,root);
    }
    Node *Make_tree(int a[],int l,int r,Node *p)
    {
        if (l > r)  return nil;
        int mid = l+r>>1;
        Node *x = newNode(a[mid],p);
        x->c[0] = Make_tree(a,l,mid-1,x);
        x->c[1] = Make_tree(a,mid+1,r,x);
        Pushup(x);
        return x;
    }
    void Insert(int pos,int a[],int n)
    {
        Select(pos,nil), Select(pos+1,root);
        root->c[1]->c[0] = Make_tree(a,0,n-1,root->c[1]);
        Splay(root->c[1]->c[0],nil);
    }
    void Insert(int v)
    {
        Node *x = root,*y = nil;
        while (x != nil)
        {
            y = x;
            y->size++;
            x = x->c[v >= x->key];
        }
        y->c[v >= y->key] = x = newNode(v,y);
        Splay(x,nil);
    }
    void Remove(int l,int r)
    {
        Select(l,r);
        root->c[1]->c[0] = nil;
        Splay(root->c[1],nil);
    }
};

SplayTree sp;
int n,m,k1,k2;
int a[maxn];
char buf[20];

int main()
{
    int cas = 0;
    while (true)
    {
        scanf("%d%d%d%d",&n,&m,&k1,&k2);
        if (n == 0 && m == 0 && k1 == 0 && k2 == 0) break;

        Init();
        sp.Init();
        sp.Insert(0);
        sp.Insert(0);

        for (int i = 0;i < n;i++)
            scanf("%d",&a[i]);
        sp.Insert(0,a,n);

        cas++;
        printf("Case #%d:\n",cas);

        int siz = n;
        for (int i = 0;i < m;i++)
        {
            scanf("%s",buf);
            if (buf[0] == 'a')
            {
                int add;
                scanf("%d",&add);
                sp.Select(0,k2-1);
                sp.root->c[1]->c[0]->add += add;
                sp.Pushup(sp.root->c[1]), sp.Pushup(sp.root);
            }
            else if (buf[0] == 'r')
            {
                sp.Select(0,k1-1);
                sp.root->c[1]->c[0]->rev ^= 1;
                sp.Pushup(sp.root->c[1]), sp.Pushup(sp.root);
            }
            else if (buf[0] == 'i')
            {
                siz++;
                scanf("%d",&a[0]);
                sp.Insert(1,a,1);
            }
            else if (buf[0] == 'd')
            {
                siz--;
                sp.Remove(0,0);
            }
            else if (buf[0] == 'm')
            {
                int dir;
                scanf("%d",&dir);
                if (dir == 1)
                {
                    sp.Select(siz-1,siz-1);
                    a[0] = sp.root->c[1]->c[0]->key;
                    sp.Remove(siz-1,siz-1);
                    sp.Insert(0,a,1);
                }
                else
                {
                    sp.Select(0,0);
                    a[0] = sp.root->c[1]->c[0]->key;
                    sp.Remove(0,0);
                    sp.Insert(siz-1,a,1);
                }
            }
            else
            {
                sp.Select(0,0);
                printf("%d\n",sp.root->c[1]->c[0]->key);
            }
        }
    }
    return 0;
}
