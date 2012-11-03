#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const double pi = acos(-1.0);
const double eps = 1e-12;
const int MaxN = 50000;
struct Point
{
	double x,y;
	Point(){}
	Point(double _x,double _y)
	{
		x = _x,y = _y;
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
		s = _s,e = _e;
	}
	Point operator& (const Line& b)const
	{
		Point res = s;
		double t = ((s-b.s)*(b.s-b.e))/((s-e)*(b.s-b.e));
		res.x += (e.x-s.x)*t;
		res.y += (e.y-s.y)*t;
		return res;
	}
};

bool GScmp(Point a,Point b)
{
	if (fabs(a.x-b.x) < eps)
		return a.y < b.y-eps;
	return a.x < b.x-eps;
}

bool conLine(Point p[],int n)
{
	for (int i = 2;i < n;i++)
		if (fabs((p[1]-p[0])*(p[i]-p[0])) > eps)
			return false;
	return true;
}

void GS(Point p[],int n,Point res[],int &resn)
{
	resn = 0;
	int top = 0;
	sort(p,p+n,GScmp);

	if (n < 2)
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
		if (resn < 2 || (res[resn-1]-res[resn-2])*(p[i]-res[resn-1]) > eps)
			res[resn++] = p[i++];
		else
			--resn;
	top = resn-1;
	for (int i = n-2;i >= 0;)
		if (resn < top+2 || (res[resn-1]-res[resn-2])*(p[i]-res[resn-1]) > eps)
			res[resn++] = p[i--];
		else
			--resn;
	resn--;
}

double theta[MaxN];
void Gettheta(Point p[],int n)
{
	for (int i = 0;i < n;i++)
	{
		Point v = p[(i+1)%n]-p[i];
		theta[i] = atan2(v.y,v.x);
	}
	for (int i = 1;i < n;i++)
		if (theta[i-1] > theta[i]+eps)
			theta[i] += 2*pi;
}
int cmp(double a,double b)
{
	if (fabs(a-b) < eps)	return 0;
	if (a < b)	return -1;
	return 1;
}
int Gao(int la,int lb,Line line,Point p[],int n)
{
	if (la > lb)
		lb += n;
	int l = la,r = lb,mid;
	while (l < r)
	{
		mid = l+r+1>>1;
		if (cmp((line.e-line.s)*(p[la%n]-line.s),0)*cmp((line.e-line.s)*(p[mid%n]-line.s),0) > 0)
			l = mid;
		else
			r = mid-1;
	}
	//printf("l = (%.3f, %.3f) -> (%.3f, %.3f)\n",line.s.x,line.s.y,line.e.x,line.e.y);
	//printf("la = (%.3f, %.3f), lb = (%.3f %.3f), l = (%.3f %.3f)\n",p[la%n].x,p[la%n].y,p[lb%n].x,p[lb%n].y,p[l%n].x,p[l%n].y);
	return l%n;
}
int Gao(int la,int lb,int dir,Point s,Point p[],int n)
{
	if (la > lb)
		lb += n;
	if (la == lb)	return la;

	int l = la+1,r = lb,mid;

	while (l < r)
	{
		mid = l+r+1>>1;

		int ret = cmp((p[mid%n]-s)*(p[(mid-1)%n]-s),0);
		if (dir*ret < 0)
			l = mid;
		else if (dir*ret > 0)
			r = mid-1;
		else
		{
			if (dir == 1)
				l = mid;
			else
				r = mid-1;
		}
	}

	int ret = cmp((p[l%n]-s)*(p[(l-1)%n]-s),0);
	if (dir*ret < 0)
		return l%n;
	else if (dir*ret > 0)
		return (l-1)%n;
	else
	{
		if (dir == 1)
			return l%n;
		else
			return (l-1)%n;
	}
}
//Gettheta(p,n) first!
void Calc(Point s,Point p[],int n,int& pl,int& pr)
{
	Line l = Line(s,p[0]);
	Point v = l.e-l.s;
	double tnow = atan2(v.y,v.x);
	if (tnow < theta[0]-eps)	tnow += 2*pi;
	int tpl = lower_bound(theta,theta+n,tnow)-theta;
	tnow = atan2(-v.y,-v.x);
	if (tnow < theta[0]-eps)	tnow += 2*pi;
	int tpr = lower_bound(theta,theta+n,tnow)-theta;

	pl = tpl = tpl%n;
	pr = tpr = tpr%n;

	//printf("--------------------\n");
	//printf("pl =%d (%.3f, %.3f) pr =%d (%.3f, %.3f)\n",pl,p[pl].x,p[pl].y,pr,p[pr].x,p[pr].y);
	int px = Gao(pr,pl,l,p,n);
	//printf("px =%d (%.3f, %.3f) -> (%.3f, %.3f)\n",px,p[px].x,p[px].y,p[(px+1)%n].x,p[(px+1)%n].y);
	//pr -> px
	//px -> pl

	pl = Gao(tpr,px,1,s,p,n);
	pr = Gao(px+1,tpl,-1,s,p,n);

}

