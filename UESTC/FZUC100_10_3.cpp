#include <iostream>
#include <cmath>
using namespace std;

const int maxv = 1<<30;
int t,ft;
int n,m,sx,sy,ex,ey;
char map[60][60];
bool A[60][60],B[60][60],C[60][60],D[60][60],E[60][60],F[60][60];

int main()
{
    int i,j;
    scanf("%d",&t);
    for (ft = 1;ft <= t;ft++)
    {
        scanf("%d%d",&n,&m);
        for (i = 1;i <= n;i++)
            scanf("%s",&map[i]);
        for (i = 1;i <= n;i++)
        for (j = 0;j < m;j++)
        {
            if (map[i][j] == '$')  
            {
                          sx = i;  sy = j;
            }
            if (map[i][j] == '!')
            {
                          ex = i;  ey = j;
            }
        }
        for (i = 1;i <= n;i++)
        for (j = 0;j < m;j++)
        
    }
    return 0;
}
