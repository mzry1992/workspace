#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct Point
{
	int x,y;
	bool operator < (const Point& b)const
	{
		if (x == b.x)
			return y < b.y;
		return x < b.x;
	}
};

struct Recta
{
	Point a,b;
	Recta(){}
	Recta(Point _a,Point _b)
	{
		a = _a;
		b = _b;
	}
};

Recta seg[1000];
int l,Q;

Recta tree[3000];
int lc[3000],rc[3000],L,tot[3000];

void Build(int pos,Recta now)
{
	if (now.b < now.a)
		swap(now.a,now.b);

	tree[pos] = now;
	int nl = -1;
	for (int i = 0;i < l;i++)
		if (seg[i].a.x == seg[i].b.x)
		{
			if (seg[i].a.x <= now.a.x || seg[i].a.x >= now.b.x)	continue;

			if (seg[i].a.y == now.a.y && seg[i].b.y == now.b.y)
			{
				nl = i;
				break;
			}
		}
		else
		{
			if (seg[i].a.y <= now.a.y || seg[i].a.y >= now.b.y)	continue;

			if (seg[i].a.x == now.a.x && seg[i].b.x == now.b.x)
			{
				nl = i;
				break;
			}
		}

	//printf("pos = %d, now = ((%d,%d),(%d,%d)), nl = %d\n",pos,now.a.x,now.a.y,now.b.x,now.b.y,nl);

	lc[pos] = rc[pos] = -1;
	if (nl == -1)
	{
		tot[pos] = 1;
		return;
	}

	lc[pos] = L++;
	Build(lc[pos],Recta(now.a,seg[nl].b));
	rc[pos] = L++;
	Build(rc[pos],Recta(seg[nl].a,now.b));

	tot[pos] = tot[lc[pos]]+tot[rc[pos]];
}

int cnt,ret[3000],tcnt,tret[3000];
bool check(int pos,Point p)
{
	return (p.x > tree[pos].a.x && p.x < tree[pos].b.x &&
		p.y > tree[pos].a.y && p.y < tree[pos].b.y);
}

void Find(int pos,Point p)
{
	ret[cnt++] = pos;
	if (lc[pos] == -1)
	{
		ret[cnt++] = -1;
		return;
	}
	if (check(lc[pos],p))
		Find(lc[pos],p);
	else
		Find(rc[pos],p);
}

int main()
{
	Recta full;
	while (scanf("%d%d%d%d",&full.a.x,&full.a.y,&full.b.x,&full.b.y) != EOF)
	{
		scanf("%d%d",&l,&Q);
		for (int i = 0;i < l;i++)
		{
			scanf("%d%d%d%d",&seg[i].a.x,&seg[i].a.y,&seg[i].b.x,&seg[i].b.y);
			if (seg[i].b < seg[i].a)
				swap(seg[i].a,seg[i].b);
		}

		L = 1;
		Build(0,full);

		for (int q = 0;q < Q;q++)
		{
			Point a,b;
			scanf("%d%d%d%d",&a.x,&a.y,&b.x,&b.y);

			cnt = 0;
			Find(0,a);
			tcnt = cnt;
			for (int i = 0;i < cnt;i++)
				tret[i] = ret[i];

//			for (int i = 0;i < cnt;i++)
//				printf("%d ",ret[i]);
//			printf("\n");

			cnt = 0;
			Find(0,b);

			ret[cnt-1] = -2;
//			for (int i = 0;i < cnt;i++)
//				printf("%d ",ret[i]);
//			printf("\n");

			int lca;
			for (int i = 0;i < cnt && i < tcnt;i++)
				if (tret[i] != ret[i])
				{
					lca = ret[i-1];
					break;
				}
//			printf("lca = %d\n",lca);

			printf("%d\n",l+2-tot[lca]);
		}
	}
    return 0;
}

