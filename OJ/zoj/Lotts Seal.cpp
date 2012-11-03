#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

const double eps = 1e-10;
const double pi = acos(-1.0);

int cmp(double a,double b)
{
    if (fabs(a-b) < eps)    return 0;
    if (a < b)  return -1;
    return 1;
}

struct point
{
    double x,y;
    point() {}
    point(double _x,double _y)
    {
        x = (double)_x;
        y = (double)_y;
    }
    void transXY(double B)
    {
        double tx = x,ty = y;
        x = tx*cos(B)-ty*sin(B);
        y = tx*sin(B)+ty*cos(B);
    }
    friend double operator &(const point& a,const point& b)
    {
        return a.x*b.y-a.y*b.x;
    }
    friend point operator -(const point& a,const point& b)
    {
        return point(a.x-b.x,a.y-b.y);
    }
    friend point operator +(const point& a,const point& b)
    {
        return point(a.x+b.x,a.y+b.y);
    }
    friend bool operator < (const point& a,const point& b)
    {
        if (cmp(a.x,b.x) == 0)  return cmp(a.y,b.y) < 0;
        return cmp(a.x,b.x) < 0;
    }
};

point lott;
point img[100010],_img[100010];
int n,_n;
double r,s;

bool conpoint(point p[],int n)
{
    for (int i = 1; i < n; i++)
        if (cmp(p[i].x,p[0].x) != 0 ||
                cmp(p[i].y,p[0].y) != 0)
            return false;
    return true;
}

bool conline(point p[],int n)
{
    for (int i = 2; i < n; i++)
        if (cmp((p[1]-p[0])&(p[i]-p[0]),0)  != 0)   return false;
    return true;
}

void gs(point p[],int n,point res[],int& resn)
{
    resn = 0;
    if (conpoint(p,n))
    {
        res[resn++] = p[0];
        return;
    }
    sort(p,p+n);
    if (conline(p,n))
    {
        res[resn++] = p[0];
        res[resn++] = p[n-1];
        return;
    }
    for (int i = 0; i < n;)
        if (resn < 2 || cmp((res[resn-1]-res[resn-2]&(p[i]-res[resn-1])),0) > 0)
            res[resn++] = p[i++];
        else
            --resn;
    int top = resn-1;
    for (int i = n-2; i >= 0;)
        if (resn < top+2 || cmp((res[resn-1]-res[resn-2])&(p[i]-res[resn-1]),0) > 0)
            res[resn++] = p[i--];
        else
            --resn;
    resn--;
}

point poly[2][3];

bool inpoly(point poly[3],point p)
{
    for (int k = 0; k < 3; k++)
        if (cmp((p-poly[k])&(poly[(k+1)%3]-poly[k]),0) > 0) return false;
    return true;
}

bool inpoly(point poly[2][3],point p[],int n)
{
    for (int i = 0; i < n; i++)
        if (inpoly(poly[0],p[i]) == false &&
                inpoly(poly[1],p[i]) == false)
            return false;
    return true;
}

point hp[6];

bool inpoly(point a,point b)
{
    if (inpoly(poly[0],a) == true && inpoly(poly[0],b) == true) return true;
    if (inpoly(poly[1],a) == true && inpoly(poly[1],b) == true) return true;
    for (int i = 0; i < 6; i++)
        if (cmp((hp[i]-a)&(b-a),0) >= 0)
            return true;
    return false;
}

double calcarea(point p[],int n)
{
    if (n < 3)  return 0;
    double res = 0;
    for (int i = 2; i < n; i++)
        res += (p[i-1]-p[0])&(p[i]-p[0]);
    res /= 2;
    return res;
}

int main()
{
    while (scanf("%lf%lf",&lott.x,&lott.y) != EOF)
    {
        scanf("%d",&_n);
        for (int i = 0; i < _n; i++)
            scanf("%lf%lf",&_img[i].x,&_img[i].y);
        scanf("%lf%lf",&r,&s);
        gs(_img,_n,img,n);

        point _v;
        _v = point(0,sqrt(3)*r);
        for (int i = 0; i < 3; i++)
        {
            poly[0][i] = lott+_v;
            _v.transXY(2*pi/3);
        }
        _v = point(0,-sqrt(3)*r);
        for (int i = 0; i < 3; i++)
        {
            poly[1][i] = lott+_v;
            _v.transXY(2*pi/3);
        }

        _v = point(r,0);
        for (int i = 0; i < 6; i++)
        {
            hp[i] = lott+_v;
            _v.transXY(pi/3);
        }

        bool res = inpoly(poly,img,n);
        if (n > 1)
            for (int i = 0; i < n; i++)
                if (inpoly(img[i],img[(i+1)%n]) == false)
                {
                    res = false;
                    break;
                }
        double s1,s2;
        s1 = calcarea(img,n);
        s2 = 3*sqrt(3)*r*r;
        if (cmp(s2-s1,s) <= 0)  res = false;
        if (res == false)   printf("Failed.\n");
        else printf("Succeeded.\n");
    }
    
    return 0;
}
