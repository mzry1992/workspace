#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct cardboard
{
    int ux,dx;
}ca[5100];
int n,m,dy,uy,x,y,tot[5100],res[5100];
double tx[5100];

bool cmp(const cardboard& a,const cardboard& b)
{
    return a.dx < b.dx;
}

int main()
{
    while (true)
    {
        scanf("%d",&n);
        if (n == 0) break;
        scanf("%d%d%d%d%d",&m,&ca[0].dx,&uy,&ca[n+1].dx,&dy);
        ca[0].ux = ca[0].dx;
        ca[n+1].ux = ca[n+1].dx;
        for (int i = 1;i <= n;i++)
            scanf("%d%d",&ca[i].ux,&ca[i].dx);
        sort(ca,ca+n+2,cmp);
        memset(tot,0,4*(n+1));
        for (int i = 1;i <= m;i++)
        {
            scanf("%d%d",&x,&y);
            for (int i = 0;i <= n+1;i++)
                tx[i] = (double)ca[i].dx+(double)(ca[i].ux-ca[i].dx)*(double)(y-dy)/(double)(uy-dy);
            for (int i = 0;i <= n;i++)
            {
                if (x > tx[i] && x < tx[i+1])
                {
                    tot[i]++;
                    break;
                }
            }
        }
        memset(res,0,4*(n+2));
        for (int i = 0;i <= n;i++)
            res[tot[i]]++;
        printf("Box\n");
        for (int i = 1;i <= m;i++)
            if (res[i] > 0)
                printf("%d: %d\n",i,res[i]);
    }
    return 0;
}

