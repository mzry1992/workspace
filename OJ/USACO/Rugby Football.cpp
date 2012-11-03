#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n,t,l;
int v[12000];

bool cmp(int a,int b)
{
    return a > b;
}

int main()
{
    int T;
    scanf("%d",&T);
    for (int ft = 1;ft <= T;ft++)
    {
        scanf("%d%d%d",&n,&t,&l);
        for (int i = 1;i <= n;i++)
            scanf("%d",&v[i]);
        sort(v+1,v+1+n,cmp);
        double res = 0.0;
        int dist = l;
        bool reach = false;
        for (int i = 1;i <= n;i++)
        {
            if (dist > v[i]*t)
            {
                dist -= v[i]*t;
                res += t;
            }
            else
            {
                res += (double)dist/(double)v[i];
                reach = true;
                break;
            }
        }
        if (reach == false)
            printf("-1\n");
        else
            printf("%.2lf\n",res);
    }
}
