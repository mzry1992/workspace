#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdio>
using namespace std;

struct Point {
    double x, y;

    Point() {
    }

    Point(double x0, double y0) : x(x0), y(y0) {
    }
};

struct Line {
    Point p1, p2;

    Line() {
    }

    Line(Point p10, Point p20) : p1(p10), p2(p20) {
    }
};

struct Circle {
    Point c;
    double r;

    Circle() {
    }

    Circle(Point _c, double _r) : c(_c), r(_r) {
    }
}c[500];

Point operator+(const Point& a,const Point& b){
	return Point(a.x+b.x,a.y+b.y);
}

Point operator-(const Point& a,const Point& b){
	return Point(a.x-b.x,a.y-b.y);
}

double operator*(Point p1, Point p2){
    return (p1.x * p2.y - p2.x * p1.y);
}

double Norm(Point p){
    return sqrt(p.x * p.x + p.y * p.y);
}

double Distance(Point p1, Point p2)
{
    return sqrt((p1.x - p2.x)*(p1.x - p2.x)+(p1.y - p2.y)*(p1.y - p2.y));
}

double Distance(Point p, Line L)
{
    return ( fabs((p - L.p1) * (L.p2 - L.p1)) / Norm(L.p2 - L.p1));
}

int main(){

    freopen("给趣味赛出的题1的数据.txt","r",stdin);
    freopen("给趣味赛出的题1的数据hypout.txt","w",stdout);
	int n;
	Circle c;
	Line l;
	int ret=0,cnt=1;

	while (scanf("%lf%lf%lf",&c.c.x,&c.c.y,&c.r) != EOF){
	scanf("%d",&n);
	ret = 0;
	for(int i=0;i<n;i++){
		scanf("%lf%lf%lf%lf",&l.p1.x,&l.p1.y,&l.p2.x,&l.p2.y);
		l.p2=l.p1+l.p2;
		if(Distance(c.c,l)<=c.r){
			ret++;
		}
	}
	printf("Case #%d: %d\n",cnt++,ret);
	}
	return 0;
}
