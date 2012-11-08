#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 500000;
const int mod = 99990001;
struct Node
{
	int size,key;

	int a,b;
	int minid,id;

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

	cur->a = 1;
	cur->b = 0;
	cur->minid = cur->id = maxn;

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

		x->minid = x->id;
		for (int i = 0;i < 2;i++)
			if (x->c[i] != nil)
				x->minid = min(x->minid,x->c[i]->minid);
	}
	void Pushdown(Node *x)
	{
		if (x == nil)	return;

		x->key = ((long long)x->key*x->a%mod+x->b)%mod;
		for (int i = 0;i < 2;i++)
			if (x->c[i] != nil)
			{
				x->c[i]->a = (long long)x->c[i]->a*x->a%mod;
				x->c[i]->b = ((long long)x->c[i]->b*x->a%mod+x->b)%mod;
			}
		x->a = 1;
		x->b = 0;
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
	Node *Last(Node *now)
	{
		Splay(now,nil);
		while (now->c[1] != nil)
			now = now->c[1];
		return now;
	}
	//把u接到v下面去，边权为w
	//先转成下面的样子：
	//  lv        lu
	//  /\         \
	//c0 c1         ru
	//              /
	//            c2  
	//再链接成这样：
	//  lv
	//  /\
	//c0  lu
	//     \
	//      ru
	//      /\
	//    c2  c1
	//需要保证u是某棵树的根
	void Link(int u,int v,int w)
	{
		Splay(l[v],nil);

		Splay(l[u],nil);
		l[u]->key = w;
		Pushup(l[u]);
		Splay(r[u],l[u]);

		Node *c1 = l[v]->c[1];
		l[v]->c[1] = l[u];
		r[u]->c[1] = c1;
		l[u]->p = l[v];
		c1->p = r[u];
		Pushup(r[u]);
		Pushup(l[u]);
		Pushup(l[v]);
		Splay(l[u],nil);
	}
	//把u为根的子树分离开
	//       lu
	//      /  \
	//     /    \
	//   c0     ru
	//  / \    / \
	//   last c1 c2
	//把c0和c2断开
	//然后接上？
	//         lu
	//          \
	//   last    ru
	//  / \     / 
	// c0  c2  c1
	int Split(int u)
	{
		Splay(l[u],nil);

		int ret = l[u]->key;
		Splay(r[u],l[u]);
		Node *c0 = l[u]->c[0], *c2 = r[u]->c[1]; 
		
		l[u]->key = 0;//去掉边权
		l[u]->c[0] = r[u]->c[1] = c0->p = c2->p = nil;
		Pushup(r[u]);
		Pushup(l[u]);
		
		Node *last = Last(c0);
		Splay(last,nil);
		last->c[1] = c2;
		c2->p = last;
		Pushup(last);

		//对拆分后的两部份进行处理
		Node *nu = last;
		Node *nv = l[u];
		if (nu->size > nv->size || (nu->size == nv->size && nu->minid > nv->minid))
			swap(nu,nv);
		nu->a = (long long)nu->a*ret%mod;
		nu->b = (long long)nu->b*ret%mod;
		nv->b = (nv->b+ret)%mod;

		return ret;//返回原边权
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
int eid[maxn],toid[maxn];

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
			eid[edge[i].id] = edge[i].to;
			toid[edge[i].id] = now;

			DFS(edge[i].to,now);
		}
}

int main()
{
	Init();
	sp.Init();

	scanf("%d",&n);

	for (int i = 0;i < n;i++)
	{
		l[i] = newNode(0,nil);
		r[i] = newNode(0,nil);
		l[i]->id = r[i]->id = i;
		l[i]->c[1] = r[i], r[i]->p = l[i];
		sp.Pushup(l[i]);

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

		int ret = sp.Split(eid[id]);
		printf("%d\n",ret);
	}

	return 0;
}
