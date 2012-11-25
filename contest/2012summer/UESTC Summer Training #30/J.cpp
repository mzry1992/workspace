#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int n,m,a[11000],now;

int main()
{
    scanf("%d%d",&n,&m);
    for (int i = 1;i <= n+m-1;i++)
        scanf("%d",&a[i]);
    now = 0;
    for (int i = 0;i < n;i++)
    {
        int minp = a[i+1]-now;
        //printf("%d %d\n",i,a[i+1]);
        for (int j = 2;j <= m;j++)
        {
            //cout << i << ' ' << j << ' ' << minp << ' ' << a[i+j] << endl;
            if (a[i+j]-now < 0)
                minp = max(minp,(a[i+j]-now)/j);
            else
            {
                if ((a[i+j]-now)%j == 0)
                    minp = max(minp,(a[i+j]-now)/j);
                else
                    minp = max(minp,(a[i+j]-now)/j+1);
            }
        }
        if (i > 0)
            printf(" ");
        printf("%d",minp);
        now += minp;
        //printf("minp = %d, now = %d\n",minp,now);
    }
    printf("\n");
	return 0;
}
