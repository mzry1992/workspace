#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 300000;
const int mod = 99990001;

struct Node
{
	int size,key;

	int a,b,la,lb;
	int minid,id;

	Node *c[2];
	Node *p;
} mem[maxn],*cur,*nil,*pos[maxn];

Node *newNode(int v,Node *p)
{
	cur->c[0] = cur->c[1] = nil, cur->p = p;
	cur->size = 1;
	cur->key = v;

	cur->a = cur->la = 1;
	cur->b = cur->lb = 0;
	cur->minid = cur->id = cur-mem;

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
	void Pushup(Node *x)
	{
		if (x == nil)	return;
		Pushdown(x);
		Pushdown(x->c[0]);
		Pushdown(x->c[1]);
		x->size = x->c[0]->size+x->c[1]->size+1;
		
		x->minid = x->id;
		for (int i = 0;i < 2;i++)
			if (x->c[i] != nil)
				x->minid = min(x->minid,x->c[i]->minid);
	}
	void Pushdown(Node *x)
	{
		if (x == nil)	return;

		x->a = (long long)x->a*x->la%mod;
		x->b = ((long long)x->b*x->la%mod+x->lb)%mod;

		for (int i = 0;i < 2;i++)
			if (x->c[i] != nil)
			{
				//printf("node %d, c = %d\n",x-mem,x->c[i]-mem);
				x->c[i]->la = (long long)x->c[i]->la*x->la%mod;
				x->c[i]->lb = ((long long)x->c[i]->lb*x->la%mod+x->lb)%mod;
			}

		x->la = 1;
		x->lb = 0;
	}
	bool isRoot(Node *x)
	{
		return (x == nil) || (x->p->c[0] != x && x->p->c[1] != x);
	}
	void Rotate(Node *x,int f)
	{
		if (isRoot(x))	return;

		Node *y = x->p;
		y->c[f^1] = x->c[f], x->p = y->p;
		if (x->c[f] != nil)
			x->c[f]->p = y;
		if (y != nil)
		{
			if (y == y->p->c[1])
				y->p->c[1] = x;
			else if (y == y->p->c[0])
				y->p->c[0] = x;
		}
		x->c[f] = y,y->p = x;
		Pushup(y);
	}
	void Splay(Node *x)
	{
		static Node *stack[maxn];
		int top = 0;
		stack[top++] = x;
		for (Node *y = x;!isRoot(y);y = y->p)
			stack[top++] = y->p;
		while (top)
			Pushdown(stack[--top]);

		while (!isRoot(x))
		{
			Node *y = x->p;
			if (isRoot(y))
				Rotate(x,x == y->c[0]);
			else
			{
				int fd = y->p->c[0] == y;
				if (y->c[fd] == x)
					Rotate(x,fd^1), Rotate(x,fd);
				else
					Rotate(y,fd),Rotate(x,fd);
			}
		}
		Pushup(x);
	}
	Node *Access(Node *u)
	{
		Node *v = nil;
		while (u != nil)
		{
			Splay(u);
			v->p = u;
			u->c[1] = v;
			Pushup(u);
			u = (v = u)->p;
			if (u == nil)	return v;
		}
	}
	Node *Root(Node *u)
	{
		Access(u);
		Splay(u);
		for (Pushdown(u);u->c[0] != nil;u = u->c[0])
			Pushdown(u);
		Splay(u);
		return u;
	}
	Node *LCA(Node *u,Node *v)
	{
		if (Root(u) != Root(v))
			return nil;
		Access(u);
		return Access(v);
	}
	void Cut(Node *u)
	{
		Access(u);
		Splay(u);
		u->c[0] = u->c[0]->p = nil;
		Pushup(u);
	}
	void Link(Node *u,Node *v,int val)
	{
		Access(u);
		Splay(u);
		u->p = v;
		u->key = val;
		Pushup(u);
	}
};

struct Edge
{
	int to,next,w,id;
};
Edge edge[maxn*2];
int head[maxn],L;

void addedge(int u,int v,int w,int id)
{
	edge[L].to = v;
	edge[L].w = w;
	edge[L].next = head[u];
	edge[L].id = id;
	head[u] = L++;
}

SplayTree sp;
int n;
Node *epos[maxn],*fapos[maxn];

void DFS(int now,int fa)
{
	for (int i = head[now];i != -1;i = edge[i].next)
		if (edge[i].to != fa)
		{
			epos[edge[i].id] = pos[edge[i].to];
			fapos[edge[i].id] = pos[now];
			sp.Link(pos[edge[i].to],pos[now],edge[i].w);
			DFS(edge[i].to,now);
		}
}

int main()
{
	Init();

	scanf("%d",&n);
	for (int i = 0;i < n;i++)
	{
		pos[i] = newNode(0,nil);
		head[i] = -1;
	}
	L = 0;
	
	for (int i = 0;i < n-1;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		u--,v--;
		addedge(u,v,w,i);
		addedge(v,u,w,i);
	}
	DFS(0,-1);

	for (int i = 0;i < n-1;i++)
	{
		fflush(stdout);
		
		int id;
		scanf("%d",&id);
		id--;

		Node *u,*v;
		u = epos[id];
		v = fapos[id];

		printf("=============================\n");
		printf("u = %d, v = %d\n",u-mem,v-mem);

		sp.Access(u);
		int wi = ((long long)u->key*u->a%mod+u->b)%mod;
		printf("%d\n",wi);

		for (int j = 0;j < n;j++)
			printf("%d, c = (%d, %d), p = %d, a = %d, b = %d, la = %d, lb = %d, key = %d, minid = %d\n",
					pos[j]-mem,pos[j]->c[0]-mem,pos[j]->c[1]-mem,pos[j]->p-mem,pos[j]->a,pos[j]->b,pos[j]->la,pos[j]->lb,pos[j]->key,pos[j]->minid);

		sp.Cut(u);
		sp.Access(u);
		sp.Access(v);
		if (u->size > v->size || (u->size == v->size && u->minid > v->minid))
			swap(u,v);

		printf("uu = %d, vv = %d\n",u-mem,v-mem);

		u->a = (long long)u->a*wi%mod;
		u->b = (long long)u->b*wi%mod;

		v->b = (v->b+wi)%mod;

		printf("u = (%d, %d), v = (%d, %d)\n",u->a,u->b,v->a,v->b);
		
		for (int j = 0;j < n;j++)
			printf("%d, c = (%d, %d), p = %d, a = %d, b = %d, la = %d, lb = %d, key = %d, minid = %d\n",
					pos[j]-mem,pos[j]->c[0]-mem,pos[j]->c[1]-mem,pos[j]->p-mem,pos[j]->a,pos[j]->b,pos[j]->la,pos[j]->lb,pos[j]->key,pos[j]->minid);
	}
	return 0;
}
