#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <set>
using namespace std;

const double eps = 1e-12;
const double pi = acos(-1.0);
const double inf = 1e100;
const int MAXN = 5000;
double mp[MAXN][MAXN];

struct Point
{
    long long x,y;
    Point() {}
    Point(int _x,int _y)
    {
        x = _x;
        y = _y;
    }
    Point operator -( const Point & b ) const
    {
        return Point ( x - b .x , y - b . y ) ;
    }
    long long operator *( const Point & b ) const
    {
        return x * b . y - y * b . x ;
    }
    long long operator &( const Point & b ) const
    {
        return x * b . x + y * b . y ;
    }
};

struct Line
{
    Point s,e;
    Line() {}
    Line(Point _s,Point _e)
    {
        s = _s;
            angle = p[i].angle;
            while (pt < top && !dbcmp(p[pt].angle, p[i].angle))
            {
                if (p[pt].st == 1) add(p[pt].id);
                else del(p[pt].id);
                pt++;
            }
            if (K) vst[l[h[1]].id] = true;
            i = pt - 1;
        e = _e;
    }
};

double Dist(Point a,Point b)
{
    return sqrt((double)(a.x-b.x)*(a.x-b.x)+(double)(a.y-b.y)*(a.y-b.y));
}

bool inter(Line l1,Line l2)
{
    return ( max ( l1 . s .x , l1 . e . x ) >= min ( l2 . s .x , l2 . e . x ) &&
             max ( l2 . s .x , l2 . e . x ) >= min ( l1 . s .x , l1 . e . x ) &&
             max ( l1 . s .y , l1 . e . y ) >= min ( l2 . s .y , l2 . e . y ) &&
             max ( l2 . s .y , l2 . e . y ) >= min ( l1 . s .y , l1 . e . y ) &&
             (( l2 .s - l1 . s ) *( l1 .e - l1 . s ) ) *(( l2 .e - l1 . s ) *( l1 .e - l1 . s ) ) < 0 &&
             (( l1 .s - l2 . s ) *( l2 .e - l2 . s ) ) *(( l1 .e - l2 . s ) *( l2 .e - l2 . s ) ) < 0) ;
}

Point s,t,p[MAXN];
int n,m,totp;
int px[50],py[50];

struct Event
{
    double tim;
    int typ,id;

    Event(double _tim,int _typ,int _id)
    {
        tim = _tim;
        typ = _typ;
        id = _id;
    }
    bool operator < (const Event& b)const
    {
        if (fabs(tim-b.tim) < eps)
            return typ < b.typ;
        return tim < b.tim;
    }
};
Event e[MAXN*4];
int tote;

int main()
{
    while (true)
    {
        scanf("%d%d",&n,&m);
        if (n == 0 && m == 0)   break;

        cin >> s.x >> s.y >> t.x >> t.y;

        totp = 0;
        p[totp++] = Point(s.x,s.y);
        p[totp++] = Point(t.x,t.y);

        for (int i = 0; i < 2*n; i++)
            scanf("%d",&px[i]);
        for (int i = 0; i < 2*m; i++)
            scanf("%d",&py[i]);

        for (int i = 1; i < 2*n; i += 2)
            for (int j = 1; j < 2*m; j += 2)
            {
                //(px[i],py[j]) -> (px[i+1],py[j+1])

                p[totp++] = Point(px[i],py[j]);
                p[totp++] = Point(px[i],py[j+1]);

                p[totp++] = Point(px[i],py[j+1]);
                p[totp++] = Point(px[i+1],py[j+1]);

                p[totp++] = Point(px[i],py[j]);
                p[totp++] = Point(px[i+1],py[j]);

                p[totp++] = Point(px[i+1],py[j]);
                p[totp++] = Point(px[i+1],py[j+1]);
            }

        for (int i = 0; i < totp; i++)
            for (int j = 0; j < totp; j++)
                mp[i][j] = inf;
        bool check = true;
        for (int i = 2; i < totp; i += 2)
        {
            mp[i][i+1] = mp[i+1][i] = Dist(p[i],p[i+1]);
            if (inter(Line(p[0],p[1]),Line(p[i],p[i+1])))
                check = false;
        }
        if (check)
            mp[0][1] = mp[1][0] = Dist(p[0],p[1]);

        for (int i = 0; i < totp; i++)
        {
            tote = 0;
            for (int j = 2; j < totp; j += 2)
            {
                //p[j]->p[j+1]
                Point v = p[j]-p[i];
                double ta = atan2(v.y,v.x);
                v = p[j+1]-p[i];
                double tb = atan2(v.y,v.x);

                int ida = j;
                int idb = j+1;

                if (ta > tb-eps)
                {
                    swap(ta,tb);
                    swap(ida,idb);
                }

                e[tote++] = Event(ta,1,ida);
                e[tote++] = Event(tb,-1,idb);

                if (ta-tb > pi)
                {
                    e[tote++] = Event(-pi,1,-1);
                    e[tote++] = Event(pi,-1,-1);
                }
            }

            sort(e,e+tote);

            for (int j = 0;j < tote;j++)
            {

            }
        }

    }
    return 0;
}

