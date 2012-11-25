#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int n,m;
char cmp[20];

const int mod = 100000007;
int f[10000001];
int typ[20],val[20];

int main()
{
    freopen("F.in","r",stdin);
    freopen("F.out","w",stdout);
    while (scanf("%d%d",&n,&m),n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%*s%s%*s%d",cmp,&val[i]);
            if (strcmp(cmp,"less") == 0)
                typ[i] = 0;
            else
            {
                typ[i] = 1;
                m -= val[i];
                val[i] = 0;
            }
        }

        if (m < 0)
        {
            puts("0");
            continue;
        }
        for (int i = 0; i <= m; i++)
            f[i] = 1;
        for (int i = 0; i < n; i++)
        {
            int x = val[i];
            if (typ[i] == 0)
            {
                // < x
                for (int j = m; j >= x; j--)
                {
                    f[j] = (f[j]-f[j-x]);
                    if (f[j] < 0)   f[j] += mod;
                }
                for (int j = 1; j <= m; j++)
                {
                    f[j] += f[j-1];
                    if (f[j] >= mod)    f[j] -= mod;
                }
            }
            else
            {
                // > x
                for (int j = m; j > x; j--)
                    f[j] = f[j-x-1];
                for (int j = x; j >= 0; j--)
                    f[j] = 0;
                for (int j = x+1; j <= m; j++)
                {
                    f[j] += f[j-1];
                    if (f[j] >= mod)    f[j] -= mod;
                }
            }

        }
        int res = f[m]-f[m-1];
        if (res < 0)  res += mod;
        printf("%d\n",res);
    }
    return 0;
}
