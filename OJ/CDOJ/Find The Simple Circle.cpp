#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int g[9][9],a[9];
bool use[9];
int n;

void Gao(int now)
{
    if (now > 1)
    {
        if (g[a[now-1]][a[0]] == 1)
        {
            for (int i = 0;i < now;i++)
                printf("%d",a[i]);
            printf("\n");
        }
    }
    for (int i = 0;i < n;i++)
        if (use[i] == false)
        {
            if (now > 0 && i < a[0])   continue;
            if (now == 0 || g[a[now-1]][i] == 1)
            {
                a[now] = i;
                use[i] = true;
                Gao(now+1);
                use[i] = false;
            }
        }
}

int main()
{
    while (scanf("%d",&n) != EOF)
    {
        for (int i = 0;i < n;i++)
            for (int j = 0;j < n;j++)
                scanf("%d",&g[i][j]);
        memset(use,false,sizeof(use));
        Gao(0);
        printf("\n");
    }
    return 0;
}
