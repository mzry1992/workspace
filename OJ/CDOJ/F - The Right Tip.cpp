#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
int a[10];
const int v[8] = {1,2,5,10,20,50,100,200};
int sum;
bool hasans;

void DFS(int now,int nowsum,int coin)
{
    if (hasans == true) return;
    if (now == n)
    {
        hasans = true;
        return;
    }
    if (coin == 8 && nowsum != sum) return;
    if (nowsum == sum)
        DFS(now+1,0,0);
    else
    {
        if (sum-nowsum < v[coin])   return;
        for (int i = min((sum-nowsum)/v[coin],a[coin]);i >= 0;i--)
        {
            a[coin] -= i;
            DFS(now,nowsum+i*v[coin],coin+1);
            a[coin] += i;
        }
    }
}

int main()
{
    while (true)
    {
        scanf("%d",&n);
        if (n == -1)    break;
        sum = 0;
        for (int i = 0;i < 8;i++)
        {
            scanf("%d",&a[i]);
            sum += a[i]*v[i];
        }
        if (sum%n != 0)
        {
            printf("no\n");
            continue;
        }
        sum /= n;
        hasans = false;
        DFS(1,0,0);
        if (hasans == true)
            printf("yes\n");
        else
            printf("no\n");
    }
}
