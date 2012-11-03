#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

const double pi = acos(-1.0);

struct Point
{
	double x,y;
	Point(){}
	Point(double _x,double _y)
	{
		x = _x;
		y = _y;
	}
	Point operator +(const Point& b)const
	{
		return Point(x+b.x,y+b.y);
	}
	Point operator -(const Point& b)const
	{
		return Point(x-b.x,y-b.y);
	}
	Point operator /(const double& b)const
	{
		return Point(x/b,y/b);
	}
	void transXY(double B)
	{
		double tx = x,ty = y;
		x = tx*cos(B)-ty*sin(B);
		y = tx*sin(B)+ty*cos(B);
	}
};

Point p[3];

int main()
{
	for (int i = 0;i < 3;i++)
		scanf("%lf%lf",&p[i].x,&p[i].y);
	Point center = (p[0]+p[1]+p[2])/3;
	for (int i = 0;i < 3;i++)
	{
		Point pa = (center+p[i])/2;
		printf("%.10f %.10f\n",pa.x,pa.y);

		Point v = pa-p[i];
		v.transXY(pi/3);
		pa = p[i]+v;
//		printf("%.10f %.10f\n",pa.x,pa.y);
	}

	for (int i = 0;i < 3;i++)
	{
		Point pa = (center+p[i])/2;
//		printf("%.10f %.10f\n",pa.x,pa.y);

		Point v = pa-p[i];
		v.transXY(pi/3);
		pa = p[i]+v;
		printf("%.10f %.10f\n",pa.x,pa.y);
	}
    return 0;
}

