#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <vector>
#include <cmath>
#include <algorithm>
#define Point pair<double,double>
using namespace std;

const int step[9][2] = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,0},{0,1},{1,-1},{1,0},{1,1}};
int n,x,y,nx,ny;
map<pair<int,int>,vector<Point > > g;
vector<Point > tmp;
Point p[20000];
double tx,ty,ans,nowans;
vector<Point >::iterator it,op,ed;
pair<int,int> gird;
bool flag;

double Dis(Point p0,Point p1)
{
    return sqrt((p0.first-p1.first)*(p0.first-p1.first)+
                (p0.second-p1.second)*(p0.second-p1.second));
}

double CalcDis(Point p0,Point p1,Point p2)
{
    return Dis(p0,p1)+Dis(p0,p2)+Dis(p1,p2);
}

void build(int n,double w)
{
    g.clear();
    for (int i = 0;i < n;i++)
        g[make_pair((int)floor(p[i].first/w),(int)floor(p[i].second/w))].push_back(p[i]);
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d",&n);
        for (int i = 0;i < n;i++)
        {
            scanf("%lf%lf",&tx,&ty);
            p[i] = make_pair(tx,ty);
        }
        random_shuffle(p,p+n);
        ans = CalcDis(p[0],p[1],p[2]);
        build(3,ans/2.0);
        for (int i = 3;i < n;i++)
        {
            x = (int)floor(2.0*p[i].first/ans);
            y = (int)floor(2.0*p[i].second/ans);
            tmp.clear();
            for (int k = 0;k < 9;k++)
            {
                nx = x+step[k][0];
                ny = y+step[k][1];
                gird = make_pair(nx,ny);
                if (g.find(gird) != g.end())
                {
                    op = g[gird].begin();
                    ed = g[gird].end();
                    for (it = op;it != ed;it++)
                        tmp.push_back(*it);
                }
            }
            flag = false;
            for (int j = 0;j < tmp.size();j++)
                for (int k = j+1;k < tmp.size();k++)
                {
                    nowans = CalcDis(p[i],tmp[j],tmp[k]);
                    if (nowans < ans)
                    {
                        ans = nowans;
                        flag = true;
                    }
                }
            if (flag == true)
                build(i+1,ans/2.0);
            else
                g[make_pair((int)floor(2.0*p[i].first/ans),(int)floor(2.0*p[i].second/ans))].push_back(p[i]);
        }
        printf("%.3f\n",ans);
    }
}
