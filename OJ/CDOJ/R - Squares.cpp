#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <set>
#define Point pair<int,int>
#define x first
#define y second
using namespace std;

set<Point> gird;
Point p[2000],p0,p1;
int n,res,dx,dy;

int main()
{
    while (scanf("%d",&n) != EOF)
    {
        if (n == 0) break;
        gird.clear();
        for (int i = 0;i < n;i++)
        {
            scanf("%d%d",&p[i].x,&p[i].y);
            gird.insert(p[i]);
        }
        res = 0;
        for (int i = 0;i < n;i++)
            for (int j = i+1;j < n;j++)
                {
                    if ((p[i].x+p[j].x+p[i].y-p[j].y)%2 != 0)   continue;
                    if ((p[i].y+p[j].y+p[j].x-p[i].x)%2 != 0)   continue;
                    if ((p[i].x+p[j].x-p[i].y+p[j].y)%2 != 0)   continue;
                    if ((p[i].y+p[j].y-p[j].x+p[i].x)%2 != 0)   continue;
                    p0 = make_pair((p[i].x+p[j].x+p[i].y-p[j].y)/2,(p[i].y+p[j].y+p[j].x-p[i].x)/2);
                    p1 = make_pair((p[i].x+p[j].x-p[i].y+p[j].y)/2,(p[i].y+p[j].y-p[j].x+p[i].x)/2);
                    if (gird.find(p0) != gird.end())
                        if (gird.find(p1) != gird.end())
                            res++;
                }
        printf("%d\n",res/2);
    }
}
