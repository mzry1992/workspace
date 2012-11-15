#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n,s;
int x,y;

int tota,totb;
int ta[100];

void DFS(int now,int x,int y)
{
    if (now == n+1)
    {
        totb++;
        for (int i = 1;i <= n;i++)
        if (ta[i] != ta[i-1])
            tota++;
        return;
    }
    if (x > 0)
    {
        ta[now] = 1;
        DFS(now+1,x-1,y);
    }
    if (y > 0)
    {
        ta[now] = 0;
        DFS(now+1,x,y-1);
    }
}

int main()
{
    freopen("FAS.txt","w",stdout);
    for (n = 1;n <= 20;n++)
    for (s = 2*n;s <= 3*n;s++)
    {
        x = s-2*n;
        y = n-x;
        tota = totb = 0;
        ta[0] = 1;
        DFS(1,x,y);
        printf("%10d%10d%10d%10d%10d%10d\n",n,s,x,y,tota,totb);
    }
    return 0;
    while (scanf("%d%d",&n,&s) != EOF)
    {
        //double res = 0.0;
        //printf("%.7lf\n",res);
    }
}
