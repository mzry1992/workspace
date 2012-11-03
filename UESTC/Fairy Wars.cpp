#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

int n,r,l;
int x,y;
struct Point
{
    int x,y;
};
struct Rect
{
    int xa,ya,xb,yb;
};
Rect p[50000];

int main()
{
    while (scanf("%d%d%d",&n,&r,&l) != EOF)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d%d",&x,&y);
            p[i].xa = 2*x-l;
            p[i].xb = 2*x+l;
            p[i].ya = 2*y-l;
            p[i].yb = 2*y+l;
        }
        scanf("%d%d",&x,&y);
        x *= 2;
        y *= 2;
    }
    return 0;
}
