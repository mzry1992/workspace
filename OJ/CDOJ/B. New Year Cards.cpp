#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n,a[301][300],rk[301][301],m0,m1,res[300];

int main()
{
    while (scanf("%d",&n) != EOF)
    {
        for (int i = 0;i <= n;i++)
            for (int j = 0;j < n;j++)
            {
                scanf("%d",&a[i][j]);
                a[i][j]--;
            }
        for (int i = 0;i <= n;i++)
        {
            for (int j = 0;j < n;j++)
                rk[i][a[i][j]] = j;
            rk[i][n] = n;
        }
        m0 = 0;
        m1 = n;
        for (int i = 0;i < n;i++)
            res[i] = 0;
        res[0] = n;
        for (int i = 1;i < n;i++)
        {
            if (rk[n][i] < rk[n][m0])
            {
                m1 = m0;
                m0 = i;
            }
            else if (rk[n][i] < rk[n][m1])
                m1 = i;
            for (int j = 0;j < n;j++)
            {
                int id = m0;
                if (m0 == j)
                    id = m1;
                if (rk[j][id] < rk[j][res[j]])
                    res[j] = id;
            }
        }
        for (int i = 0;i < n;i++)
            printf("%d ",res[i]+1);
        printf("\n");
    }
    return 0;
}
