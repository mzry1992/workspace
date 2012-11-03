#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct Point
{
    int x,y;
};

int n,tx[100],ty[100],nx,ny,cur,res;
Point p[100];
int has[100][100],sum[100][100];

int Count(int x,int y0,int y1)
{
    if (y0 == 0)    return sum[x][y1];
    return sum[x][y1]-sum[x][y0-1];
}

int main()
{
    int ft = 1;
    while (true)
    {
        scanf("%d",&n);
        if (n == 0) break;
        for (int i = 0;i < n;i++)
        {
            scanf("%d%d",&p[i].x,&p[i].y);
            tx[i] = p[i].x;
            ty[i] = p[i].y;
        }
        sort(tx,tx+n);
        sort(ty,ty+n);
        nx = unique(tx,tx+n)-tx;
        ny = unique(ty,ty+n)-ty;
        memset(has,0,sizeof(has));
        for (int i = 0;i < n;i++)
        {
            int *pos = lower_bound(tx,tx+nx,p[i].x);
            p[i].x = (int)(pos-tx);
            pos = lower_bound(ty,ty+ny,p[i].y);
            p[i].y = (int)(pos-ty);
            has[p[i].x][p[i].y]++;
        }
        for (int x0 = 0;x0 < nx;x0++)
        {
            sum[x0][0] = has[x0][0];
            for (int y0 = 1;y0 < ny;y0++)
                sum[x0][y0] = sum[x0][y0-1]+has[x0][y0];
        }
        res = 0;
        for (int y0 = 0;y0 < ny;y0++)
            for (int y1 = y0;y1 < ny;y1++)
                for (int x0 = 0;x0 < nx;x0++)
                {
                    cur = Count(x0,y0,y1);
                    res = max(res,cur);
                    for (int x1 = x0+1;x1 < nx;x1++)
                    {
                        res = max(res,cur+Count(x1,y0,y1));
                        if (y0 != y1)
                            cur += has[x1][y0]+has[x1][y1];
                        else
                            cur += has[x1][y0];
                    }
                }
        printf("Case %d: %d\n",ft++,res);
    }
    return 0;
}
