#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n,m;
int a[2100][2100];
int len[2100][2100];

int main()
{
    while (scanf("%d%d",&n,&m) != EOF)
    {
        for (int i = 1;i <= n;i++)
            for (int j = 1;j <= m;j++)
                scanf("%d",&a[i][j]);
        int res = 0;
        memset(len,0,sizeof(len));
        for (int i = 1;i <= n;i++)
            for (int j = m;j >= 1;j--)
                if (a[i][j] == 1)
                    len[i][j] = len[i][j+1]+1;
        for (int i = 1;i <= n;i++)
            for (int j = 1;j <= m;j++)
            {
                int maxlen = len[i][j];
                for (int k = i;k <= n;k++)
                {
                    if (maxlen > len[k][j]) maxlen = len[k][j];
                    if (maxlen*(k-i+1) > res)   res = maxlen*(k-i+1);
                    if (maxlen == 0)    break;
                    if (maxlen*(n-i+1) <= res)  break;
                }
            }
        printf("%d\n",res);
    }
}
