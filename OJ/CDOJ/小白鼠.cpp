#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n,tot;
double p[200],sum[200];
int fa[200];
bool del[200];

int getmin()
{
    int res = -1;
    for (int i = 0;i < tot;i++)
        if (del[i] == false)
            if (res == -1 || sum[res] > sum[i])
                res = i;
    return res;
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d",&n);
        for (int i = 0;i < n;i++)
        {
            scanf("%lf",&p[i]);
            fa[i] = i;
            sum[i] = p[i];
            del[i] = false;
        }
        tot = n;
        for (int i = 1;i < n;i++)
        {
            int ida = getmin();
            del[ida] = true;
            int idb = getmin();
            del[idb] = true;

            fa[tot] = tot;
            sum[tot] = sum[ida]+sum[idb];
            del[tot] = false;
            fa[ida] = fa[idb] = tot++;
        }
        double res = 0;
        for (int i = 0;i < n;i++)
        {
            int tim = 0;
            int ti = i;
            while (fa[ti] != ti)
            {
                tim++;
                ti = fa[ti];
            }
            tim = max(tim,1);
            res += tim*p[i];
            //cout << tim << ' ' << p[i] << endl;
        }
        printf("%.2f\n",res);
    }
    return 0;
}
