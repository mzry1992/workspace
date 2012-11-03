/*
ID: muziriy3
PROG: crypt1
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
int a[20];
int num[10];
int res;
bool ta[10];

bool check(int x,int y)
{
    for (int i = 1;i <= y;i++)
    {
        if (ta[x%10] == false)  return false;
        x /= 10;
    }
    return true;
}

void DFS(int now)
{
    if (now == 5)
    {
        int numa = num[0]*100+num[1]*10+num[2];
        int numb = num[3]*10+num[4];
        int numc = numa*num[4];
        int numd = numa*num[3];
        int nume = numa*numb;
        if (numc <= 999 && numc >= 100)
        if (numd <= 999 && numd >= 100)
        if (nume <= 9999 && nume >= 1000)
        if (check(numc,3))
        if (check(numd,3))
        if (check(nume,4))
            res++;
    }
    else
        for (int i = 1;i <= n;i++)
        {
            num[now] = a[i];
            DFS(now+1);
        }
}

int main()
{
    freopen("crypt1.in","r",stdin);
    freopen("crypt1.out","w",stdout);
    scanf("%d",&n);
    memset(ta,false,sizeof(ta));
    for (int i = 1;i <= n;i++)
    {
        scanf("%d",&a[i]);
        ta[a[i]] = true;
    }
    res = 0;
    DFS(0);
    printf("%d\n",res);
}
