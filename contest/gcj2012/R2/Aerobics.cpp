#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <set>
using namespace std;

struct Circ
{
    int r,id;
    Circ() {}
    Circ(int _r,int _id)
    {
        r = _r;
        id = _id;
    }
    bool operator < (const Circ& b) const
    {
        if (r == b.r)   return id < b.id;
        return r > b.r;
    }
};

const int MAXN = 2000;
Circ c[MAXN];
int n,X,Y;

struct Point
{
    int x,y;
    Point() {}
    Point(int _x,int _y)
    {
        x = _x;
        y = _y;
    }
    bool operator < (const Point& b) const
    {
        if (x == b.x)   return y < b.y;
        return x < b.x;
    }
    bool operator == (const Point& b) const
    {
        return x == b.x && y == b.y;
    }
};
struct Rect
{
    Point s,t;
    Rect() {}
    Rect(Point _s,Point _t)
    {
        s = _s;
        t = _t;
    }
    int area()
    {
        int w,h;
        w = t.x-s.x;
        h = t.y-s.y;
        if (s.x == 0)
            w += t.x-s.x;
        if (s.x == X)
            w += t.x-s.x;
        if (s.y == 0)
            h += t.y-s.y;
        if (s.y == Y)
            h += t.y-s.y;
        return min(w,h);
    }
    bool operator < (const Rect& b) const
    {
        int wa,ha;
        wa = t.x-s.x;
        ha = t.y-s.y;
        if (s.x == 0)
            wa += t.x-s.x;
        if (s.x == X)
            wa += t.x-s.x;
        if (s.y == 0)
            ha += t.y-s.y;
        if (s.y == Y)
            ha += t.y-s.y;
        wa =  min(wa,ha);
        int wb,hb;
        wb = b.t.x-b.s.x;
        hb = b.t.y-b.s.y;
        if (b.s.x == 0)
            wb += b.t.x-b.s.x;
        if (b.s.x == X)
            wb += b.t.x-b.s.x;
        if (b.s.y == 0)
            hb += b.t.y-b.s.y;
        if (b.s.y == Y)
            hb += b.t.y-b.s.y;
        wb =  min(wb,hb);
        if (wa == wb)
        {
            if (s == b.s)   return t < b.t;
            return s < b.s;
        }
        return wa > wb;
    }
};

set<Rect> mp;
set<Rect>::iterator it;
Point res[MAXN];

int main()
{
    freopen("B-large.in","r",stdin);
    freopen("B-large.out","w",stdout);
    int totcas;
    scanf("%d",&totcas);
    for (int cas = 1; cas <= totcas; cas++)
    {
        scanf("%d%d%d",&n,&X,&Y);
        for (int i = 0; i < n; i++)
        {
            int r;
            scanf("%d",&r);
            c[i] = Circ(r,i);
        }
        sort(c,c+n);
        mp.clear();
        mp.insert(Rect(Point(0,0),Point(X,Y)));
        for (int i = 0; i < n; i++)
        {
            Rect tmp = *mp.begin();
            mp.erase(tmp);
            int rx,ry;
            if (tmp.s.x == 0)
                rx = tmp.s.x;
            else
                rx = tmp.s.x+c[i].r;

            if (tmp.s.y == 0)
                ry = tmp.s.y;
            else
                ry = tmp.s.y+c[i].r;

            res[c[i].id] = Point(rx,ry);

            if (tmp.s.x == 0)
                rx = tmp.s.x+c[i].r;
            else
                rx = tmp.s.x+2*c[i].r;

            if (tmp.s.y == 0)
                ry = tmp.s.y+c[i].r;
            else
                ry = tmp.s.y+2*c[i].r;

            mp.insert(Rect(Point(rx,tmp.s.y),Point(tmp.t.x,ry)));
            mp.insert(Rect(Point(tmp.s.x,ry),Point(rx,tmp.t.y)));
            mp.insert(Rect(Point(rx,ry),tmp.t));
        }

        printf("Case #%d:",cas);
        for (int i = 0;i < n;i++)
            printf(" %d %d",res[i].x,res[i].y);
        printf("\n");
    }
    return 0;
}
