#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n,a[100][200];
bool f1[200],f2[200][200];

int main()
{
    scanf("%d",&n);
    memset(f1,false,sizeof(f1));
    memset(f2,false,sizeof(f2));
    for (int i = 0;i < 2*n;i++)
        f2[i][i] = true;
    for (int i = 0;i < n;i++)
    {
        for (int j = 0;j < 2*n;j++)
            if (f1[j] == false)
            {
                a[i][0] = j;
                f1[j] = true;
                break;
            }
        for (int j = 1;j < 2*n-1;j++)
        {
            for (int k = 0;k < 2*n;k++)
                if (f2[a[i][j-1]][k] == false)
                {
                    a[i][j] = k;
                    f2[a[i][j-1]][k] = true;
                    f2[k][a[i][j-1]] = true;
                    break;
                }
        }
        for (int k = 0;k < 2*n;k++)
            if (f2[a[i][2*n-2]][k] == false && f1[k] == false)
            {
                a[i][2*n-1] = k;
                f2[a[i][2*n-2]][k] = true;
                f2[k][a[i][2*n-2]] = true;
                f1[k] = true;
                break;
            }
    }
    for (int i = 0;i < n;i++)
    {
        for (int j = 0;j < 2*n;j++)
            printf("%d ",a[i][j]+1);
        printf("\n");
    }
    return 0;
}
