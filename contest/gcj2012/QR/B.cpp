#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int b[31][2];
int n,s,p,a[110];
bool del[110];

int main()
{
    freopen("B-large.in","r",stdin);
    freopen("B-large.out","w",stdout);
    for (int i = 0;i < 31;i++)
        b[i][0] = b[i][1] = -1;
    for (int x = 0;x <= 10;x++)
        for (int y = x;y <= 10;y++)
            if (y-x <= 2)
                for (int z = y;z <= 10;z++)
                    if (z-y <= 2 && z-x <= 2)
                    {
                        if (y-x == 2 || z-y == 2 || z-x == 2)
                            b[x+y+z][1] = max(b[x+y+z][1],z);
                        else
                            b[x+y+z][0] = max(b[x+y+z][0],z);
                    }
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d%d%d",&n,&s,&p);
        for (int i = 0;i < n;i++)
            scanf("%d",&a[i]);
        sort(a,a+n);
        int res = 0;
        int used = 0;
        memset(del,false,sizeof(del));
        for (int i = 0;i < n;i++)
            if (used < s && b[a[i]][0] < p && b[a[i]][1] >= p)
            {
                //cout << a[i] << ' ' << b[a[i]][0] << ' ' << b[a[i]][1] << endl;
                res++;
                used++;
                del[i] = true;
            }
        for (int i = 0;i < n;i++)
            if (del[i] == false)
                if (b[a[i]][0] >= p)
                    res++;
        printf("Case #%d: %d\n",ft,res);
    }
	return 0;
}
