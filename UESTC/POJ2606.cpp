#include <stdio.h>

int n,i,j,k,x[200],y[200];
int km[200][200],kn[200][200],tm,tn,tgcd,flag,result,sum;

int gcd(int a,int b)
{
    if (a%b == 0) return b;
    return gcd(b,a%b);
}

int main()
{
    while (scanf("%d",&n) == 1)
    {
        for (i = 1;i <= n;i++)
            scanf("%d %d",&x[i],&y[i]);
        for (i = 1;i <= n;i++)
        for (j = 1;j <= n;j++)
        if (i != j)
        {
              tm = y[i]-y[j];
              tn = x[i]-x[j];
              flag = 1;
              if (tm*tn >= 0) flag = 0;
              if (tm < 0) tm = -tm;
              if (tn < 0) tn = -tn;
              if (tm == 0) tn = 1;
              if (tn == 0) tm = 1;
              if ((tm != 0) && (tn != 0))
              {
                 tgcd = gcd(tm,tn);
                 tm = tm/tgcd;
                 tn = tn/tgcd;
              }
              if (flag == 1) tm = -tm;
              km[i][j] = km[j][i] = tm;
              kn[i][j] = kn[j][i] = tn;
        }
        result = 1;
        for (i = 1;i <= n;i++)
        {
            for (j = 1;j <= n;j++)
            if (i != j)
            {
                  tm = km[i][j];
                  tn = kn[i][j];
                  if (!((tm == 0) && (tn == 0)))
                  {
                      sum = 2;
                      for (k = 1;k <= n;k++)
                      if ((k != i) && (k != j))
                      if ((km[i][k] == tm) && (kn[i][k] == tn))
                         sum++;
                      if (sum > result) result = sum;
                  }
            }
        }
        if (n == 0) result = 0;
        printf("%d\n",result);
    }
    return 0;
}
    
