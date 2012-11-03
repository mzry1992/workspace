#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <vector>
#include <cmath>
#define Point pair<double,double>
using namespace std;

const int step[9][2] = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,0},{0,1},{1,-1},{1,0},{1,1}};
int n,m,x,y,nx,ny;
map<pair<int,int>,vector<Point > > g;
vector<Point > tmp;
Point p[10000],tmp[100000];
double tx,ty,ans,nowans;
vector<Point >::iterator it,op,ed;
pair<int,int> gird;
bool flag;

double dis(Point p0,Point p1)
{
    return sqrt((p0.first-p1.first)*(p0.first-p1.first)+
                (p0.second-p1.second)*(p0.second-p1.second));
}

void build(int n,double w)
{
    g.clear();
    for (int i = 0; i < n; i++)
        g[make_pair((int)floor(p[i].first/w),(int)floor(p[i].second/w))].push_back(p[i]);
}

int main()
{
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
        scanf("%lf%lf",&tmp[i].first,&tmp[i].second);
    return 0;
}
