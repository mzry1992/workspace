//指针
#include "iostream"
#include "cstdio"
#include "cstring"
#include "algorithm"
using namespace std;

struct SplayNode
{
	int sz;
	SplayNode *ch[2],*fa;

	inline void Pushdown()
	{

	}

	inline void Pushup()
	{
		sz = ch[0]->sz+ch[1]->sz+1;
	}

};

struct SplayTree
{
	SplayNode *root;

	inline void Zig(SplayNode* x)
	{
		SplayNode *y = x->fa,*z = y->fa,*b;
		z->Pushdown();y->Pushdown();x->Pushdown();
		z->ch[y == z->ch[1]] = x;
		bool F = x == y->ch[1];
		b = x->ch[!F];
		b->fa = y;y->fa = x;x->fa = z;
		x->ch[!F] = y;y->ch[F] = b;
		y->Pushup();x->Pushup();
	}

	inline void ZigZig(SplayNode* x)
	{
		SplayNode *y = x->fa,*z = y->fa,*zz = z->fa,*b,*c;
		zz->ch[z == zz->ch[1]] = x;
		bool F = x == y->ch[1];
		b = x->ch[!F];c = y->ch[!F];
		c->fa = z;z->fa = y;y->fa = x;x->fa = zz;
		x->ch[!F] = y;y->ch[!F] = z;z->ch[F] = c;
		b->fa = y;y->ch[F] = b;
		z->Pushup();y->Pushup();x->Pushup();
	}

	inline void Splay(SplayNode* x,SplayNode* goal)
	{
		if (x == goal)	return;
	}
};

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}