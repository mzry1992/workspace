#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 900000;
const int mod = 99990001;

struct Node
{
	int size,key;

	int a,b;
	int minid,id;

	Node *c[2];
	Node *p;
} mem[maxn],*cur,*nil;

int emp[maxn],totemp;
Node *l[maxn],*r[maxn];

Node *newNode(int v,Node *p)
{
	cur = mem+emp[--totemp];
	cur->c[0] = cur->c[1] = nil,cur->p = p;
	cur->size = 1;
	cur->key = v;

	cur->a = 1;
	cur->b = 0;
	cur->minid = cur->id = maxn;

	return cur;
}
void Init()
{
	for (int i = 0;i < maxn;i++)
		emp[i] = i;
	totemp = maxn;
	cur = mem+emp[--totemp];
	nil = newNode(0,cur);
	nil->size = 0;
}
void Recycle(Node *p)
{
	if (p == nil)	return;
	Recycle(p->c[0]),Recycle(p->c[1]);
	emp[totemp++] = p-mem;
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
		x->c[f] = y,y->p = x;
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
					Rotate(x,fd^1),Rotate(x,fd);
				else
					Rotate(y,fd),Rotate(x,fd);
			}
		}
		Pushup(x);
		if (f == nil)
			root = x;
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
		y->c[v >= y->key] = x = newNode(v,y);
		Splay(x,nil);
	}
	void Insert(int pos,int v)
	{
		Select(pos,nil), Select(pos+1,root);
		root->c[1]->c[0] = newNode(v,root->c[1]);
		Splay(root->c[1]->c[0],nil);
	}
	void Insert(Node *pos,Node *v)
	{
		int pl;
		if (pos == nil)
		{
			Init();
			Insert(0), Insert(0);
			pl = 0;
		}
		else
		{
			Splay(pos, nil);
			pl = root->c[0]->size;
		}
		Select(pl,nil), Select(pl+1,root);
		root->c[1]->c[0] = v;
		v->p = root->c[1];
		Splay(v,nil);
	}
	void Select(int k,Node *f)
	{
		Node *x = root;
		Pushdown(x);
		int tmp;
		while ((tmp = x->c[0]->size) != k)
		{
			if (k < tmp)	x = x->c[0];
			else
				x = x->c[1], k -= tmp+1;
			Pushdown(x);
		}
		Splay(x,f);
	}
	void Select(int l,int r)
	{
		Select(l,nil),Select(r+2,root);
	}
	void Select(Node *l,Node *r)
	{
		Splay(l,nil);
		int pl = root->c[0]->size-1;
		Splay(r,nil);
		int pr = root->c[0]->size-1;
		Select(pl,pr);
	}
	//把[l,r]代表的子树分离出去
	Node *Split(Node *l,Node *r)
	{
		Select(l,r);
		Node *res = root->c[1]->c[0];
		root->c[1]->c[0] = res->p = nil;
		Splay(root->c[1],nil);
		if (root->size == 2)
		{
			Recycle(root);
			Init();
		}
		return res;
	}
	//边权保存在l[u]处？
	//把u这棵子树连接到v下面去，边权为val
	void Link(int u,int v,int val)
	{
		Node *pos = Split(l[u],r[u]);
		if (v >= 0)
			Insert(l[v],pos);
		else
			Insert(nil,pos);

		Select(l[u],l[u]);
		root->c[1]->c[0]->key = val;
		Pushup(root->c[1]);
		Pushup(root);
	}
	int AncestorID(Node *now)
	{
		Splay(now,nil);
		Select(1,nil);
		return root->id;
	}
};

SplayTree sp;
int epos[maxn],topos[maxn];

struct Edge
{
	int to,next,id,w;
};
Edge edge[maxn];
int head[maxn],L;

void addedge(int u,int v,int w,int id)
{
	edge[L].to = v;
	edge[L].id = id;
	edge[L].w = w;
	edge[L].next = head[u];
	head[u] = L++;
}

void DFS(int now,int fa)
{
	for (int i = head[now];i != -1;i = edge[i].next)
		if (edge[i].to != fa)
		{
			sp.Link(edge[i].to,now,edge[i].w);
			epos[edge[i].id] = edge[i].to;
			topos[edge[i].id] = now;

			DFS(edge[i].to,now);
		}
}

int n;
int a[maxn];

int main()
{
	Init();

	n = 200000;

	//scanf("%d",&n);
	for (int i = 0;i < n;i++)
	{
		sp.Init();
		sp.Insert(0), sp.Insert(0);//插入两个节点代表序列端点
		sp.Insert(0,0), sp.Insert(1,0);//插入代表一个节点的左右括号
		sp.Select(0,0), l[i] = sp.root->c[1]->c[0];//记录左右括号位置
		sp.Select(1,1), r[i] = sp.root->c[1]->c[0];
		l[i]->minid = r[i]->minid = l[i]->id = r[i]->id = i;

		head[i] = -1;
	}
	L = 0;

	for (int i = 0;i < n-1;i++)
	{
		int u,v,w;
		u = i+1;
		v = i;
		//v = rand()%u;
		w = rand()%mod;

		//scanf("%d%d%d",&u,&v,&w);
		//u--;
		//v--;
		
		addedge(u,v,w,i);
		addedge(v,u,w,i);
	}

	DFS(0,-1);

	for (int i = 0;i < n-1;i++)
		a[i] = n-1-i;
	//random_shuffle(a,a+n-1);

	for (int i = 0;i < n-1;i++)
	{
		fflush(stdout);

		int id;
		//scanf("%d",&id);
		//id--;
		id = a[i]-1;

		sp.Select(l[epos[id]],l[epos[id]]);

		int wi = sp.root->c[1]->c[0]->key;
		printf("%d\n",wi);

		sp.Link(epos[id],-1,0);

		int upos = sp.AncestorID(l[epos[id]]);
		int vpos = sp.AncestorID(l[topos[id]]);

		sp.Select(l[upos],r[upos]);
		Node *u = sp.root->c[1]->c[0];

		sp.Select(l[vpos],r[vpos]);
		Node *v = sp.root->c[1]->c[0];

		if (u->size > v->size || (u->size == v->size && u->minid > v->minid))
			swap(u,v);

		u->a = (long long)u->a*wi%mod;
		u->b = (long long)u->b*wi%mod;
		sp.Pushup(u->p),sp.Pushup(u->p->p);

		v->b = (v->b+wi)%mod;
		sp.Pushup(v->p),sp.Pushup(v->p->p);
	}

	return 0;
}
