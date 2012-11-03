/*
ID: muziriy3
PROG: hamming
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <deque>
#include <string>
using namespace std;

int n,b,d;
int res[100];

int cmp(int x,int y)
{
    int c = x^y;
    int res = 0;
    for (int i = 1;i <= b;i++)
    if ((c>>(i-1))&1 == 1)  res++;
    return res;
}

bool check(int tot)
{
    for (int i = 1;i < tot;i++)
    if (cmp(res[i],res[tot]) < d)   return false;
    return true;
}

int main()
{
    //freopen("hamming.in","r",stdin);
    //freopen("hamming.out","w",stdout);
    scanf("%d%d%d",&n,&b,&d);
    res[1] = 0;
    for (int i = 2;i <= n;i++)
    {
        res[i] = res[i-1];
        while (true)
        {
            res[i]++;
            if (check(i))
                break;
        }
    }
    for (int i = 1;i <= n;i++)
    {
        printf("%d",res[i]);
        if (i%10 == 0 || i == n)
            printf("\n");
        else
            printf(" ");
    }
}
