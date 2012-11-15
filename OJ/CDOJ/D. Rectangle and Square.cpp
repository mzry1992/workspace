#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int x[8],y[8],a[8],b[4],c[4];
bool hasres;

bool check(int a[])
{
    for (int i = 0;i < 4;i++)
    {
        int xa,ya,xb,yb;
        xa = x[a[(i+3)%4]]-x[a[i]];
        ya = y[a[(i+3)%4]]-y[a[i]];
        xb = x[a[(i+1)%4]]-x[a[i]];
        yb = y[a[(i+1)%4]]-y[a[i]];
        if (xa*xb+ya*yb != 0)   return false;
    }
    return true;
}

int ch;

bool check1(int a[])
{
    if (check(a) == false)  return false;
    int la2,lb2;
    int xa,ya,xb,yb;
    xa = x[a[3]]-x[a[0]];
    ya = y[a[3]]-y[a[0]];
    xb = x[a[1]]-x[a[0]];
    yb = y[a[1]]-y[a[0]];
    la2 = xa*xa+ya*ya;
    lb2 = xb*xb+yb*yb;
    if (la2 == 0 || lb2 == 0)   return false;
    if (la2 != lb2) return false;
    return true;
}

bool check2(int a[])
{
    if (check(a) == false)  return false;
    int la2,lb2;
    int xa,ya,xb,yb;
    xa = x[a[3]]-x[a[0]];
    ya = y[a[3]]-y[a[0]];
    xb = x[a[1]]-x[a[0]];
    yb = y[a[1]]-y[a[0]];
    la2 = xa*xa+ya*ya;
    lb2 = xb*xb+yb*yb;
    if (la2 == 0 || lb2 == 0)   return false;
    return true;
}

int main()
{
    for (int i = 0;i < 8;i++)
        scanf("%d%d",&x[i],&y[i]);
    for (int i = 0;i < 8;i++)
        a[i] = i;
    hasres = false;
    do
    {
        for (int i = 0;i < 4;i++)
            b[i] = a[i];
        for (int i = 4;i < 8;i++)
            c[i-4] = a[i];
        if (check1(b) && check2(c))
        {
            hasres = true;
            break;
        }
    }while (next_permutation(a,a+8));
    if (hasres == false)    puts("NO");
    else
    {
        puts("YES");
        for (int i = 0;i < 4;i++)
            printf("%d ",b[i]+1);
        printf("\n");
        for (int i = 0;i < 4;i++)
            printf("%d ",c[i]+1);
        printf("\n");
    }
    return 0;
}

