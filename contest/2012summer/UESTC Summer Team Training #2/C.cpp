#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int a[4];

int main()
{
    int cas = 0;
    while (scanf("%d",&a[0]) != EOF)
    {
        for (int i = 1;i < 4;i++)
            scanf("%d",&a[i]);
        sort(a,a+4);
        int resa = a[3]+a[2];
        int resb;
        if (a[2]+a[1] <= a[3])
            resb = max(a[3],a[0]+a[1]+a[2]);
        else
        {
            int more = a[2]+a[1]-a[3];
            if (more >= a[0])
                resb = a[1]+a[2];
            else
                resb = a[1]+a[2]+a[0]-more;
        }
        printf("Case %d: %d\n",++cas,max(resa,resb));
    }
	return 0;
}
