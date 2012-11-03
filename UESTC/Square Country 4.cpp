#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const double pi = acos(-1.0);
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
    Point(Point _s,Point _e)
        {
            x = _e.x-_s.x;
            y = _e.y-_s.y;
        }
    void transXY(double B)
        {
            double tx = x,ty = y;
            x = tx*cos(B) - ty*sin(B);
            y = tx*sin(B) + ty*cos(B);
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

double xmult(Point a,Point b)
{
    return a.x*b.y-a.y*b.x;
}

double xmult(Line a,Line b)
{
    return xmult(Point(a.s,a.e),Point(b.s,b.e));
}

bool HalfPlaneIntersectionCmp(Line a,Line b)
{
    if (fabs(a.k-b.k) > eps)    return a.k < b.k;
    return xmult(Point(b.s,a.s),Point(b.s,b.e)) < 0.0;
}

Point LineToLine(Line a,Line b)
{
    Point res = a.s;
    double t = ((a.s.x-b.s.x)*(b.s.y-b.e.y)-(a.s.y-b.s.y)*(b.s.x-b.e.x))/((a.s.x-a.e.x)*(b.s.y-b.e.y)-(a.s.y-a.e.y)*(b.s.x-b.e.x));
    res.x += (a.e.x-a.s.x)*t;
    res.y += (a.e.y-a.s.y)*t;
    return res;
}

void HalfPlaneIntersection(Line line[],int n,Point res[],int& resn)
{
    Line Q[100];
    int tot = n;
    sort(line,line+n,HalfPlaneIntersectionCmp);
    tot = 1;
    for (int i = 1;i < n;i++)
        if (fabs(line[i].k-line[i-1].k) > eps)
            line[tot++] = line[i];
    int head,tail;
    head = 0;
    tail = 1;
    Q[0] = line[0];
    Q[1] = line[1];
    resn = 0;
    for (int i = 2;i < tot;i++)
    {
        if ((fabs(xmult(Q[tail],Q[tail-1])) < eps) || (fabs(xmult(Q[head],Q[head+1])) < eps))   return;
        while (head < tail && xmult(Point(line[i].s,LineToLine(Q[tail],Q[tail-1])),Point(line[i].s,line[i].e)) > eps)
            tail--;
        while (head < tail && xmult(Point(line[i].s,LineToLine(Q[head],Q[head+1])),Point(line[i].s,line[i].e)) > eps)
            head++;
        tail++;
        Q[tail] = line[i];
    }
    while (head < tail && xmult(Point(Q[head].s,LineToLine(Q[tail],Q[tail-1])),Point(Q[head].s,Q[head].e)) > eps)
        tail--;
    while (head < tail && xmult(Point(Q[tail].s,LineToLine(Q[head],Q[head+1])),Point(Q[tail].s,Q[tail].e)) > eps)
        head++;
    if (tail <= head+1) return;
    for (int i = head;i < tail;i++)
        res[resn++] = LineToLine(Q[i],Q[i+1]);
    if (head < tail+1)
        res[resn++] = LineToLine(Q[head],Q[tail]);
}

double CalcArea(Point a,Point b,Point c)    {   return (double)xmult(Point(a,b),Point(a,c))/2.0;}

double CalcArea(Point l[],int n)
{
    if (n < 3) return 0.0;
    double res = 0.0;
    for (int i = 2;i < n;i++)
        res += CalcArea(l[0],l[i-1],l[i]);
    return res;
}

int n;
double a;
char mp[100];
double col[200][200][26];
Point r1[4],r2[4],resp[20];
Line line[20];
int totline,totres;

int main()
{
    scanf("%d%lf",&n,&a);
    a = pi*a/180.0;
    for (int i = 0;i < 4*n;i++)
        for (int j = 0;j < 4*n;j++)
            for (int k = 0;k < 26;k++)
                col[i][j][k] = 0.0;
    for (int i = 0;i < 2*n;i++)
    {
        scanf("%s",mp);
        int len = strlen(mp);
        for (int j = 0;j < 2*n;j++)
            if (mp[j] != '.')
            {
                r1[0] = Point(j-n,n-1-i);
                r1[0].transXY(a);
                r1[1] = Point(j-n+1,n-1-i);
                r1[1].transXY(a);
                r1[2] = Point(j-n+1,n-i);
                r1[2].transXY(a);
                r1[3] = Point(j-n,n-i);
                r1[3].transXY(a);
                int lx,rx,ly,ry;
                lx = floor(min(min(r1[0].x,r1[1].x),min(r1[2].x,r1[3].x)));
                rx = floor(max(max(r1[0].x,r1[1].x),max(r1[2].x,r1[3].x)));
                ly = floor(min(min(r1[0].y,r1[1].y),min(r1[2].y,r1[3].y)));
                ry = floor(max(max(r1[0].y,r1[1].y),max(r1[2].y,r1[3].y)));
                for (int x = lx;x <= rx;x++)
                    for (int y = ly;y <= ry;y++)
                    {
                        r2[0] = Point(x,y);
                        r2[1] = Point(x+1,y);
                        r2[2] = Point(x+1,y+1);
                        r2[3] = Point(x,y+1);
                        totline = 0;
                        for (int i = 0;i < 4;i++)
                            line[totline++] = Line(r1[i],r1[(i+1)%4]);
                        for (int i = 0;i < 4;i++)
                            line[totline++] = Line(r2[i],r2[(i+1)%4]);
                        HalfPlaneIntersection(line,totline,resp,totres);
                        col[2*n-1-y][x+2*n][mp[j]-'a'] += CalcArea(resp,totres);
                    }
            }
    }
    for (int i = 0;i < 4*n;i++)
    {
        for (int j = 0;j < 4*n;j++)
        {
            bool flag = false;
            for (int k = 0;k < 26;k++)
                if (col[i][j][k]-0.5 > 1e-6)
                {
                    printf("%c",'a'+k);
                    flag = true;
                }
            if (flag == false)
                printf(".");
        }
        printf("\n");
    }
}

