#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
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
};

int cmp(double a,double b)
{
    if (fabs(a-b) < eps)    return 0;
    if (a < b)  return -1;
    return 1;
}

int m,n;
int y[1100],lx0[1100],rx0[1100],ly[1100],ry[1100],toty,maxy;
double lx[1100],rx[1100],res;

double getx(double xa,double ya,double xb,double yb,double y)
{
    return xa+(xb-xa)*(y-ya)/(yb-ya);
}

Point CenterOfPolygon(Point poly[],int n)
{
    Point p, p0, p1, p2, p3;
    double m, m0;

    p1 = poly[0];
    p2 = poly[1];
    p.x = p.y = m = 0;
    for (int i = 2; i < n; i++) {
        p3 = poly[i];
        p0.x = (p1.x + p2.x + p3.x) / 3.0;
        p0.y = (p1.y + p2.y + p3.y) / 3.0;
        m0 = p1.x * p2.y + p2.x * p3.y + p3.x * p1.y - p1.y * p2.x - p2.y * p3.x - p3.y * p1.x;
        if (cmp(m + m0,0.0) == 0) {
            m0 += eps;
        }
        p.x = (m * p.x + m0 * p0.x) / (m + m0);
        p.y = (m * p.y + m0 * p0.y) / (m + m0);
        m = m + m0;
        p2 = p3;
    }
    return p;
}

Point poly[1100],cent;
int polysize;

bool check(int pos)
{
    polysize = 0;
    for (int i = pos;i >= 0;i--)
        poly[polysize++] = Point(lx[i],y[i]);
    for (int i = 0;i <= pos;i++)
        poly[polysize++] = Point(rx[i],y[i]);
    cent = CenterOfPolygon(poly,polysize);
    if (cmp(cent.x,lx[0]) >= 0 && cmp(cent.x,rx[0]) <= 0)   return true;
    return false;
}

bool check2(double hi)
{
    polysize = 0;
    int pos = toty-1;
    for (int i = 1;i < toty;i++)
        if (cmp(1.0*y[i-1],hi) <= 0 && cmp(hi,1.0*y[i]) <= 0)
        {
            pos = i;
            break;
        }
    poly[polysize++] = Point(getx(1.0*lx[pos-1],1.0*y[pos-1],1.0*lx[pos],1.0*y[pos],hi),hi);
    for (int i = pos-1;i >= 0;i--)
        poly[polysize++] = Point(lx[i],y[i]);
    for (int i = 0;i <= pos-1;i++)
        poly[polysize++] = Point(rx[i],y[i]);
    poly[polysize++] = Point(getx(1.0*rx[pos-1],1.0*y[pos-1],1.0*rx[pos],1.0*y[pos],hi),hi);
    cent = CenterOfPolygon(poly,polysize);
    if (cmp(cent.x,lx[0]) >= 0 && cmp(cent.x,rx[0]) <= 0)   return true;
    return false;
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d%d",&n,&m);
        for (int i = 0;i < n;i++)
        {
            scanf("%d%d",&lx0[i],&ly[i]);
            y[i] = ly[i];
        }
        for (int i = 0;i < m;i++)
        {
            scanf("%d%d",&rx0[i],&ry[i]);
            y[n+i] = ry[i];
        }
        sort(y,y+n+m);
        toty = unique(y,y+n+m)-y;
        maxy = min(ly[n-1],ry[m-1]);
        for (int i = 0;i < toty;i++)
            if (y[i] > maxy)
            {
                toty = i;
                break;
            }
        lx[0] = lx0[0];
        rx[0] = rx0[0];
        y[0] = ly[0];
        for (int i = 1;i < toty;i++)
        {
            for (int j = 1;j < n;j++)
                if (ly[j] >= y[i] && ly[j-1] < y[i])
                    lx[i] = getx(1.0*lx0[j-1],1.0*ly[j-1],1.0*lx0[j],1.0*ly[j],1.0*y[i]);
            for (int j = 0;j < m;j++)
                if (ry[j] >= y[i] && ry[j-1] < y[i])
                    rx[i] = getx(1.0*rx0[j-1],1.0*ry[j-1],1.0*rx0[j],1.0*ry[j],1.0*y[i]);
        }
        //for (int i = 0;i < toty;i++)
        //    cout << y[i] << ' ' << lx[i] << ' ' << rx[i] << endl;
        res = 0.0;
        for (int i = 1;i < toty;i++)
        {
            if (check(i) == false)
            {
                //cout << i << endl;
                double l,r,mid;
                l = 1.0*y[i-1];
                r = 1.0*y[i];
                while (fabs(l-r) > 1e-4)
                {
                    mid = (l+r)/2.0;
                    //cout << l << ' ' << r << ' ' << mid << endl;
                    if (check2(mid) == true)
                        l = mid;
                    else
                        r = mid;
                }
                res = l;
                break;
            }
            else
                res = y[i];
        }
        printf("%.3f\n",res);
    }
    return 0;
}
