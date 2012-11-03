#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

struct Point
{
    double x,y;
    Point() {}
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
    double Length()
    {
    	return sqrt(x*x+y*y);
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
	Point operator &(const Line& b)const
	{
		Point res = s;
		double t = ((s-b.s)*(b.s-b.e))/((s-e)*(b.s-b.e));
		res.x += (e.x-s.x)*t;
		res.y += (e.y-s.y)*t;
		return res;
	}
};

double dist(Point a,Point b)
{
	Point tmp = b-a;
	return tmp.Length();
}

Point p[3];

Point InscribedCircle(Point p[3],double& r)
{
	double len[3];
	for (int i = 0;i < 3;i++)
		len[i] = dist(p[i],p[(i+1)%3]);
	double tr = (len[0]+len[1]+len[2])/2;
	r = sqrt((tr-len[0])*(tr-len[1])*(tr-len[2])/tr);
	Line l[2];
	for (int i = 0;i < 2;i++)
	{
		Point v = p[i+1]-p[i];
		Point tv = Point(-v.y,v.x);
		tr = tv.Length();
		tv = Point(tv.x*r/tr,tv.y*r/tr);
		l[i].s = Point(p[i].x+tv.x,p[i].y+tv.y);
		l[i].e = Point(p[i+1].x+tv.x,p[i+1].y+tv.y);
	}
	Point tp = l[0]&l[1];
	//printf("%.2f %.2f r = %2f\n",tp.x,tp.y,r);
	return tp;
}

void calc(Point c0,double r0,Point p,Point mp,double mr,Point& c1,double& c1r)
{
	double l = 0,r = 1,mid;
	Point v = mp-p;

	for (int tim = 0;tim < 50;tim++)
	{
		mid = (l+r)/2;
		c1 = Point(p.x+v.x*mid,p.y+v.y*mid);
		c1r = mid*mr;

		double dis = dist(c0,c1);
		if (r0+c1r > dis)
			r = mid;
		else
			l = mid;
	}
}

int main()
{
    while (true)
    {
        bool end = true;
        for (int i = 0; i < 3; i++)
        {
            scanf("%lf%lf",&p[i].x,&p[i].y);
            if (p[i].x != 0 || p[i].y != 0)
                end = false;
        }
        if (end)	break;
        double mr;
        Point mp = InscribedCircle(p,mr);

		//printf("(%.2f %.2f), %.2f\n",mp.x,mp.y,mr);

        double l = 0,r = 1,mid;
        Point v0 = mp-p[0];

		Point c0,c1,c2;
		double c0r,c1r,c2r;

        for (int tim = 0;tim < 50;tim++)
        {
        	mid = (l+r)/2;
        	c0 = Point(p[0].x+v0.x*mid,p[0].y+v0.y*mid);
			c0r = mid*mr;

        	calc(c0,c0r,p[1],mp,mr,c1,c1r);
        	calc(c0,c0r,p[2],mp,mr,c2,c2r);

//			printf("c0 = (%.2f %.2f), %.2f\n",c0.x,c0.y,c0r);
//			printf("c1 = (%.2f %.2f), %.2f\n",c1.x,c1.y,c1r);
//			printf("c2 = (%.2f %.2f), %.2f\n",c2.x,c2.y,c2r);

        	double dis = dist(c1,c2);
        	if (c1r+c2r > dis)
				l = mid;
			else
				r = mid;
        }

        printf("%.6f %.6f %.6f\n",c0r,c1r,c2r);
    }
    return 0;
}

