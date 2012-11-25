#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n,m,a[50][50],b[3],c[3],d[50],e[50],f[3];

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    while (scanf("%d%d",&n,&m) != EOF)
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                scanf("%d",&a[i][j]);
        for (int i = 0; i < n; i++)
        {
            d[i] = 0;
            for (int j = 0; j < m; j++)
                d[i] += a[i][j];
            if (i > 0)
                d[i] += d[i-1];
        }
        for (int i = 0; i < m; i++)
        {
            e[i] = 0;
            for (int j = 0; j < n; j++)
                e[i] += a[j][i];
            if (i > 0)
                e[i] += e[i-1];
        }
        for (int i = 0; i < 3; i++)
            scanf("%d",&b[i]);
        sort(b,b+3);
        int res = 0;
        do
        {
            f[0] = b[0];
            for (int i = 1; i < 3; i++)
                f[i] = f[i-1]+b[i];
            for (int i = 0; i < n; i++)
                for (int j = i+1; j < n-1; j++)
                    if (d[i] == f[0] && d[j] == f[1] && d[n-1] == f[2])
                        res++;
            for (int i = 0; i < m; i++)
                for (int j = i+1; j < m-1; j++)
                    if (e[i] == f[0] && e[j] == f[1] && e[m-1] == f[2])
                        res++;
        }
        while (next_permutation(b,b+3));
        printf("%d\n",res);
    }
    return 0;
}
