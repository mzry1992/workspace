#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

const double pi = acos(-1.0);
struct Point
{
    double x,y,z;
    Point(){}
    Point(double _x,double _y,double _z)
    {
        x = _x;
        y = _y;
        z = _z;
    }
    Point operator *(const Point &a)const
    {
        return Point(y*a.z-z*a.y,z*a.x-x*a.z,x*a.y-y*a.x);
    }
    double operator &(const Point &a)const
    {
        return x*a.x+y*a.y+z*a.z;
    }
    double length()
    {
        return sqrt(x*x+y*y+z*z);
    }
    void output()
    {
        printf("(%.6f ,%.6f ,%.6f)\n",x,y,z);
    }
};

Point p[3],pa,pb,pc,xa,xb;

int main()
{
	int t;
	scanf("%d",&t);
	for (int ft = 1;ft <= t;ft++)
	{
        for (int i = 0;i < 3;i++)
        {
            double a,b;
            scanf("%lf%lf",&b,&a);
            a += 90;
            a = a/180*pi;
            b = b/180*pi;
            p[i] = Point(sin(a)*cos(b),sin(a)*sin(b),cos(a));
        }
        double res = 0;
        for (int i = 0;i < 3;i++)
        {
            pa = p[(i+2)%3];
            pb = p[i];
            pc = p[(i+1)%3];
            xa = pb*pa;
            xb = pb*pc;
            res += acos((xa&xb)/(xa.length()*xb.length()));
            //cout << res << endl;
            //cout << "=-==========" << endl;
        }
        printf("%.2f\n",res/pi*180);
	}
	return 0;
}
