#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const bool prime[40] = {0,0,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,1,0,0};
int n;
int a[30];
bool use[30];

void DFS(int now)
{
    if (now == n+1)
    {
        if (prime[a[n]+a[1]] == false)  return;
        for (int i = 1;i < n;i++)
            printf("%d ",a[i]);
        printf("%d\n",a[n]);
        return;
    }
    for (int i = 2;i <= n;i++)
    if (use[i] == false)
    if (prime[a[now-1]+i] == true)
    {
        a[now] = i;
        use[i] = true;
        DFS(now+1);
        use[i] = false;
    }
}

int main()
{
    int ft = 0;
    while (scanf("%d",&n) != EOF)
    {
        ft++;
        printf("Case %d:\n",ft);
        memset(use,false,sizeof(use));
        a[1] = 1;
        use[1] = true;
        DFS(2);
        printf("\n");
    }
}
