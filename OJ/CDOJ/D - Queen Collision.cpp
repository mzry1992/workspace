#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n,g;
int h[30100],l[30100],x1[60100],x2[60100];
int k,x,y,s,t;

int main()
{
    while (true)
    {
        scanf("%d",&n);
        if (n == 0) break;
        scanf("%d",&g);
        memset(h,0,sizeof(h));
        memset(l,0,sizeof(l));
        memset(x1,0,sizeof(x1));
        memset(x2,0,sizeof(x2));
        for (int i = 1;i <= g;i++)
        {
            scanf("%d%d%d%d%d",&k,&x,&y,&s,&t);
            for (int j = 0;j < k;j++)
            {
                int tx,ty;
                tx = x+j*s;
                ty = y+j*t;
                h[tx]++;
                l[ty]++;
                x1[tx-ty+n]++;
                x2[tx+ty]++;
            }
        }
        int tot = 0;
        for (int i = 1;i <= n;i++)
        {
            if (h[i] > 0)
                tot += h[i]-1;
            if (l[i] > 0)
                tot += l[i]-1;
        }
        for (int i = 1;i <= 2*n;i++)
        {
            if (x1[i] > 0)
                tot += x1[i]-1;
            if (x2[i] > 0)
                tot += x2[i]-1;
        }
        printf("%d\n",tot);
    }
}
