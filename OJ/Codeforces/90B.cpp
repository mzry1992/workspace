#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

int n,k,a[100],q,know[100][100],b[100],tb;
bool used[100];

int main()
{
    while (scanf("%d%d",&n,&k) != EOF)
    {
        for (int i = 0;i < n;i++)
            scanf("%d",&a[i]);
        scanf("%d",&q);
        memset(used,false,sizeof(used));
        double resmin,resmax,resnow;
        resmin = 1e100;
        resmax = 0;
        for (int i = 0;i < q;i++)
        {
            for (int j = 0;j < n/k;j++)
            {
                scanf("%d",&know[i][j]);
                know[i][j]--;
                used[know[i][j]] = true;
            }
            resnow = 0;
            for (int j = 0;j < n/k;j++)
                resnow += a[know[i][j]];
            resmin = min(resmin,resnow);
            resmax = max(resmax,resnow);
        }
        tb = 0;
        for (int i = 0;i < n;i++)
            if (used[i] == false)
                b[tb++] = a[i];
        sort(b,b+tb);
        if (tb >= n/k)
        {
            resnow = 0;
            for (int i = 0;i < n/k;i++)
                resnow += b[i];
            resmin = min(resmin,resnow);
            resmax = max(resmax,resnow);
            resnow = 0;
            for (int i = 0;i < n/k;i++)
                resnow += b[tb-1-i];
            resmin = min(resmin,resnow);
            resmax = max(resmax,resnow);
        }
        resmin /= (double)(n/k);
        resmax /= (double)(n/k);
        printf("%.10f %.10f\n",resmin,resmax);
    }
    return 0;
}
