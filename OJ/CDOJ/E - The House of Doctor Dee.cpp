#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>
using namespace std;

int tx1,tx2,tx3,tx4,ty1,ty2,ty3,ty4;
int kx1,kx2,kx3,kx4,ky1,ky2,ky3,ky4;
int x[4],y[4];

int main()
{
    while (scanf("%d%d",&tx1,&ty1) != EOF)
    {
        scanf("%d%d",&tx2,&ty2);
        scanf("%d%d",&tx3,&ty3);
        scanf("%d%d",&tx4,&ty4);
        kx1 = min(tx1,tx2);
        ky1 = min(ty1,ty2);
        kx2 = max(tx1,tx2);
        ky2 = max(ty1,ty2);
        kx3 = min(tx3,tx4);
        ky3 = min(ty3,ty4);
        kx4 = max(tx3,tx4);
        ky4 = max(ty3,ty4);
        int tx = min(kx2,kx4)-max(kx1,kx3);
        int ty = min(ky2,ky4)-max(ky1,ky3);
        if (tx < 0 || ty < 0)
        {
            printf("0\n");
            continue;
        }
        int fan1,fan2;
        if (tx1 <= tx2)
        {
            if (ty1 <= ty2) fan1 = 1;
            else fan1 = 2;
        }
        else
        {
            if (ty1 <= ty2) fan1 = 2;
            else fan1 = 1;
        }
        if (tx3 <= tx4)
        {
            if (ty3 <= ty4) fan2 = 1;
            else fan2 = 2;
        }
        else
        {
            if (ty3 <= ty4) fan2 = 2;
            else fan2 = 1;
        }
        if (fan1 == fan2)
            printf("%d\n",tx+ty);
        else
            printf("%d\n",max(tx,ty));
    }
}
