#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;

const int MaxN = 100000;
struct Point
{
	int x,y,r;
	int id;
	bool del;
};

int cmpTyp;
bool cmp(const Point& a,const Point& b)
{
	if (cmpTyp == 0)
		return a.x < b.x;
	else
		return a.y < b.y;
}

int cnt[MaxN];
bool Div[MaxN];
int minX[MaxN],minY[MaxN],maxX[MaxN],maxY[MaxN];
void BuildKD(int l,int r,Point p[])
{
	if (l > r)	return;
	int mid = l+r>>1;
	cmpTyp = 0;
	minX[mid] = min_element(p+l,p+r+1,cmp)->x;
	maxX[mid] = max_element(p+l,p+r+1,cmp)->x;
	cmpTyp = 1;
	minY[mid] = min_element(p+l,p+r+1,cmp)->y;
	maxY[mid] = max_element(p+l,p+r+1,cmp)->y;

	cnt[mid] = r-l+1;
	cmpTyp = Div[mid] = (maxX[mid]-minX[mid] < maxY[mid]-minY[mid]);
	nth_element(p+l,p+mid,p+r+1,cmp);
	BuildKD(l,mid-1,p);
	BuildKD(mid+1,r,p);
}

queue<int> Q;
int Find(int l,int r,Point a,Point p[])
{
	if (l > r)	return 0;
	int mid = l+r>>1;
	if (cnt[mid] == 0)	return 0;
	
	if (maxX[mid] < a.x-a.r ||
			minX[mid] > a.x+a.r ||
			maxY[mid] < a.y-a.r ||
			minY[mid] > a.y+a.r)
		return 0;

	int totdel = 0;

	if (p[mid].del == false)
		if (abs(p[mid].x-a.x) <= a.r && abs(p[mid].y-a.y) <= a.r)
		{
			p[mid].del = true;
			Q.push(p[mid].id);
			totdel++;
		}

	totdel += Find(l,mid-1,a,p);
	totdel += Find(mid+1,r,a,p);

	cnt[mid] -= totdel;

	return totdel;
}

Point p[MaxN],tp[MaxN];
int n;

int main()
{
	int cas = 1;
	while (true)
	{
		scanf("%d",&n);
		if (n == 0)	break;
	
		for (int i = 0;i < n;i++)
		{
			p[i].id = i;
			int tx,ty;
			scanf("%d%d%d",&tx,&ty,&p[i].r);
			p[i].x = tx-ty;
			p[i].y = tx+ty;
			p[i].del = false;
			tp[i] = p[i];
		}
		BuildKD(0,n-1,tp);

		printf("Case #%d:\n",cas++);
		int q;
		scanf("%d",&q);
		for (int i = 0;i < q;i++)
		{
			int id;
			scanf("%d",&id);
			int res = 0;
			id--;
			Q.push(id);
			while (!Q.empty())
			{
				int now = Q.front();
				Q.pop();
				if (p[now].del == true)	continue;
				p[now].del = true;
				res += Find(0,n-1,p[now],tp);
			}
			printf("%d\n",res);
		}
	}
	return 0;
}
