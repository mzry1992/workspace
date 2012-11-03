#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int Inf = 0x3f3f3f3f;
const int MaxN = 500005;

struct Node
{
	int size,key;

	bool rev,same;
	int sum,lsum,rsum,maxsum,lazy;

	Node *c[2];
	Node *p;
}mem[MaxN],*cur,*nil;

int emp[MaxN],totemp;

Node *newNode(int v,Node *p)
{
	cur = mem+emp[--totemp];
	cur->c[0] = cur->c[1] = nil, cur->p = p;
	cur->size = 1;
	cur->key = v;

	cur->rev = cur->same = false;
	cur->sum = cur->lsum = cur->rsum = cur->maxsum = cur->key;

	return cur;
}

void Init()
{
	for (int i = 0;i < MaxN;i++)
		emp[i] = i;
	totemp = MaxN;
	cur = mem+emp[--totemp];
	nil = newNode(0,cur);
	nil->size = 0;
}

void Recycle(Node *p)
{
	if (p == nil)	return;
	Recycle(p->c[0]), Recycle(p->c[1]);
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
		Pushdown(x); Pushdown(x->c[0]); Pushdown(x->c[1]);
		x->size = x->c[0]->size+x->c[1]->size+1;

		x->sum = x->c[0]->sum+x->c[1]->sum+x->key;
		x->lsum = max(x->c[0]->lsum,x->c[0]->sum+x->key+max(0,x->c[1]->lsum));
		x->rsum = max(x->c[1]->rsum,x->c[1]->sum+x->key+max(0,x->c[0]->rsum));
		x->maxsum = max(max(x->c[0]->maxsum,x->c[1]->maxsum),x->key+max(0,x->c[0]->rsum)+max(0,x->c[1]->lsum));
	}
	void Pushdown(Node *x)
	{
		if (x == nil)	return;
		if (x->rev)
		{
			x->rev = 0;
			x->c[0]->rev ^= 1;
			x->c[1]->rev ^= 1;
			swap(x->c[0],x->c[1]);
			
			swap(x->lsum,x->rsum);
		}
		if (x->same)
		{
			x->same = false;
			x->key = x->lazy;
			x->sum = x->key*x->size;
			x->lsum = x->rsum = x->maxsum = max(x->key,x->sum);
			x->c[0]->same = true, x->c[0]->lazy = x->key;
			x->c[1]->same = true, x->c[1]->lazy = x->key;
		}
	}
	void Rotate(Node *x,int f)
	{
		if (x == nil)	return;
		Node *y = x->p;
		y->c[f^1] = x->c[f],x->p = y->p;
		if (x->c[f] != nil)
			x->c[f]->p = y;
		if (y->p != nil)
			y->p->c[y->p->c[1] == y] = x;
		x->c[f] = y,y->p = x;
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
	void Select(int k, Node *f)
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
		Select(l,nil), Select(r+2,root);
	}
	Node *Make_tree(int a[],int l,int r,Node *p)
	{
		if (l > r)	return nil;
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
	void Remove(int l,int r)
	{
		Select(l,r);
		Recycle(root->c[1]->c[0]);
		root->c[1]->c[0] = nil;
		Splay(root->c[1],nil);
	}
};

SplayTree sp;
int a[MaxN];
char buf[20];

int main()
{
	int totcas;
	scanf("%d",&totcas);
	for (int cas = 1;cas <= totcas;cas++)
	{
		Init();
		sp.Init();
		nil->lsum = nil->rsum = nil->maxsum = -Inf;
		sp.Insert(0);
		sp.Insert(0);

		int n,m;
		scanf("%d%d",&n,&m);
		for (int i = 0;i < n;i++)
			scanf("%d",&a[i]);
		sp.Insert(0,a,n);

		for (int i = 0;i < m;i++)
		{
			int pos,tot,c;
			scanf("%s",buf);
			if (strcmp(buf,"MAKE-SAME") == 0)
			{
				scanf("%d%d%d",&pos,&tot,&c);
				sp.Select(pos-1,pos+tot-2);
				sp.root->c[1]->c[0]->same = true;
				sp.root->c[1]->c[0]->lazy = c;
				sp.Pushup(sp.root->c[1]), sp.Pushup(sp.root);
			}
			else if (strcmp(buf,"INSERT") == 0)
			{
				scanf("%d%d",&pos,&tot);
				for (int i = 0;i < tot;i++)
					scanf("%d",&a[i]);
				sp.Insert(pos,a,tot);
			}
			else if (strcmp(buf,"DELETE") == 0)
			{
				scanf("%d%d",&pos,&tot);
				sp.Remove(pos-1,pos+tot-2);
			}
			else if (strcmp(buf,"REVERSE") == 0)
			{
				scanf("%d%d",&pos,&tot);
				sp.Select(pos-1,pos+tot-2);
				sp.root->c[1]->c[0]->rev ^= 1;
				sp.Pushup(sp.root->c[1]), sp.Pushup(sp.root);
			}
			else if (strcmp(buf,"GET-SUM") == 0)
			{
				scanf("%d%d",&pos,&tot);
				sp.Select(pos-1,pos+tot-2);
				printf("%d\n",sp.root->c[1]->c[0]->sum);
			}
			else if (strcmp(buf,"MAX-SUM") == 0)
			{
				sp.Select(0,sp.root->size-3);
				printf("%d\n",sp.root->c[1]->c[0]->maxsum);
			}
		}
	}
	return 0;
}
