#include <stdio.h>

int i,n,temp,tot2,tot5,last;

int main()
{
    while (scanf("%d",&n) == 1)
    {
          if (n == 0)
             printf("%d\n",1);
          else
          {
              last = 1;
              tot2 = 0;
              tot5 = 0;
              for (i = 1;i <= n;i++)
              {
                  temp = i;
                  while (temp%2 == 0)
                  {
                        temp = temp/2;
                        tot2++;
                  }
                  while (temp%5 == 0)
                  {
                        temp = temp/5;
                        tot5++;
                  }
                  last = last*temp;
                  last = last%10;
              }
              if (tot2 <= tot5)
              {
                       tot5 -= tot2;
                       tot2 -= tot2;
              }
              else
              {
                       tot2 -= tot5;
                       tot5 -= tot5;
              }
              for (i = 1;i <= tot2;i++)
              {
                  last = last*2;
                  last = last%10;
              }
              for (i = 1;i <= tot5;i++)
              {
                  last = last*5;
                  last = last%10;
              }
              printf("%5d -> %d\n",n,last);
          }
    }
    return 0;
}
