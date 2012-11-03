/*
ID: muziriy3
PROG: ariprog
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <deque>
using namespace std;

int n,m;
bool use[130000];
int num[130000],tot;
struct ab
{
    int a,b;
}res[12000];
int totres;

bool cmp(ab a,ab b)
{
    if (a.b == b.b)
        return a.a < b.a;
    return a.b < b.b;
}

int main()
{
    freopen("ariprog.in","r",stdin);
    freopen("ariprog.out","w",stdout);
    scanf("%d%d",&n,&m);
    memset(use,false,sizeof(use));
    for (int i = 0;i <= m;i++)
    for (int j = 0;j <= m;j++)
        use[i*i+j*j] = true;
    tot = 0;
    for (int i = 0;i <= m*m*2;i++)
    if (use[i] == true)
    {
        tot++;
        num[tot] = i;
    }
    totres = 0;
    for (int i = 1;i <= tot-n+1;i++)
    for (int j = i+1;j <= tot-n+2;j++)
    {
        int ta = num[i];
        int tb = num[j]-num[i];
        bool flag = true;
        for (int k = 2;k < n;k++)
        if (use[ta+k*tb] == false)
        {
            flag = false;
            break;
        }
        if (flag == true)
        {
            totres++;
            res[totres].a = ta;
            res[totres].b = tb;
        }
    }
    sort(res+1,res+1+totres,cmp);
    for (int i = 1;i <= totres;i++)
        printf("%d %d\n",res[i].a,res[i].b);
    if (totres == 0)
        printf("NONE\n");
}
