/*
ID: muziriy3
PROG: sprime
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <deque>
using namespace std;

const int base[5] = {2,3,5,7,11};

int modexp(int a,int b,int c)
{
    if (b == 1) return a%c;
    int res = modexp(a,b/2,c);
    res = (int)(((long long)res*(long long)res)%(long long)c);
    if (b%2 == 1)   res = (int)(((long long)res*(long long)(a%c))%(long long)c);
    return res;
}

bool isprime(int a)
{
    if (a == 1 || a == 4 || a == 6 || a == 8 || a == 9)     return false;
    if (a == 2 || a == 3 || a == 5 || a == 7 || a == 11)    return true;
    for (int i = 0;i < 5;i++)
    if (modexp(base[i],a-1,a) != 1) return false;
    return true;
}

int n;

void DFS(int dep,int now)
{
    if (dep == n)   printf("%d\n",now);
    else
    {
        for (int i = 1;i <= 9;i++)
        if (isprime(now*10+i) == true)
            DFS(dep+1,now*10+i);
    }
}

int main()
{
    freopen("sprime.in","r",stdin);
    freopen("sprime.out","w",stdout);
    scanf("%d",&n);
    DFS(0,0);
}
