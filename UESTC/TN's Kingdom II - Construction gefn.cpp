#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

struct Point
{
    int x,y;
    friend bool operator < (const Point& a,const Point& b)
    {
        if (a.x == b.x) return a.y < b.y;
        return a.x < b.x;
    }
};

Point p[100000];

int main()
{
    freopen("in.txt","w",stdout);
    srand(time(0));
    int n = 8;
    int maxxy = 50000;
    /*for (int i = 0;i < n;i++)
    {
        p[i].x = rand()%maxxy;
        p[i].y = rand()%maxxy;
    }

    sort(p,p+n);

    int tn = n;
    n = 1;
    for (int i = 1; i < tn; i++)
        if (p[i].x != p[n-1].x ||
            p[i].y != p[n-1].y)
                p[n++] = p[i];

    printf("%d\n",n);
    for (int i = 0;i < n;i++)
        printf("%d %d\n",p[i].x,p[i].y);
    return 0;*/

    int tx,ty;
    tx = 0;
    ty = 0;
    printf("%d\n",n);
    for (int i = 0;i < n;i++)
    {
        printf("%d %d\n",tx,ty);
        int x = rand()%2;
        int y = rand()%2+1;
        tx += x;
        if (x > 0)  ty = y;
        else
            ty += y*100;
    }
    return 0;
}

