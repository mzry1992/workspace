#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n,m,k,r;
struct rectangle
{
    int x1,y1,x2,y2;
}obs[60],tre[10];
int tx[200],ty[200],nx,ny;

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d%d",&m,&n);
        scanf("%d",&k);
        for (int i = 1;i <= k;i++)
            scanf("%d%d%d%d",&obs[i].x1,&obs[i].y1,&obs[i].x2,&obs[i].y2);
        scanf("%d",&r);
        for (int i = 1;i <= r;i++)
            scanf("%d%d%d%d",&tre[i].x1,&tre[i].y1,&tre[i].x2,&tre[i].y2);
        nx = ny = 0;
        for (int i = 1;i <= k;i++)
        {

        }
    }
}
