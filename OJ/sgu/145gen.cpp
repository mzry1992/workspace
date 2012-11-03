#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

int x[20],y[20],z[20];

int main()
{
    freopen("145in2.txt","w",stdout);
    freopen("145in.txt","r",stdin);
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    for (int i = 0; i < m; i++)
        scanf("%d%d%d",&x[i],&y[i],&z[i]);
    int xs,xe;
    scanf("%d%d",&xs,&xe);
    for (int k = 1; k <= 16; k++)
    {
        printf("%d %d %d\n",n,m,k);
        for (int i = 0; i < m; i++)
            printf("%d %d %d\n",x[i],y[i],z[i]);
        printf("%d %d\n",xs,xe);
    }
    return 0;
}
