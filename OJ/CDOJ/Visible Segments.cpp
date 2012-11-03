#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <set>
using namespace std;

const double eps = 1e-12;
const double pi = acos(-1.0);

const int MAXN = 100000;
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
    double operator *(const Point& b)const
    {
        return x*b.y-y*b.x;
    }
    double operator &(const Point& b)const
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
        s = _s;
        e = _e;
    }
	Point operator &(const Line& b)const
	{
		Point res = s;
		double t = ((s-b.s)*(b.s-b.e))/((s-e)*(b.s-b.e));
		res.x += (e.x-s.x)*t;
		res.y += (e.y-s.y)*t;
		return res;
	}
};

double Normal(Point a)
{
    return sqrt(a&a);
}

Line l[MAXN];
int n;
bool del[MAXN];

struct Event
{
    double tim,dis;
    int id,typ;
    Event() {}
    Event(double _tim,double _dis,int _id,int _typ)
    {
        tim = _tim;
        dis = _dis;
        id = _id;
        typ = _typ;
    }
    bool operator <(const Event& b)const
    {
        if (fabs(tim-b.tim) < eps)
		{
			if (typ == b.typ)
			{
				if (typ == -1)
					return dis < b.dis;
				else
					return dis > b.dis;
			}
			else
				return typ < b.typ;
		}
		return tim < b.tim;
    }
};
int tote;
Event e[MAXN*4];

Line timenow;
struct Node
{
	int id;
	Node(){}
	Node(int _id)
	{
		id = _id;
	}
	bool operator <(const Node& b)const
	{
		return Normal(l[id]&timenow) < Normal(l[b.id]&timenow)-eps;
	}
};
set<Node> rank;
bool visit[MAXN];

int main()
{
    while (scanf("%d",&n) != EOF)
    {
        for (int i = 0; i < n; i++)
            scanf("%lf%lf%lf%lf",&l[i].s.x,&l[i].s.y,&l[i].e.x,&l[i].e.y);

        tote = 0;
        for (int i = 0; i < n; i++)
        {
            visit[i] = del[i] = false;
            if (fabs(l[i].s*l[i].e) < eps)
            {
                del[i] = true;
				continue;
            }

            double ta = atan2(l[i].s.y,l[i].s.x);
            double tb = atan2(l[i].e.y,l[i].e.x);
            if (ta > tb)
            {
                swap(ta,tb);
                swap(l[i].s,l[i].e);
            }

            if (tb-ta > pi)
            {
				double tx = Normal(l[i]&Line(Point(0,0),Point(-1,0)));
                e[tote++] = Event(-pi,tx,i,-1);
                e[tote++] = Event(pi,tx,i,1);

				swap(ta,tb);
				swap(l[i].s,l[i].e);
            }
			
            e[tote++] = Event(ta,Normal(l[i].s),i,-1);
            e[tote++] = Event(tb,Normal(l[i].e),i,1);
        }

        sort(e,e+tote);
		rank.clear();
		for (int i = 0;i < tote;i++)
		{
			timenow = Line(Point(0,0),Point(cos(e[i].tim),sin(e[i].tim)));
			if (e[i].typ == -1)
				rank.insert(Node(e[i].id));
			else
				rank.erase(Node(e[i].id));
			if (rank.size() > 0)
				visit[rank.begin()->id] = true;
		}

		for (int i = 0;i < n;i++)
			if (visit[i] == true && del[i] == false)
				printf("%d\n",i);
	}
    return 0;
}

