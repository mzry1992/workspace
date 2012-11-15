#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n,m;
int t[1010000];

int main()
{
    while (scanf("%d%d",&n,&m) != EOF)
    {
        memset(t,0,sizeof(t));
        for (int i = 1;i <= n;i++)
        {
            int temp;
            scanf("%d",&temp);
            t[temp+500000]++;
        }
        int tot = 0;
        for (int i = 1000000;i >= 0;i--)
        if (tot == m)   break;
        else
        while (t[i] > 0)
        {
            printf("%d ",i-500000);
            t[i]--;
            tot++;
            if (tot == m)   break;
        }
        printf("\n");
    }
}
