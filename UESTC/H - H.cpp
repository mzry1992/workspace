#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <vector>
#include <cmath>
#include <algorithm>
#define Point pair<double,double>
using namespace std;

const double pi = acos(-1.0);
const int step[9][2] = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,0},{0,1},{1,-1},{1,0},{1,1}};
map<pair<int,int>,vector<Point > > g;
vector<Point > tmp;
double tx,ty,ans,nowans;
vector<Point >::iterator it,op,ed;
pair<int,int> gird;
bool flag;
int n,x,y,nx,ny;
double e,theta;
Point p[16000];

Point Rotate(Point p,double angle)
{
    Point res;
    res.first = p.first*cos(angle)-p.second*sin(angle);
    res.second = p.first*sin(angle)+p.second*cos(angle);
    return res;
}

double Dis(Point p0,Point p1)
{
    return sqrt((p0.first-p1.first)*(p0.first-p1.first)+
                (p0.second-p1.second)*(p0.second-p1.second));
}

void build(int n,double w)
{
    g.clear();
    for (int i = 0;i < n;i++)
        g[make_pair((int)floor(p[i].first/w),(int)floor(p[i].second/w))].push_back(p[i]);
}

int main()
{
    int ft = 0;
    while (true)
    {
        scanf("%d%lf%lf",&n,&e,&theta);
        theta = -(theta/180*pi);
        if (n == 0) break;
        for (int i = 0;i < n;i++)
        {
            scanf("%lf%lf",&p[i].first,&p[i].second);
            p[i] = Rotate(p[i],theta);
            p[i].second = p[i].second/sqrt(1-e*e);
        }
        ft++;
        printf("Case %d:\n",ft);
        random_shuffle(p,p+n);
        ans = Dis(p[0],p[1]);
        build(2,ans);
        for (int i = 2;i < n;i++)
        {
            x = (int)floor(p[i].first/ans);
            y = (int)floor(p[i].second/ans);
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
            {
                nowans = Dis(p[i],tmp[j]);
                if (nowans < ans)
                {
                    ans = nowans;
                    flag = true;
                }
            }
            if (flag == true)
                build(i+1,ans);
            else
                g[make_pair((int)floor(p[i].first/ans),(int)floor(p[i].second/ans))].push_back(p[i]);
        }
        double a,b;
        a = ans/2.0;
        b = a*sqrt(1-e*e);
        ans = pi*a*b;
        printf("%.6f\n",ans);
    }
    return 0;
}
