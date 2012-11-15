#include <stdio.h>

int n,i,j,k,q,sum,sum1,result;
int a[101][101];

int main()
{
    while (scanf("%d",&n) == 1)
    {
          result = 0;
          for (i = 1;i <= n;i++)
          for (j = 1;j <= n;j++)
              scanf("%d",&a[i][j]);
          for (i = 1;i <= n;i++)
          for (j = i;j <= n;j++)
          {
               sum = 0;
               for (k = 1;k <= n;k++)
               {
                    sum1 = 0;
                    for (q = i;q <= j;q++)
                        sum1 += a[q][k];
                    sum += sum1;
                    if (sum < 0)  sum = 0;
                    if (sum > result) 
                       result = sum;
               }
          }
          printf("%d\n",result);
    }
    return 0;
}  
                
