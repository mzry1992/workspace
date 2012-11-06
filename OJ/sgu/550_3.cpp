#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int MaxN = 500000;
struct Node
{
	int size,key;

	Node *c[2];
	Node *p;
}mem[maxn],*cur,*nil;
Node *l[maxn],*r[maxn];//左括号右括号定义在前面

int emp[maxn],totemp;
Node *newNode(int v,Node *p)
{
	cur->c[0] = cur->c[1] = nil,cur->p = p;
	cur->size = 1;
	cur->key = v;
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
		if (x == nil)	return;
		Pushdown(x);
		Pushdown(x->c[0]);
		Pushdown(x->c[1]);
		x->size = x->c[0]->size+x->c[1]->size+1;
	}
	void Pushdown(Node *x)
	{
		if (x == nil)	return;
	}
	void Rotate(Node *x,int f)
	{
		if (x == nil)	return;
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
		static Node *stack[maxn];
		int top = 0;
		stack[top++] = x;
		for (Node *y = x; y != f;y = y->p)
			stack[top++] = y->p;
		while (top)
			Pushdown(stack[--top]);

		while (x->p != f)
		{
			Node *y = x->p;
			if (y->p == f)
				Rotate(x,x == y->c[0]);
			else
			{
				int fd = y->p->c[0] == y;
				if (y->c[fd] == x)
					Rotate(x, fd^1), Rotate(x,fd);
				else
					Rotate(y,fd), Rotate(x,fd);
			}
		}
		Pushup(x);
		if (f == nil)
			root = x;
	}
	void Link(int u,int v,int w)
	{
		Splay(l[v],nil);
		Splay(l[u],nil);
		l[u]->key = w;
		Pushup(l[u]);
		Splay(r[u],l[u]);
		Node *lhs = l[v], rhs = l[v]->c[1];
		lhs->c[1] = l[u];
		r[u]->c[1] = rhs;
		r[u]->p = lhs;
		rhs->p = r[u];
		Pushup(r[u]);
		Pushup(l[u]);
		Pushup(lhs);
		Spaly(l[u],nil);
	}
};

SplayTree sp;
int n;
struct Edge
{
	int to,next,w,id;
};
Edge edge[maxn];
int head[maxn],L;

void addedge(int u,int v,int w,int id)
{
	edge[L].to = v;
	edge[L].w = w;
	edge[L].id = id;
	edge[L].next = head[u];
	head[u] = L++;
}

void DFS(int now,int fa)
{
	for (int i = head[now];i != -1;i = edge[i].next)
		if (edge[i].to != fa)
		{
			sp.Link(edge[i].to,now,edge[i].w);

			DFS(edge[i].to,now);
		}
}

int main()
{
	Init();

	scanf("%d",&n);

	for (int i = 0;i < n;i++)
	{
		l[i] = newNode(0,nil);
		r[i] = newNode(0,nil);
		l[i]->c[1] = r[i], r[i]->p = l[i];
		sp.Pushup(l[i]);

		head[i] = -1;
	}
	L = 0;

	for (int i = 0;i < n-1;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		addedge(u,v,w,i);
		addedge(v,u,w,i);
	}

	DFS(0,-1);
	return 0;
}
