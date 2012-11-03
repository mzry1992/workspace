#include "iostream"
#include "cstdio"
#include "cstring"
#include "algorithm"
using namespace std;

const int MaxN = 21000;

struct Node
{
    int size,key;
    bool rev;

    Node *c[2];
    Node *p,*f;
}mem[MaxN],*cur,*nil;

Node *newNode(int v,Node *p)
{
    cur->c[0] = cur->c[1] = cur->f = nil,cur->p = p;
    cur->size = 1;
    cur->key = v;
    cur->rev = 0;
    return cur++;
}

void Init()
{
    cur = mem;
    nil = newNode(0,cur);
    nil->size = 0;
}

struct DynamicTree
{
    //root还有存在的意义么。。？
    void Pushup(Node *x)
    {
        if (x == nil)   return;
        Pushdown(x);Pushdown(x->c[0]);Pushdown(x->c[1]);
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
    }
    void Rotate(Node *x,int f)
    {
        if (x == nil)   return;
        Node *y = x->p;
        y->c[f^1]=x->c[f],x->p=y->p;
        if (x->c[f] != nil)
            x->c[f]->p = y;
        if (y->p != nil)
            y->p->c[y->p->c[1] == y] = x;
        x->c[f]=y,y->p=x;
        Pushup(y);
    }
    void Splay(Node *x,Node *f)
    {
        while (x->p != f)
        {
            Node *y = x->p;
            if (y->p == f)
                Rotate(x,x==y->c[0]);
        }
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}