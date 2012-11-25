#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

const int dd[5][2] = {{-1,0},{0,0},{1,0},{0,-1},{0,1}};

struct Point
{
    int x,y;
    Point() {}
    Point(int _x,int _y)
    {
        x = _x,y = _y;
    }
    Point operator -(const Point &b)const
    {
        return Point(x-b.x,y-b.y);
    }
    int operator *(const Point &b)const
    {
        return x*b.y-y*b.x;
    }
    int operator &(const Point &b)const
    {
        return x*b.x+y*b.y;
    }
};

struct Line
{
    Point s,e;
    Line() {}
    Line(Point _s,Point _e)
    {
        s = _s,e = _e;
    }
};

bool inter(Line l1,Line l2)
{
    return (max(l1.s.x,l1.e.x) >= min(l2.s.x,l2.e.x) &&
            max(l2.s.x,l2.e.x) >= min(l1.s.x,l1.e.x) &&
            max(l1.s.y,l1.e.y) >= min(l2.s.y,l2.e.y) &&
            max(l2.s.y,l2.e.y) >= min(l1.s.y,l1.e.y) &&
            ((l2.s-l1.s)*(l1.e-l1.s))*((l2.e-l1.s)*(l1.e-l1.s)) <= 0 &&
            ((l1.s-l2.s)*(l2.e-l2.s))*((l1.e-l2.s)*(l2.e-l2.s)) <= 0);
}

Line l[6];
int dist[64][64][31][31];
int n,m,sx,sy,ex,ey,w;

struct node
{
    int x,y,sa,sb;
    node() {}
    node(int _x,int _y,int _sa,int _sb)
    {
        x = _x;
        y = _y;
        sa = _sa;
        sb = _sb;
    }
    int &dis()
    {
        return dist[x][y][sa][sb];
    }
};

node Q[4000000];
int head,tail;

int BFS()
{
    memset(dist,63,sizeof(dist));
    node now,nxt;
    now = node(sx,sy,15,15);

    head = tail = 0;
    Q[tail++] = now;

    now.dis() = 0;

    while (head < tail)
    {
        now = Q[head++];
        if (now.x == ex && now.y == ey && now.sa == 15 && now.sb == 15)
            return now.dis();

        for (int i = 0; i < 5; i++)
        {
            int na = now.sa+dd[i][0];
            int nb = now.sb+dd[i][1];
            if (na < 0 || na > 30 || nb < 0 || nb > 30) continue;

            nxt = node(now.x+na-15,now.y+nb-15,na,nb);
            if (nxt.x < 0 || nxt.x >= n || nxt.y < 0 || nxt.y >= m) continue;
            bool flag = true;
            for (int k = 0; k < w && flag; k++)
                if (inter(l[k],Line(Point(now.x,now.y),Point(nxt.x,nxt.y))))
                    flag = false;
            if (flag == false)  continue;
            if (nxt.dis() > now.dis()+1)
            {
                nxt.dis() = now.dis()+1;
                Q[tail++] = nxt;
            }
        }
    }

    return dist[ex][ey][15][15];
}

int main()
{
    while (scanf("%d%d",&n,&m) != EOF)
    {
        scanf("%d%d%d%d",&sx,&sy,&ex,&ey);
        scanf("%d",&w);
        for (int i = 0; i < w; i++)
            scanf("%d%d%d%d",&l[i].s.x,&l[i].s.y,&l[i].e.x,&l[i].e.y);
        printf("%d\n",BFS());
    }
    return 0;
}

