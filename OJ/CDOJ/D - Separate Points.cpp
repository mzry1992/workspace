#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

struct Point
{
    int x,y;
}a[120],b[120];
int n,m;

inline int cross(struct Point a,struct Point b)
{
    return a.x*b.y-a.y*b.x;
}

inline int is_left(Point a,Point b,Point c)
{
    Point p1,p2;
    p1.x = b.x-a.x;
    p1.y = b.y-a.y;
    p2.x = c.x-b.x;
    p2.y = c.y-b.y;
    return cross(p1,p2);
}

double dist(Point a,Point b)
{
    return sqrt((double)((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)));
}

int main()
{
    while (true)
    {
        scanf("%d%d",&n,&m);
        if (n == 0 && m == 0)   break;
        for (int i = 0;i < n;i++)  scanf("%d%d",&a[i].x,&a[i].y);
        for (int i = 0;i < m;i++)  scanf("%d%d",&b[i].x,&b[i].y);
        bool flag = false;
        for (int i = 0;i < n;i++)
            for (int j = 0;j < m;j++)
            {
                bool tflag = true;
                for (int k = 0;k < n;k++)
                {
                    if (is_left(a[i],b[j],a[k]) < 0)    tflag = false;
                    else if (is_left(a[i],b[j],a[k]) == 0)
                        if (fabs(dist(a[k],a[i])+dist(a[i],b[j])-dist(a[k],b[j])) > 1e-8)   tflag = false;
                }
                for (int k = 0;k < m;k++)
                {
                    if (is_left(a[i],b[j],b[k]) > 0)    tflag = false;
                    else if (is_left(a[i],b[j],b[k]) == 0)
                        if (fabs(dist(b[k],b[j])+dist(a[i],b[j])-dist(b[k],a[i])) > 1e-8)   tflag = false;
                }
                if (tflag == true)  flag = true;
            }
        if (flag == true)   printf("YES\n");
        else printf("NO\n");
    }
}
