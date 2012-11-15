#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int ans[1100][1100];

int main()
{
    int n;
    scanf("%d",&n);
    memset(ans,0,sizeof(ans));
    for (int i = 1;i <= n;i++)
    for (int j = 1;j <= i;j++)
    {
        scanf("%d",&ans[i][j]);
        if (ans[i-1][j-1] < ans[i-1][j])
            ans[i][j] += ans[i-1][j];
        else
            ans[i][j] += ans[i-1][j-1];
    }
    int max = 0;
    for (int i = 1;i <= n;i++)
    if (ans[n][i] > max)
        max = ans[n][i];
    printf("%d\n",max);
}
