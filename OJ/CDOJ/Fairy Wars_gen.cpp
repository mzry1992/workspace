#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

const int step[9][2] = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,0},{0,1},{1,-1},{1,0},{1,1}};
int n,r,l,x,y,nx,ny;
struct Point
{
    int x,y,id;
};
Point p[50000];
map<pair<int,int>,vector<Point > > g;
vector<Point >::iterator it,op,ed;
pair<int,int> gird;
vector<Point > tmp;

void build(int w)
{
    g.clear();
    for (int i = 0; i < n; i++)
        g[make_pair(p[i].x/w,p[i].y/w)].push_back(p[i]);
}

int f[50001],fa,fb;

int findf(int x)
{
    if (f[x] != x)  f[x] = findf(f[x]);
    return f[x];
}

int main()
{
    freopen("fairy wars.in","w",stdout);
    for (int ft = 1;ft <= 1;ft++)
    {
        n = 50000;
        r = 20000;
        l = 20000;
        printf("%d %d %d\n",n,r,l);
        l = l/2;
        for (int i = 0; i < n; i++)
        {
            p[i].x = rand()%20000-10000;
            p[i].y = rand()%20000-10000;
            printf("%d %d\n",p[i].x,p[i].y);
        }
        x = rand()%20000-10000;
        y = rand()%20000-10000;
        printf("%d %d\n",x,y);
    }
    return 0;
}

