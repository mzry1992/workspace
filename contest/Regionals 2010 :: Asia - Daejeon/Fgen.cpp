#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int g[30][30];

int main()
{
    freopen("F.in","w",stdout);
    int totcas = 20;
    printf("%d\n",totcas);
    for (int cas = 1;cas <= totcas;cas++)
    {
        int n = 4;
        memset(g,-1,sizeof(g));
        for (int i = 0;i < 100;i++)
        {
            int u = rand()%n;
            int v = rand()%n;
            int w = rand()%10+1;
            g[u][v] = g[v][u] = w;
        }
        int m = 0;
        for (int i = 0;i < n;i++)
            for (int j = i+1;j < n;j++)
                if (g[i][j] > 0)
                    m++;
        printf("%d %d\n",n,m);
        for (int i = 0;i < n;i++)
            for (int j = i+1;j < n;j++)
                if (g[i][j] > 0)
                    printf("%d %d %d\n",i+1,j+1,g[i][j]);
    }
    return 0;
}

