#include <stdio.h>
#include <string.h>

char s[100];
int num[100],tnum[100],i,j,n,app[9],tapp[9],flag1,flag2;

int main()
{
    while (scanf("%s",&s) == 1)
    {
          num[0] = strlen(s);
          n = num[0];
          for (i = 0;i <= 9;i++)    app[i] = 0;
          for (i = 1;i <= n;i++)
          {
              num[i] = s[n-i] - '0';
              app[num[i]]++;
          }
          flag2 = 0;
          for (i = 2;i <= n;i++)
          {
              for (j = 1;j <= n;j++)
                  tnum[j] = 0;
              for (j = 1;j <= n;j++)
              {
                  tnum[j] = tnum[j]+num[j]*i;
                  tnum[j+1] = tnum[j]/10;
                  tnum[j] = tnum[j]%10;
              }
              for (j = 0;j <= 9;j++)
                  tapp[j] = 0;
              for (j = 1;j <= n;j++)
                  tapp[tnum[j]]++;
              for (j = 0;j <= 9;j++)
                  if (tapp[j] != app[j]) flag2 = 1;
          }     
          if ((tnum[n+1] == 0) && (flag2 == 0))
             printf("%s is cyclic\n",s);
          else
              printf("%s is not cyclic\n",s);
    }
    return 0;
}
