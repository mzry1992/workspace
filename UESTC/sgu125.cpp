#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n,a[3][3],b[3][3];
bool hasres;

void Gao(int x,int y)
{
    if (y >= n)
    {
        x++;
        y = 0;
    }
    int cc;
    if (x == n)
    {
        bool check = true;
        for (int i = 0;i < n && check;i++)
            for (int j = 0;j < n && check;j++)
            {
                cc = 0;
                if (i-1 >= 0)   cc += (a[i-1][j] > a[i][j]);
                if (j-1 >= 0)   cc += (a[i][j-1] > a[i][j]);
                if (i+1 < n)    cc += (a[i+1][j] > a[i][j]);
                if (j+1 < n)    cc += (a[i][j+1] > a[i][j]);
                if (cc != b[i][j])
                    check = false;
            }
        if (check == false) return;
        for (int i = 0;i < n;i++,puts(""))
            for (int j = 0;j < n;j++)
                printf("%d ",a[i][j]);
        hasres = true;
    }
    if (hasres == true) return;
    for (int i = 9;i >= 0;i--)
    {
        a[x][y] = i;
        cc = 0;
        if (x-1 >= 0)   cc += (a[x-1][y] > a[x][y]);
        if (y-1 >= 0)   cc += (a[x][y-1] > a[x][y]);
        if (cc > b[x][y])   break;
        Gao(x,y+1);
    }
}

int main()
{
    scanf("%d",&n);
    for (int i = 0;i < n;i++)
        for (int j = 0;j < n;j++)
            scanf("%d",&b[i][j]);
    hasres = false;
    memset(c,0,sizeof(c));
    Gao(0,0);
    if (hasres == false)
        puts("NO SOLUTION");
    return 0;
}