double r;

double cut(Point a,Point b)
{
	Point tv = b-a;
	if (fabs(tv.x) < eps && fabs(tv.y) < eps)	return -1;

	Line tl = Line(Point(0,0),Point(tv.y,-tv.x));
	Point near = Line(a,b)&tl;
	double A,B,C;
	A = near&near;
	C = r;
	B = C*C-A;
	double tvl = tv&tv;
	double tmp = sqrt(B/tvl);
	Point pa = Point(near.x+tmp*tv.x,near.y+tmp*tv.y);
	Point pb = Point(near.x-tmp*tv.x,near.y-tmp*tv.y);

	double theta0 = atan2(pa.y,pa.x);
	double theta1 = atan2(pb.y,pb.x);
	if (theta1 < theta0)
		theta1 += 2*pi;
	double res = 0.5*r*r*(theta1-theta0);
	res -= 0.5*(pa*pb);
	//printf("a = (%.3f, %.3f), b = (%.3f, %.3f), res = %.8f\n",a.x,a.y,b.x,b.y,res);
	return res;
}

double solve(Point pa[],int n,Point pb[],int m)
{
	Gettheta(pb,m);

	double res = 0;
	for (int i = 0;i < n;i++)
	{
		int pl,pr;
		Calc(pa[i],pb,m,pl,pr);

		//pa[i]->pb[pr]; pa[i+1]->pa[i]

		//pa[i]->pb[pl]; pa[i-1]->pa[i]
		
		//printf("pa[i] = (%.2f %.2f)\n",pa[i].x,pa[i].y);
		//printf("pl = (%.2f %.2f), pr = (%.2f %.2f)\n",pb[pl].x,pb[pl].y,pb[pr].x,pb[pr].y);

		if ((pb[pr]-pa[i])*(pa[(i+1)%n]-pa[i]) <= 0 &&
			(pb[pr]-pa[i])*(pa[(i+n-1)%n]-pa[i]) <= 0)
		{
			//pa[i] -> pb[pr]
			res = max(res,cut(pa[i],pb[pr]));
		}

		if ((pa[(i+1)%n]-pa[i])*(pb[pl]-pa[i]) <= 0 &&
			(pa[(i+1)%n]-pa[i])*(pb[pr]-pa[i]) <= 0)
		{
			//pa[(i+1)%n] -> pa[i]
			res = max(res,cut(pa[(i+1)%n],pa[i]));
		}

		if ((pb[pl]-pa[i])*(pa[(i+n-1)%n]-pa[i]) >= 0 &&
			(pb[pl]-pa[i])*(pa[(i+1)%n]-pa[i]) >= 0)
		{
			//pb[pl] -> pa[i]
			res = max(res,cut(pb[pl],pa[i]));
		}

		if ((pa[(i+n-1)%n]-pa[i])*(pb[pl]-pa[i]) >= 0 &&
			(pa[(i+n-1)%n]-pa[i])*(pb[pr]-pa[i]) >= 0)
		{
			//pa[i] -> pa[(i+n-1)%n]
			res = max(res,cut(pa[i],pa[(i+n-1)%n]));
		}

		Point pp = Point(pa[i].x-pa[i].y,pa[i].y+pa[i].x);
		//printf("%.3f %.3f | %.3f %.3f\n",pa[i].x,pa[i].y,pp.x,pp.y);
		if ((pp-pa[i])*(pa[(i+n-1)%n]-pa[i]) <= 0 &&
			(pp-pa[i])*(pa[(i+1)%n]-pa[i]) <= 0 &&
			(pp-pa[i])*(pb[pl]-pa[i]) >= 0 &&
			(pp-pa[i])*(pb[pr]-pa[i]) >= 0)
		{
			//pa[i]->pp
			res = max(res,cut(pa[i],pp));
		}
	}
	return res;
}

int n,m,tn;
Point pa[MaxN],pb[MaxN],tp[MaxN];

int main()
{
	//freopen("input","r",stdin);

	scanf("%lf",&r);

	scanf("%d",&tn);
	for (int i = 0;i < tn;i++)
		scanf("%lf%lf",&tp[i].x,&tp[i].y);
	GS(tp,tn,pa,n);

	scanf("%d",&tn);
	for (int i = 0;i < tn;i++)
		scanf("%lf%lf",&tp[i].x,&tp[i].y);
	GS(tp,tn,pb,m);

	//for (int i = 0;i < n;i++)
	//	printf("(%.2f, %.2f) ",pa[i].x,pa[i].y);
	//printf("\n");
	//for (int i = 0;i < m;i++)
	//	printf("(%.2f, %.2f) ",pb[i].x,pb[i].y);
	//printf("\n");

	double ans1 = solve(pa,n,pb,m);
	double ans2 = solve(pb,m,pa,n);

	printf("%.10f %.10f\n",pi*r*r-ans1,ans2);
	return 0;
}
