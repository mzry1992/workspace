#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <map>
#include <vector>
using namespace std;

struct Point
{
    long long x,y;
    int id;
    bool operator < (const Point& b)const
    {
        if (y == b.y)
            return x < b.x;
        return y < b.y;
    }
};

Point p[100000];
long long ans[100000];
int n;

long long dist2(int a,int b)
{
    return (p[a].x-p[b].x)*(p[a].x-p[b].x)+(p[a].y-p[b].y)*(p[a].y-p[b].y);
}

int main()
{
    int totcas;
    scanf("%d",&totcas);
    while (totcas--)
    {
        scanf("%d",&n);
        for (int i = 0;i < n;i++)
        {
            scanf("%I64d%I64d",&p[i].x,&p[i].y);
            p[i].id = i;
        }
        sort(p,p+n);
        for (int i = 0;i < n;i++)
        {
            long long res = 0x7fffffffffffffffLL;
            for (int j = i-1;j >= 0 && (p[i].y-p[j].y)*(p[i].y-p[j].y) < res;j--)
                res = min(res,dist2(i,j));
            for (int j = i+1;j < n && (p[i].y-p[j].y)*(p[i].y-p[j].y) < res;j++)
                res = min(res,dist2(i,j));
            ans[p[i].id] = res;
        }
        for (int i = 0;i < n;i++)
            printf("%I64d\n",ans[i]);
    }
	return 0;
}
