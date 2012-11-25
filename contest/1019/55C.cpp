#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n,m,k,x[100],y[100],d[100],mind;

int main()
{
    while (scanf("%d%d%d",&n,&m,&k) != EOF)
    {
        if (k == 0)
        {
            puts("NO");
            continue;
        }
        mind = 19921005;
        for (int i = 0;i < k;i++)
        {
            scanf("%d%d",&x[i],&y[i]);
            d[i] = min(min(x[i],n-x[i]+1),min(y[i],m-y[i]+1));
            mind = min(d[i],mind);
        }
        if (mind-2 >= 4)
            puts("NO");
        else
            puts("YES");
    }
    return 0;
}
