#include<stdio.h>
#include<stdlib.h>
#include<cstring>
#include<iostream>
#include<cmath>
using namespace std;
const int LSIZE = 5000;
struct point
	{
	int x, y;
	}P[LSIZE];
struct line
	{
	point p1,p2;
	int l1,l2,dir;
	}L[LSIZE];
int dis(point a,point b)
	{
	return abs(a.x-b.x) + abs(a.y-b.y);
	}
bool inter(line a,line b,point &pt)
	{
	if(a.p1.x == a.p2.x)
		{line tmp = a;a=b;b=tmp;}
	if((a.p1.x-b.p1.x)*(a.p2.x-b.p1.x)<=0 && (b.p1.y-a.p1.y)*(b.p2.y-a.p1.y)<=0)
		{
		pt.x = b.p1.x;
		pt.y = a.p1.y;
		return true;
		}
	return false;
	}
int main()
	{
	freopen("e.in","r",stdin);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&P[i].x,&P[i].y);
	int use = 0;
	int len = 0;
	int ans = 2147483647;
	for(int i=2;i<=n;i++)
		{
		use++;
		L[use].p1 = P[i-1];
		L[use].p2 = P[i];
		L[use].l1 = len;
		L[use].l2 = len =len+dis(P[i],P[i-1]);
		if(P[i-1].x == P[i].x) L[use].dir = 1;
		for(int i=1;i<=use-2;i++)
			{
			point pt;
			if(L[i].dir != L[use].dir)
				if(inter(L[i],L[use],pt))
					{
					int tmp = L[use].l1+dis(pt,L[use].p1)-L[i].l2+dis(pt,L[i].p2);
					ans = min(tmp,ans);
					}
			}
		}
	ans = min(ans,len);
	printf("%d\n",ans);
	return 0;
	}
