/*公用 - 头文件*/
#include <cstdio>
#include <iostream>
#include <cstring>

/*必要 - 头文件*/
#include <cmath>

using namespace std;

/*定义 - 宏*/

/*定义 - 常量*/
const double EPS = 1e-8;
const double PI = acos(-1.0);

/*定义 - 类型*/
struct Point
{
    double x,y;
    Point(){}
    Point(double _x,double _y)
        {
            x = _x; y = _y;
        }
    Point(Point pa,Point pb)
        {
            x = pb.x-pa.x;
            y = pb.y-pa.y;
        }
    Point operator + (const Point& p) const
        {
            return Point(x+p.x,y+p.y);
        }
    Point operator - (const Point& p) const
        {
            return Point(x-p.x,y-p.y);
        }
	double operator * (const Point& p) const
        {
            return x*p.y-y*p.x;
        }
	double operator & (const Point& p) const
        {
            return x*p.x+y*p.y;
        }
    double norm() const
        {
            return sqrt(x*x+y*y);
        }
    double Xmult(Point a,Point b)
        {
            return Point(a.x-x,a.y-y)*Point(b.x-x,b.y-y);
        }
};
struct Line
{
    Point s,e;
    double k;
    Line(){}
    Line(Point _s,Point _e)
        {
            s = _s;
            e = _e;
            k = atan2(e.y-s.y,e.x-s.x);
        }
};

/*函数 - 基本关系*/
inline bool CompareTo(double a,double b) //double的比较函数
{
    if (fabs(a-b) < EPS)    return 0;
    else if (a-b > EPS)     return 1;
    else return -1;
}

inline bool On(Point a,Point b) //点在点上
{
    return (CompareTo(Point(a,b).norm(),0) == 0);
}

inline bool On(Point a,Line b,int type)
{
    if (type == 0)  return (CompareTo(Point(b.s,a)*Point(b.e,a),0) == 0);
}

/*函数 - 距离*/
inline double Distance(Point a,Point b) //点到点
{
    return Point(a,b).norm();
}

inline double Distance(Point a,Line b,int type) //点到线，type = 0表示点到直线，type = 1表示点到线段
{
    if (type == 0)  return fabs(a.Xmult(b.s,b.e))/Point(b.s,b.e).norm();
    Point t = a;
    t.x += b.s.y-b.e.y;
    t.y += b.e.x-b.s.x;
    if (b.s.Xmult(t,a)*b.e.Xmult(t,a) > EPS)
        return min(Distance(a,b.s),Distance(a,b.e));
    return fabs(a.Xmult(b.e,b.s))/Distance(b.s,b.e);
}

inline double Distance(Line a,Line b,int type) //线到线，type = 0表示直线到直线，type = 1表示直线到线段，type = 2表示线段到线段
{
}

/*测试部分*/
int main()
{
    cout << Distance(Point(0,0),Line(Point(10,10),Point(20,10)),0) << endl;
    cout << Distance(Point(0,0),Line(Point(10,10),Point(20,10)),1) << endl;
    cout << On(Point(1,1),Point(1,1+EPS)) << ' ' << On(Point(1,1),Point(100,100)) << endl;
    cout << On(Point(2,2),Line(Point(0,0),Point(1,2)),0) << endl;
    return 0;
}
