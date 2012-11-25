#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <map>
#include <vector>
using namespace std;

struct point
{
    long long x,y;
    point(){}
    point(long long _x,long long _y)
    {
        x = _x;
        y = _y;
    }
    bool operator < (const point& b)const
    {
        if (x == b.x)   return y < b.y;
        return x < b.x;
    }
    point operator - (const point& b)const
    {
        return point(x-b.x,y-b.y);
    }
    int operator * (const point& b)const
    {
        return x*b.y-y*b.x;
    }
};
struct line
{
    point s,e;
    line(){}
    line(point _s,point _e)
    {
        s = _s;
        e = _e;
    }
};

map<point, vector<point > > mp;
vector<point> tp;
int n,r,w,m,tx,ty;
line s[10];
point res[10];
int totres;

void insert(int x,int y)
{
    point now = point(x,y);
    mp[point(x/r,y/r)].push_back(now);
}

long long dis2(point a,point b)
{
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}

bool check(line a,line b)
{
    return (max(a.s.x,a.e.x) >= min(b.s.x,b.e.x) &&
            max(b.s.x,b.e.x) >= min(a.s.x,a.e.x) &&
            max(a.s.y,a.e.y) >= min(b.s.y,b.e.y) &&
            max(b.s.y,b.e.y) >= min(a.s.y,a.e.y) &&
            ((b.s-a.s)*(a.e-a.s))*((b.e-a.s)*(a.e-a.s)) <= 0 &&
            ((a.s-b.s)*(b.e-b.s))*((a.e-b.s)*(b.e-b.s)) <= 0);
}

bool check(point a,point b)
{
    long long rr = 2*r;

    for (int i = 0;i < w;i++)
        if (check(s[i],line(a,b)) == true)
            rr -= 2;
    //cout << b.x << ' ' << b.y << ' ' << a.x << ' ' << a.y << ' ' << rr << endl;

    if (dis2(a,b) > rr*rr)  return false;
    return true;
}

int main()
{
	int totcas;
	scanf("%d",&totcas);
	for (int cas = 1;cas <= totcas;cas++)
	{
	    mp.clear();
        scanf("%d%d%d%d",&n,&r,&w,&m);
        for (int i = 0;i < n;i++)
        {
            scanf("%d%d",&tx,&ty);
            tx *= 2;
            ty *= 2;
            insert(tx,ty);
        }
        for (int i = 0;i < w;i++)
        {
            scanf("%d%d%d%d",&s[i].s.x,&s[i].s.y,&s[i].e.x,&s[i].e.y);
            s[i].s.x *= 2;
            s[i].s.y *= 2;
            s[i].e.x *= 2;
            s[i].e.y *= 2;
        }
        for (int i = 0;i < m;i++)
        {
            scanf("%d%d",&tx,&ty);
            tx *= 2;
            ty *= 2;
            totres = 0;
            for (int dx = -3;dx <= 3;dx++)
                for (int dy = -3;dy <= 3;dy++)
                {
                    tp = mp[point(tx/r+dx,ty/r+dy)];
                    for (int j = 0;j < tp.size();j++)
                        if (check(tp[j],point(tx,ty)) == true)
                            res[totres++] = tp[j];
                }
            //printf("\n");
            sort(res,res+totres);
            printf("%d",totres);
            for (int j = 0;j < totres;j++)
                printf(" (%lld,%lld)",res[j].x/2,res[j].y/2);
            printf("\n");
        }
	}
	return 0;
}
