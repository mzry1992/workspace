#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct Point
{
    int x,y,id;
    Point(){}
    Point(int _x,int _y)
        {
            x = _x;
            y = _y;
        }
    Point(int _x,int _y,int _id)
        {
            x = _x;
            y = _y;
            id = _id;
        }
    Point(Point _s,Point _e)
        {
            x = _e.x-_s.x;
            y = _e.y-_s.y;
        }
};

int xmult(Point a,Point b)
{
    return a.x*b.y-a.y*b.x;
}

bool grahamScanCmp(Point a,Point b)
{
    if (a.x == b.x) return a.y > b.y;
    return a.x < b.x;
}

Point res[400010];
int resn;
Point p[400010],maxx[20010][2],minx[20010][2];
int n,w;

int grahamScan(Point p[],int n)
{
    resn = 0;
    int top = 0;
    sort(p,p+n,grahamScanCmp);
    int rx = p[n-1].x,lx = p[0].x;
    for (int i = 0;i < n;)
        if (resn < 2 || xmult(Point(res[resn-2],res[resn-1]),Point(res[resn-1],p[i])) > 0)
            res[resn++] = p[i++];
        else
            --resn;
    top = resn-1;
    for (int i = n-2;i >= 0;)
        if (resn < top+2 || xmult(Point(res[resn-2],res[resn-1]),Point(res[resn-1],p[i])) > 0)
            res[resn++] = p[i--];
        else
            --resn;
    resn--;
    int ans = 0,tans;
    for (int i = 0;i < resn;i++)
    {
        for (int x = lx;x <= rx;x++)
        {
            for (int j = 0;j < 2;j++)
                if (res[i].id != minx[x][j].y && minx[x][j].y != -1)
                {
                    tans = (res[i].x-x)*(res[i].x-x)+(res[i].y-minx[x][j].x)*(res[i].y-minx[x][j].x);
                    ans = max(ans,tans);
                    break;
                }
            for (int j = 0;j < 2;j++)
                if (res[i].id != maxx[x][j].y && maxx[x][j].y != -1)
                {
                    tans = (res[i].x-x)*(res[i].x-x)+(res[i].y-maxx[x][j].x)*(res[i].y-maxx[x][j].x);
                    ans = max(ans,tans);
                    break;
                }
        }
    }
    return ans;
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d",&n);
        for (int i = 0;i <= 20000;i++)
        {
            maxx[i][0] = maxx[i][1] = Point(-1,-1);
            minx[i][0] = minx[i][1] = Point(20010,-1);
        }
        int totn = n;
        for (int i = 0;i < n;i++)
        {
            scanf("%d%d%d",&p[i].x,&p[i].y,&w);
            p[i].id = i;
            if (p[i].y+w >= maxx[p[i].x][0].x)
            {
                maxx[p[i].x][1] = maxx[p[i].x][0];
                maxx[p[i].x][0] = Point(p[i].y+w,i);
            }
            else if (p[i].y+w >= maxx[p[i].x][1].x)
                maxx[p[i].x][1] = Point(p[i].y+w,i);
            if (p[i].y+w >= maxx[p[i].x+w][0].x)
            {
                maxx[p[i].x+w][1] = maxx[p[i].x+w][0];
                maxx[p[i].x+w][0] = Point(p[i].y+w,i);
            }
            else if (p[i].y+w >= maxx[p[i].x+w][1].x)
                maxx[p[i].x+w][1] = Point(p[i].y+w,i);
            if (p[i].y <= minx[p[i].x][0].x)
            {
                minx[p[i].x][1] = minx[p[i].x][0];
                minx[p[i].x][0] = Point(p[i].y,i);
            }
            else if (p[i].y <= minx[p[i].x][1].x)
                minx[p[i].x][1] = Point(p[i].y,i);
            if (p[i].y <= minx[p[i].x+w][0].x)
            {
                minx[p[i].x+w][1] = minx[p[i].x+w][0];
                minx[p[i].x+w][0] = Point(p[i].y,i);
            }
            else if (p[i].y <= minx[p[i].x+w][1].x)
                minx[p[i].x+w][1] = Point(p[i].y,i);
            p[totn++] = Point(p[i].x,p[i].y+w,p[i].id);
            p[totn++] = Point(p[i].x+w,p[i].y+w,p[i].id);
            p[totn++] = Point(p[i].x+w,p[i].y,p[i].id);
        }
        printf("%d\n",grahamScan(p,totn));
    }
    return 0;
}
