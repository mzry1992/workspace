#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

int n,m;

int solve()
{
    if (m == 1) return -1;
    if (n == 1) return 1;
    if (m == 2)
    {
        if (n == 1) return 1;
        if (n == 2) return 5;
        if (n == 3) return 11;
        return -1;
    }
    if (m == 3)
    {
        if (n == 1) return 1;
        if (n == 2) return 3;
        if (n == 3) return 5;
        if (n == 4) return 9;
        if (n == 5) return 11;
        return -1;
    }
    if (m%2 == 0)   return 2*((n-2)/((m-2)/2))+1;
    int d = m/2-1;
    if (n-2 < 2*d)  return 2*((n-2)/((m-2)/2))+1;
    if (n-2 == 2*d) return 3;
    if (n-2 < 2*d+1+2*d)    return 2*((n-3)/((m-2)/2))+1;
    if (n-2 == 2*d+1+2*d)   return 7;
    return 2*((n-4)/((m-2)/2))+1;
}

int main()
{
    scanf("%d%d",&n,&m);
    printf("%d\n",solve());
    return 0;
}