#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int n,a[10000][5],m;
int b[10000][5];

int main()
{
    int totcas;
    scanf("%d",&totcas);
    for (int cas = 1; cas <= totcas; cas++)
    {
        scanf("%d%d",&n,&m);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < 5; j++)
                scanf("%d",&a[i][j]);
        m = min(m,5);
        int res = 0;
        for (int a0 = 0; a0 < m; a0++)
            for (int a1 = 0; a1 < m; a1++)
                for (int a2 = 0; a2 < m; a2++)
                    for (int a3 = 0; a3 < m; a3++)
                        for (int a4 = 0; a4 < m; a4++)
                        {
                            for (int i = 0; i < n; i++)
                            {
                                for (int j = 0; j < m; j++)
                                    b[i][j] = 0;
                                b[i][a0] += a[i][0];
                                b[i][a1] += a[i][1];
                                b[i][a2] += a[i][2];
                                b[i][a3] += a[i][3];
                                b[i][a4] += a[i][4];
                            }
                            int tmp = 0;
                            for (int j = 0;j < m;j++)
                            {
                                int mx = 0;
                                for (int i = 0; i < n; i++)
                                    mx = max(b[i][j],mx);
                                tmp += mx;
                            }
                            res = max(res,tmp);
                        }
        printf("%d\n",res);
    }
    return 0;
}
