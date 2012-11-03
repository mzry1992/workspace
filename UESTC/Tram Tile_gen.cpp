#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n,m,k;
bool a[10][10];

void Gao(int x,int y,int deep)
{
    if (deep == k)
    {
        printf("%d %d\n",n,m);
        for (int i = 0;i < n;i++)
        {
            for (int j = 0;j < m;j++)
                printf("%d",a[i][j]);
            printf("\n");
        }
        return;
    }
    int tx,ty;
    ty = y+1;
    if (ty >= m)
    {
        ty = 0;
        tx = x+1;
    }
    else
        tx = x;
    if (tx >= n)    return;
    Gao(tx,ty,deep);
    if (a[x][y] == false)
    {
        a[x][y] = true;
        if (y+1 < m && a[x][y+1] == false)
        {
            a[x][y+1] = true;
            Gao(tx,ty,deep+1);
            a[x][y+1] = false;
        }
        if (x+1 < n && a[x+1][y] == false)
        {
            a[x+1][y] = true;
            Gao(tx,ty,deep+1);
            a[x+1][y] = false;
        }
        a[x][y] = false;
    }
}

int main()
{
    freopen("0.in","w",stdout);
    n = 7;
    m = 6;
    k = 3;
    memset(a,false,sizeof(a));
    Gao(0,0,0);
    return 0;
}
