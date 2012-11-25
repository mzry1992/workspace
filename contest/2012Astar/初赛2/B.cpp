#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int n,k;
double x[1000],y[1000],z[1000],dis[1000][1000];
int f[1000];

int findf(int x)
{
    if (f[x] != x)  f[x] = findf(f[x]);
    return f[x];
}

int main()
{
    while (scanf("%d%d",&n,&k) != EOF)
    {
        for (int i = 0;i < n;i++)
            scanf("%lf%lf%lf",&x[i],&y[i],&z[i]);
        for (int i = 0;i < n;i++)
            for (int j = 0;j < n;j++)
                dis[i][j] = (x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])+(z[i]-z[j])*(z[i]-z[j]);
        double l,r,mid;
        l = 0;
        r = 3;
        int cnt;
        for (int tims = 0;tims < 100;tims++)
        {
            mid = (l+r)/2;
            for (int i = 0;i < n;i++)
                f[i] = i;
            for (int i = 0;i < n;i++)
                for (int j = i+1;j < n;j++)
                    if (dis[i][j] < mid)
                        f[findf(i)] = findf(j);
            cnt = 0;
            for (int i = 0;i < n;i++)
                if (findf(i) == i)
                    cnt++;
            if (cnt >= k)
                l = mid;
            else
                r = mid;
        }
        printf("%.6f\n",l);
    }
	return 0;
}
