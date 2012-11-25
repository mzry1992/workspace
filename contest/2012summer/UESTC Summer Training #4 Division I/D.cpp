#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

struct Point
{
    double x,y;
    Point(){}
    Point(double _x,double _y)
    {
        x = _x;
        y = _y;
    }
    Point operator - (const Point& b) const
    {
        return Point(x-b.x,y-b.y);
    }
    double operator * (const Point& b) const
    {
        return x*b.y-y*b.x;
    }
    double operator & (const Point& b) const
    {
        return x*b.x+y*b.y;
    }
};

double r;

int main()
{

	return 0;
}
