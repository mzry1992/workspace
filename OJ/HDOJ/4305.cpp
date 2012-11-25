#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const int mod = 10007;
int inv[mod];
void getInv()
{
	inv[1] = 1;
	for (int i = 2;i < mod;i++)
		inv[i] = (mod-(mod/i)*inv[mod%i]%mod)%mod;
}

struct Matrix
{
	int a[300][300];

	void clear()
	{
		memset(a,0,sizeof(a));
	}
	int det(int n)
	{
		for (int i = 0;i < n;i++)
			for (int j = 0;j < n;j++)
				a[i][j] = (a[i][j]%mod+mod)%mod;
		int res = 1;
		for (int i = 0;i < n;i++)
		{
			for (int j = i;j < n;j++)
				if (a[j][i] != 0)
				{
					for (int k = i;k < n;k++)
						swap(a[i][k],a[j][k]);
					if (i != j)
						res = (res+mod)%mod;
					break;
				}
			if (a[i][i] == 0)
			{
				res = -1;//不存在
				break;
			}
			for (int j = i+1;j < n;j++)
			{
				int mut = (a[j][i]*inv[a[i][i]])%mod;
				for (int k = i;k < n;k++)
					a[j][k] = (a[j][k]-(a[i][k]*mut)%mod+mod)%mod;
			}
			res = (res*a[i][i])%mod;
		}
		return res;
	}
};

struct Point
{
	int x,y;
	Point(){}
	Point(int _x,int _y)
	{
		x = _x;
		y = _y;
	}
	Point operator -(const Point& b)const
	{
		return Point(x-b.x,y-b.y);
	}
	int operator &(const Point& b)const
	{
		return x*b.x+y*b.y;
	}
};

struct Event
{
	int id,dis;
	double theta;
	bool operator <(const Event& b)const
	{
		if (fabs(theta-b.theta) < 1e-8)
			return dis < b.dis;
		return theta < b.theta;
	}
};

int dist2(Point a,Point b)
{
	return (a-b)&(a-b);
}

Matrix laplacian;
Point p[300];
Event v[300];
int n,R;

int main()
{
	getInv();
	int totcas;
	scanf("%d",&totcas);
	for (int cas = 1;cas <= totcas;cas++)
	{
		scanf("%d%d",&n,&R);
		for (int i = 0;i < n;i++)
			scanf("%d%d",&p[i].x,&p[i].y);

		laplacian.clear();
		for (int i = 0;i < n;i++)
		{
			int tot = 0;
			for (int j = 0;j < n;j++)
				if (i != j)
				{
					v[tot].id = j;
					v[tot].dis = dist2(p[i],p[j]);
					if (v[tot].dis <= R*R)
						v[tot++].theta = atan2(p[j].y-p[i].y,p[j].x-p[i].x);
				}
			sort(v,v+tot);
			for (int j = 0;j < tot;j++)
				if (j == 0 || fabs(v[j].theta-v[j-1].theta) > 1e-8)
				{
					laplacian.a[i][v[j].id] = -1;
					laplacian.a[i][i]++;
				}
		}
		printf("%d\n",laplacian.det(n-1));
	}
	return 0;
}
