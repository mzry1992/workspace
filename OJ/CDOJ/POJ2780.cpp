#include <iostream>
using namespace std;

int n;
int x[1200],y[1200];
int ans;

int main()
{
    int i,j,k,tans;
    while (scanf("%d",&n) == 1)
    {
        for (i = 1;i <= n;i++)
            scanf("%d%d",&x[i],&y[i]);
        ans = 2;
        for (i = 1;i < n;i++)
        for (j = i+1;j <= n;j++)
        {
            tans = 2;
            for (k = 1;k <= n;k++)
            if (k != i)
            if (k != j)
            if ((x[i]-x[j])*(y[k]-y[i]) == (y[i]-y[j])*(x[k]-x[i]))
               tans++;
            if (tans > ans)
               ans = tans;
        }
        printf("%d\n",ans);
    }
    return 0;
}
