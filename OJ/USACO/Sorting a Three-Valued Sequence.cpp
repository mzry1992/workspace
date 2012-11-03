/*
ID: muziriy3
PROG: sort3
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n;
int a[1200];
int a12,a21,a13,a31,a23,a32,a1,a2,a3;

int main()
{
    freopen("sort3.in","r",stdin);
    freopen("sort3.out","w",stdout);
    scanf("%d",&n);
    a12 = a21 = a13 = a31 = a23 = a32 = a1 = a2 = a3 = 0;
    for (int i = 1;i <= n;i++)
    {
        scanf("%d",&a[i]);
        if (a[i] == 1)  a1++;
        if (a[i] == 2)  a2++;
        if (a[i] == 3)  a3++;
    }
    int res = 0;
    for (int i = 1;i <= a1;i++)
    {
        if (a[i] == 2)  a21++;
        if (a[i] == 3)  a31++;
    }
    for (int i = a1+1;i <= a1+a2;i++)
    {
        if (a[i] == 1)  a12++;
        if (a[i] == 3)  a32++;
    }
    for (int i = a1+a2+1;i <= a1+a2+a3;i++)
    {
        if (a[i] == 1)  a13++;
        if (a[i] == 2)  a23++;
    }
    if (a12 > a21)
    {
        res += a21;
        a12 -= a21;
        a21 = 0;
    }
    else
    {
        res += a12;
        a21 -= a12;
        a12 = 0;
    }
    if (a13 > a31)
    {
        res += a31;
        a13 -= a31;
        a31 = 0;
    }
    else
    {
        res += a13;
        a31 -= a13;
        a13 = 0;
    }
    if (a23 > a32)
    {
        res += a32;
        a23 -= a32;
        a32 = 0;
    }
    else
    {
        res += a23;
        a32 -= a23;
        a23 = 0;
    }
    if (a12+a21+a13+a31+a23+a32 > 0)    res += 2*(a12+a21+a13+a31+a23+a32)/3;
    printf("%d\n",res);
}
