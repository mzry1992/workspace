#include <iostream>
#include <string.h>
#include <cstdio>
#include <cmath>
using namespace std;

int n;
struct point
{
    double x,y;
}p[500];
bool visit[500][500];

int main()
{
    while (scanf("%d",&n) != EOF)
    {
        for (int i = 1;i <= n;i++)
            scanf("%lf%lf",&p[i].x,&p[i].y);
        memset(visit,false,sizeof(visit));
        double res = 0.0;
        for (int i = 1;i <= n;i++)
        for (int j = 1;j <= n;j++)
        if (i != j)
        if (visit[i][j] == false)
        {
            bool cando = true;
            for (int k = 1;k <= n;k++)
            if (i != k && j != k)
            {
                if ((p[k].x-p[i].x)*(p[j].y-p[k].y) == (p[k].y-p[i].y)*(p[j].x-p[k].x))
                    if (visit[i][k] == true || visit[k][j] == true)
                    {
                        cando = false;
                        break;
                    }
            }
            if (cando == true)
            {
                res += sqrt((p[j].x-p[i].x)*(p[j].x-p[i].x)+(p[j].y-p[i].y)*(p[j].y-p[i].y));
                visit[i][j] = visit[j][i] = true;
            }
        }
        printf("%d\n",(int)res);
    }
}
