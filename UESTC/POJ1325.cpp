#include <iostream>
#include <cstdio>
using namespace std;

int n,m,tt,map[300][300];

int main()
{
    int i,j,tx,ty;
    scanf("%d",&n);
    while (n != 0)
    {
          for (i = 1;i <= n;i++)
              map[0][i] = 1;
          scanf("%d%d",&m,&tt);
          for (i = 1;i <= m;i++)
              map[n+i][n+m+1] = 1;
          for (i = 1;i <= tt;i++)
          {
              scanf("%d%d%d",&j,&tx,&ty);
              map[tx+1][n+ty+1] = 1;
          }
          for (i = 0;i <= n+m+1;i++)
          {
              for (j = 0;j <= n+m+1;i++)
                  cout << map[i][j] << ' ';
              cout << endl;
          }
    }
}
