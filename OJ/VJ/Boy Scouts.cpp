#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>
using namespace std;

const double eps = 1e-8;

int cmp(double a,double b)
{
    if (fabs(a-b) < eps)    return 0;
    if (a < b)  return -1;
    return 1;
}

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
};

double xmult(Point a,Point b)
{
    return a.x*b.y-a.y*b.x;
}

struct Node
{
    int u,v,dis;
    Node(){}
    Node(int _u,int _v,int _dis)
    {
        u = _u;
        v = _v;
        dis = _dis;
    }
};

int n,res,dis[2][100];
Point p[100],v[100][100];
int can[100][100][100];
queue<Node> Q;
Node now;
bool inq[100][100];

int main()
{
    while (scanf("%d",&n) != EOF)
    {
        for (int i = 0;i < n;i++)
            scanf("%lf%lf",&p[i].x,&p[i].y);
        for (int i = 0;i < n;i++)
            for (int j = 0;j < n;j++)
                v[i][j] = Point(p[i],p[j]);
        memset(can,0,sizeof(can));
        for (int i = 0;i < n;i++)
            for (int j = 0;j < n;j++)
                if (i != j)
                    if (v[i][j].x >= 0)
                    for (int k = 0;k < n;k++)
                        if (i != k && j != k)
                            if (v[j][k].x >= 0)
                            {
                                if (cmp(xmult(v[i][j],v[i][k]),0) > 0)
                                    can[i][j][k] = 1;
                                else
                                    can[i][j][k] = 2;
                            }
        res = 0;
        for (int i = 0;i < n;i++)
        {
            for (int j = 0;j < n;j++)
                dis[0][j] = dis[1][j] = 0;
            memset(inq,false,sizeof(inq));
            for (int j = 0;j < n;j++)
                if (i != j)
                    if (v[i][j].x >= 0 && v[i][j].y < 0)
                    {
                        Q.push(Node(i,j,1));
                        dis[0][j] = 1;
                        inq[i][j] = true;
                    }
            while (!Q.empty())
            {
                now = Q.front();
                Q.pop();
                inq[now.u][now.v] = false;
                for (int j = 0;j < n;j++)
                    if (now.u != j && now.v != j)
                        if (can[now.u][now.v][j] == 1)
                            if (dis[0][j] < now.dis+1)
                            {
                                dis[0][j] = now.dis+1;
                                if (inq[now.v][j] == false)
                                {
                                    Q.push(Node(now.v,j,now.dis+1));
                                    inq[now.v][j] = true;
                                }
                            }
            }
            memset(inq,false,sizeof(inq));
            for (int j = 0;j < n;j++)
                if (i != j)
                    if (v[i][j].x >= 0 && v[i][j].y >= 0)
                    {
                        Q.push(Node(i,j,1));
                        dis[1][j] = 1;
                        inq[i][j] = true;
                    }
            while (!Q.empty())
            {
                now = Q.front();
                Q.pop();
                inq[now.u][now.v] = false;
                for (int j = 0;j < n;j++)
                    if (now.u != j && now.v != j)
                        if (can[now.u][now.v][j] == 2)
                            if (dis[1][j] < now.dis+1)
                            {
                                dis[1][j] = now.dis+1;
                                if (inq[now.v][j] == false)
                                {
                                    Q.push(Node(now.v,j,now.dis+1));
                                    inq[now.v][j] = true;
                                }
                            }
            }
            for (int j = 0;j < n;j++)
            {
                res = max(res,dis[0][j]+dis[1][j]);
                res = max(res,1+dis[0][j]);
                res = max(res,1+dis[1][j]);
            }
        }
        printf("%d\n",res);
    }
    return 0;
}
