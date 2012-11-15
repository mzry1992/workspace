#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct cardboard
{
    int ux,dx;
}ca[5100];
int n,m,dy,uy,x,y,tot[5100];
double tx[5100];

bool cmp(const cardboard& a,const cardboard& b)
{
    return a.dx < b.dx;
}

int main()
{
    bool first = true;
    while (true)
    {
        if (first == false) printf("\n");
        first = false;
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
            for (int i = 1;i <= n+1;i++)
                if (x < (double)ca[i].dx+(double)(ca[i].ux-ca[i].dx)*(double)(y-dy)/(double)(uy-dy))
                {
                    tot[i-1]++;
                    break;
                }
        }
        for (int i = 0;i <= n;i++)
            printf("%d: %d\n",i,tot[i]);
    }
    return 0;
}

