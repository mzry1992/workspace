#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 100000;
struct Point
{
    int x,y;
};
int n;
Point p[MAXN];

bool cmpx(Point a,Point b)
{
    if (a.x == b.x) return a.y < b.y;
    return a.x < b.x;
}

bool cmpy(Point a,Point b)
{
    if (a.y == b.y) return a.x < b.x;
    return a.y < b.y;
}

int main()
{
    while (true)
    {
        scanf("%d",&n);
        if (n == 0) break;
        for (int i = 0;i < n;i++)
            scanf("%d%d",&p[i].x,&p[i].y);
        long long res = 0;
        sort(p,p+n,cmpx);
        for (int i = 0;i < n;)
            if (i == 0 || p[i].x != p[i-1].x)
            {
                int j;
                for (j = i;j < n && p[j].x == p[i].x;j += 2)
                    res += abs(p[j].x-p[j+1].x)+abs(p[j].y-p[j+1].y);
                i = j;
            }
        sort(p,p+n,cmpy);
        for (int i = 0;i < n;)
            if (i == 0 || p[i].y != p[i-1].y)
            {
                int j;
                for (j = i;j < n && p[j].y == p[i].y;j += 2)
                    res += abs(p[j].x-p[j+1].x)+abs(p[j].y-p[j+1].y);
                i = j;
            }
        printf("The length of the fence will be %I64d units.\n",res);
    }
	return 0;
}
