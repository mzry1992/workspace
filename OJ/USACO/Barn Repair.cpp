/*
ID: muziriy3
PROG: barn1
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int m,s,c;
int a[300];

int main()
{
    freopen("barn1.in","r",stdin);
    freopen("barn1.out","w",stdout);
    scanf("%d%d%d",&m,&s,&c);
    for (int i = 1;i <= c;i++)
        scanf("%d",&a[i]);
    sort(a+1,a+c+1);
    int res = a[c]-a[1]+1;
    for (int i = 2;i <= c;i++)
        a[i-1] = a[i]-a[i-1]-1;
    sort(a+1,a+c);
    for (int i = 1;i <= m-1 && c-i >= 1;i++)
        res -= a[c-i];
    printf("%d\n",res);
}
