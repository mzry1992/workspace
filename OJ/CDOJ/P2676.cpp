#include <stdio.h>

int n,fn,i,j,a[9][9];
int fx[9][9],fy[9][9],fb[9][9];

int block(int i;int j)
{
    int ti,tj;
    if ((i >= 1) && (i <= 3)) ti = 1;
    if ((i >= 4) && (i <= 6)) ti = 2;
    if ((i >= 7) && (i <= 9)) ti = 3;
    if ((j >= 1) && (j <= 3)) tj = 1;
    if ((j >= 4) && (j <= 6)) tj = 2;
    if ((j >= 7) && (j <= 9)) tj = 3;
    return (3*ti+tj-3);
}

int main()
{
    scanf("%d",&n);
    for (fn = 1;fn <= n;fn++)
    {
        for (i = 1;i <= 9;i++)
        for (j = 0;j <= 9;j++)
            fx[i][j] = fy[i][j] = fb[i][j] = 0;
        for (i = 1;i <= 9;i++)
        for (j = 1;j <= 9;j++)
        {
            scanf("%d",&a[i][j]);
            fx[i][a[i][j]] = 1;
            fy[j][a[i][j]] = 1;
            
    }
    return 0;
}
