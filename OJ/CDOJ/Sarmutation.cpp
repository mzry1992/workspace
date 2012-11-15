#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n,a[1000],c,d,ta[1000];

bool check()
{
    for (int i = 0; i < n; i++)
        if (a[i] != ta[i])  return false;
    return true;
}

void Gao()
{
    c = a[0];
    int fai = 0;
    for (int j = 0; j < n; j++)
    {
        d = a[j]-c;
        if (d == 0) continue;
        ta[0] = c;
        for (int i = 1; i < n; i++)
        {
            if (i%4 == 1)
                ta[i] = ta[i-1]+d;
            else if (i%4 == 2)
                ta[i] = ta[i-1]*d;
            else if (i%4 == 3)
                ta[i] = ta[i-1]-d;
            else
                ta[i] = ta[i-1]/d;
        }
        sort(ta,ta+n);
        if (check())
        {
            puts("YES");
            return;
        }
        fai++;
        if (fai == 2)   break;
    }
    puts("NO");
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1; ft <= t; ft++)
    {
        scanf("%d",&n);
        for (int i = 0; i < n; i++)
            scanf("%d",&a[i]);
        sort(a,a+n);
        Gao();
    }
    return 0;
}
