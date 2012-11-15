#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

int n,m;
struct point
{
    int x,y,z;
};
point so[10100],cr[10100],v;
struct dpoint
{
    double x,y,z;
};

bool online(point a,point b,point c)
{
    dpoint d,e;
    d.x = (double)a.x-(double)b.x;
    d.y = (double)a.y-(double)b.y;
    d.z = (double)a.z-(double)b.z;
    e.x = (double)c.x;
    e.y = (double)c.y;
    e.z = (double)c.z;
    if (d.x*e.x+d.y*e.y+d.z*e.z >= -EPS)
        return true;
    return false;
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d%d",&n,&m);
        cnt = 0;
        for (int i = 1;i <= n;i++)
            scanf("%d%d%d",&so[i].x,&so[i].y,&so[i].z);
        for (int i = 1;i <= m;i++)
            scanf("%d%d%d",&cr[i].x,&cr[i].y,&cr[i].z);
        scanf("%d%d%d",&v.x,&v.y,&v.z);
        int cnt = 0;
        for (int i = 1;i <= n;i++)
        for (int j = 1;j <= m;j++)
        {

        }
    }
}
