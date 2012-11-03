#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct Point
{
    int x,y;
    Point() {}
    Point(int _x,int _y)
    {
        x = _x;
        y = _y;
    }
    Point operator -(const Point& b)const
    {
        return Point(x-b.x,y-b.y);
    }
    int operator *(const Point& b)const
    {
        return x*b.y-y*b.x;
    }
};

struct Line
{
    Point s,e;
    Line() {}
    Line(Point _s,Point _e)
    {
        s = _s;
        e = _e;
    }
};

Point pa[120],pb[120],tp[120];
int n,m,tn;

bool GScmp(Point a,Point b)
{
    if (a.x == b.x)
        return a.y < b.y;
    return a.x < b.x;
}

bool conPoint(Point p[],int n)
{
    for (int i = 1; i < n; i++)
        if (p[i].x != p[0].x || p[i].y != p[0].y)
            return false;
    return true;
}

bool conLine(Point p[],int n)
{
    for (int i = 2; i < n; i++)
        if ((p[i]-p[0])*(p[1]-p[0]) != 0)
            return false;
    return true;
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

    for (int i = 0; i < n;)
        if (resn < 2 || (res[resn-1]-res[resn-2])*(p[i]-res[resn-1]) > 0)
            res[resn++] = p[i++];
        else
            --resn;
    top = resn-1;
    for (int i = n-2; i >= 0;)
        if (resn < top+2 || (res[resn-1]-res[resn-2])*(p[i]-res[resn-1]) > 0)
            res[resn++] = p[i--];
        else
            --resn;
    resn--;
}

void output(Line l1)
{
    //printf("(%d, %d) -> (%d, %d)\n",l1.s.x,l1.s.y,l1.e.x,l1.e.y);
}

int sgn(int a)
{
    return a < 0 ? -1 : a == 0 ? 0 : 1;
}

bool inter(Line l1,Line l2)
{
    return (max(l1.s.x,l1.e.x) >= min(l2.s.x,l2.e.x) &&
            max(l2.s.x,l2.e.x) >= min(l1.s.x,l1.e.x) &&
            max(l1.s.y,l1.e.y) >= min(l2.s.y,l2.e.y) &&
            max(l2.s.y,l2.e.y) >= min(l1.s.y,l1.e.y) &&
            sgn((l2.s-l1.s)*(l1.e-l1.s))*sgn((l2.e-l1.s)*(l1.e-l1.s)) <= 0 &&
            sgn((l1.s-l2.s)*(l2.e-l2.s))*sgn((l1.e-l2.s)*(l2.e-l2.s)) <= 0);
}

bool OnSeg(Point b,Line a)
{
    return ((a.s-b)*(a.e-b) == 0 &&
            (b.x-a.s.x)*(b.x-a.e.x) <= 0 &&
            (b.y-a.s.y)*(b.y-a.e.y) <= 0);
}

// poly的顶点数目要大于等于3
// 返回值为：
// 0  -- 点在poly内
// 1  -- 点在poly边界上
// 2  -- 点在poly外
int inPoly(Point p,Point poly[], int n) // 判断点p是否在简单多边形poly内, 多边形可以是凸的或凹的
{
    int i, count;
    Line ray, side;

    count = 0;
    ray.s    = p;
    ray.e.y  = p.y;
    ray.e.x  = -1;//-INF，注意取值防止越界！

    for (i = 0; i < n; i++)
    {
        side.s = poly[i];
        side.e = poly[(i+1)%n];

        if(OnSeg(p, side))
            return 1;

        // 如果side平行x轴则不作考虑
        if (side.s.y == side.e.y)
            continue;

        if (OnSeg(side.s, ray))
        {
            if (side.s.y > side.e.y) count++;
        }
        else if (OnSeg(side.e, ray))
        {
            if (side.e.y > side.s.y) count++;
        }
        else if (inter(ray, side))
        {
            count++;
        }
    }
    return ((count % 2 == 1) ? 0 : 2);
}

Point NearestPointToLineSeg(Point P, Line L)
{
    Point result;
    double a, b, t;

    a = L.e.x - L.s.x;
    b = L.e.y - L.s.y;
    t = ( (P.x - L.s.x) * a + (P.y - L.s.y) * b ) / (a * a + b * b);

    if (t >= 0 && t <= 1)
    {
        result.x = L.s.x + a * t;
        result.y = L.s.y + b * t;
    }
    else
    {
        if (dist(P,L.s) < dist(P,L.e))
            result = L.s;
        else
            result = L.e;
    }
    return result;
}

//bool inPoly(Point a,Point p[],int n)
//{
//    for (int i = 0; i < n; i++)
//        if ((p[i]-a)*(p[(i+1)%n]-a) < 0)
//            return false;
//    return true;
//}

bool check(Line l,Point p[],int n)
{
    for (int i = 0; i < n; i++)
        if (inter(l,Line(p[i],p[(i+1)%n])))
            return true;
    return false;
}


bool check(Point pa[],int n,Point pb[],int m)
{
    //Point == Point
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (pa[i].x == pb[j].x && pa[i].y == pb[j].y)
                return false;

    //Point on Line
    if (m > 1)
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (OnSeg(pa[i],Line(pb[j],pb[(j+1)%m])))
                    return false;
    }

    //Point in Poly
    if (m > 2)
    {
        for (int i = 0; i < n; i++)
            if (inPoly(pa[i],pb,m) < 2)
                return false;
    }

    //Line -> Line
    if (n > 1 && m > 1)
    {
        for (int i = 0; i < n; i++)
            if (check(Line(pa[i],pa[(i+1)%n]),pb,m))
                return false;
    }
    return true;
}

int main()
{
//	printf("%d\n",inter(Line(Point(200,200),Point(600,600)),Line(Point(500,300),Point(500,100))));
//	printf("%d\n",inter(Line(Point(2,2),Point(6,6)),Line(Point(5,3),Point(5,1))));
    while (true)
    {
        scanf("%d%d",&n,&m);
        if (n == 0 && m == 0)	break;

        tn = n;
        for (int i = 0; i < tn; i++)
            scanf("%d%d",&tp[i].x,&tp[i].y);
        GS(tp,tn,pa,n);

        tn = m;
        for (int i = 0; i < tn; i++)
            scanf("%d%d",&tp[i].x,&tp[i].y);
        GS(tp,tn,pb,m);

//		for (int i = 0;i < n;i++)
//			printf("(%d, %d) ",pa[i].x,pa[i].y);
//		printf("\n");
//		for (int i = 0;i < m;i++)
//			printf("(%d, %d) ",pb[i].x,pb[i].y);
//		printf("\n");

        if (check(pa,n,pb,m) && check(pb,m,pa,n))
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}

