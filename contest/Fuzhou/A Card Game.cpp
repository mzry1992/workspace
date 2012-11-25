#include <cstdio>
using namespace std;

int m,a[100],n;

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d",&m);
        n = 0;
        for (int i = 0;i < m;i++)
        {
            scanf("%d",&a[i]);
            n += a[i];
        }
        printf("Case %d: %.6f\n",ft,(double)a[0]/(double)n);
    }
    return 0;
}
