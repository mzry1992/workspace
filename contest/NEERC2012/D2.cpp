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
    double Length()
    {
        return sqrt(x*x+y*y);
    }
};

double dist(Point a,Point b)
{
    Point tmp = a-b;
    return tmp.Length();
}

Point p[3],xp[100];
double r,cr[3];
int totp;
double AB,AC,BC,theta,fai,a0,a1;
Point lab;

const double pi = acos(-1.0);
const double eps = 1e-10;
int cmp(const double& a,const double& b)
{
    if (fabs(a-b) < eps)	return 0;
    if (a < b)	return -1;
    return 1;
}

void Gao()
{
    if (cmp(dist(p[0],p[1]),2*r) <= 0 &&
            cmp(dist(p[0],p[2]),2*r) <= 0)
    {
        puts("Now we have enough power");
        Point ta = Point((p[0].x+p[1].x)/2.0,(p[0].y+p[1].y)/2.0);
        printf("%.10f %.10f\n",ta.x,ta.y);
        ta = Point((p[0].x+p[2].x)/2.0,(p[0].y+p[2].y)/2.0);
        printf("%.10f %.10f\n",ta.x,ta.y);
        return;
    }

    for (int mid = 0; mid < 3; mid++)
    {
        for (int i = 0; i < 3; i++)
            cr[i] = r;
        cr[mid] *= 2;

        totp = 0;
        for (int i = 0; i < 3; i++)
            for (int j = i+1; j < 3; j++)
            {
                lab = Point(p[j].x-p[i].x,p[j].y-p[i].y);
                AB = lab.Length();
                AC = cr[i];
                BC = cr[j];
                if (cmp(AB+AC,BC) <= 0)	continue;
                if (cmp(AB+BC,AC) <= 0)	continue;

                if (cmp(AB,AC+BC) > 0)	continue;

                theta = atan2(lab.y,lab.x);
                fai = acos((AC*AC+AB*AB-BC*BC)/(2.0*AC*AB));
                a0 = theta-fai;
                if (cmp(a0,-pi) < 0)	a0 += 2*pi;
                a1 = theta+fai;
                if (cmp(a1,pi) > 0)	a1 -= 2*pi;

                xp[totp++] = Point(p[i].x+cr[i]*cos(a0),p[i].y+cr[i]*sin(a0));
                xp[totp++] = Point(p[i].x+cr[i]*cos(a1),p[i].y+cr[i]*sin(a1));
            }

        for (int i = 0; i < totp; i++)
        {
            Point ta = xp[i];
            bool flag = true;
            for (int k = 0; k < 3; k++)
                if (cmp(dist(ta,p[k]),cr[k]) > 0)
                {
                    flag = false;
                    break;
                }
            if (flag)
            {
                puts("Now we have enough power");
                printf("%.10f %.10f\n",ta.x,ta.y);
                ta = Point((ta.x+p[mid].x)/2.0,(ta.y+p[mid].y)/2.0);
                printf("%.10f %.10f\n",ta.x,ta.y);
                return;
            }
        }
    }

    puts("Death");
}

int main()
{
    scanf("%lf",&r);
    for (int i = 0; i < 3; i++)
        scanf("%lf%lf",&p[i].x,&p[i].y);

    Gao();
    return 0;
}

