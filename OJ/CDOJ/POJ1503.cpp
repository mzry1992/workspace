#include <stdio.h>
#include <string.h>
#define MAX(A,B) (((A) > (B)) ? (A) : (B))

char s[1000];
int num[1600],temp[1600],temp2[1600],maxlen,i;

void output(int a[1600])
{
     int i;
     for (i = 0;i < a[0];i++)
         printf("%d",a[a[0]-i]);
     printf("\n");
}

int main()
{
    gets(s);
    num[0] = 1;
    for (i = 1;i <= 1500;i++)
        num[i] = 0;
    while (!((strlen(s) == 1) && (s[0] == '0')))
    {     
          for (i = 0;i <= 1500;i++)
              temp[i] = 0;
          temp[0] = strlen(s);
          for (i = 0;i < temp[0];i++)
              temp[temp[0]-i] = (int)(s[i]-'0');
          maxlen = MAX(num[0],temp[0]);
          temp2[0] = maxlen;
          for (i = 1;i <= 1500;i++)
              temp2[i] = 0;
          for (i = 1;i <= maxlen;i++)
          {
              temp2[i+1] = (temp2[i]+temp[i]+num[i])/10;
              temp2[i] = (temp2[i]+temp[i]+num[i])%10;
          }
          if (temp2[maxlen+1] > 0) temp2[0] = maxlen+1;
          for (i = 0;i <= 1500;i++)
              num[i] = temp2[i];
          gets(s);
    }
    while (num[num[0]] == 0) num[0]--;
    output(num);
    return 0;
}
