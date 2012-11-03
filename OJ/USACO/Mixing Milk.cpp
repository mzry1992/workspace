/*
ID: muziriy3
PROG: milk
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n,m;
struct milk
{
    int p,a;
}a[6000];

bool cmp(milk a,milk b)
{
    if (a.p == b.p)
        return a.a < b.a;
    return a.p < b.p;
}

int main()
{
    freopen("milk.in","r",stdin);
    freopen("milk.out","w",stdout);
    scanf("%d%d",&n,&m);
    for (int i = 1;i <= m;i++)
        scanf("%d%d",&a[i].p,&a[i].a);
    sort(a+1,a+1+m,cmp);
    int now,price;
    now = price = 0;
    for (int i = 1;i <= m;i++)
    if (now < n)
    {
        if (now+a[i].a <= n)
        {
            now += a[i].a;
            price += a[i].a*a[i].p;
        }
        else
        {
            price += (n-now)*a[i].p;
            now = n;
        }
    }
    else    break;
    printf("%d\n",price);
}

