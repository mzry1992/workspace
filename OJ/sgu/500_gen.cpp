#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const double eps = 1e-8;

struct Point
{
	double x,y;
	Point(){}
	Point(double _x,double _y)
	{
		x = _x;
		y = _y;
	}
	Point operator -(const Point& b)const
	{
		return Point(x-b.x,y-b.y);
	}
	double operator *(const Point& b)const
	{
		return x*b.y-y*b.x;
	}
	double operator &(const Point& b)const
	{
		return x*b.x+y*b.y;
	}
};

struct Line
{
	Point s,e;
	Line(){}
	Line(Point _s,Point _e)
	{
		s = _s;
		e = _e;
	}
};

double Norm(Point p)
{
	return sqrt(p&p);
}

Point getPoint(int r,Line l)
{
	while (true)
	{
		Point p = Point(rand()%(2*r+1)-r,rand()%(2*r+1)-r);
		if (Norm(p) >= 0.9*r)
			continue;

		if ((p-l.s)*(l.e-l.s) > 0)	continue;

		return p;
	}
}

bool conPoint(Point p[],int n)
{
	for (int i = 1;i < n;i++)
		if (p[i].x != p[0].x || p[i].y != p[0].y)
			return false;
	return true;
}

bool conLine(Point p[],int n)
{
	for (int i = 2;i < n;i++)
		if ((p[i]-p[0])*(p[1]-p[0]) != 0)
			return false;
	return true;
}

bool GScmp(Point a,Point b)
{
	if (fabs(a.x-b.x) < eps)
		return a.y < b.y-eps;
	return a.x < b.x-eps;
}

void GS(Point p[],int n,Point res[],int &resn)
{
	resn = 0;
	int top = 0;
	sort(p,p+n,GScmp);
	if (conPoint(p,n))
	{
		res[resn++] = p[0];
		return;
	}
	if (conLine(p,n))
	{
		res[resn++] = p[0];
		res[resn++] = p[n-1];
		return;
	}
	for (int i = 0;i < n;)
		if (resn < 2 ||
				(res[resn-1]-res[resn-2])*(p[i]-res[resn-1]) > 0)
			res[resn++] = p[i++];
		else
			--resn;
	top = resn-1;
	for (int i = n-2;i >= 0;)
		if (resn < top+2 || 
				(res[resn-1]-res[resn-2])*(p[i]-res[resn-1]) > 0)
			res[resn++] = p[i--];
		else
			--resn;
	resn--;
}

Point tmp[100000],op[100000];
void getPoly(int r,Line l)
{
	int n = rand()%50000+1;
	for (int i = 0;i < n;i++)
		tmp[i] = getPoint(r,l);
	int tn = n;
	GS(tmp,tn,op,n);
	printf("%d\n",n);
	for (int i = 0;i < n;i++)
		printf("%.0f %.0f\n",op[i].x,op[i].y);
}

int main()
{
	srand(time(0));
	for (int cas = 1;cas <= 1;cas++)
	{
		int r = 1000000000;
		
		printf("%d\n",r);

		Point vp = getPoint(r,Line(Point(1,1),Point(0,1)));
		getPoly(r,Line(Point(0,0),vp));
		getPoly(r,Line(vp,Point(0,0)));
	}
	printf("0 0\n");
	return 0;
}
