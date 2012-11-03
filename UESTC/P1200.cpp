#include <stdio.h>
#include <string.h>
#define MAX 16000000

char s[MAX];
bool hash[MAX];
int n,nc,totnow,l,i,j,c[500];
long thash,result,low[100];

int main()
{
    while (scanf("%d %d",&n,&nc) == 2)
    {
          scanf("%s",&s);
          memset(c,0,sizeof(c));
          memset(hash,0,sizeof(hash));
          totnow = 0;
          l = strlen(s);
          for (i = 0;i < l;i++)
          if (c[s[i]] == 0)
          {
                      c[s[i]] = totnow;
                      totnow++;
          }
          low[0] = 1;
          for (i = 1;i <= n;i++)
              low[i] = low[i-1]*nc;
          result = 0;
          for (i = 0;i <= l-n;i++)
          {
                 thash = 0;
                 for (j = 1;j <= n;j++)
                     thash += c[s[i+j-1]]*low[n-j];
                 if (hash[thash] == 0)
                 {
                                 hash[thash] = 1;
                                 result++;
                 }
          }
          printf("%ld",result);
                 
    }
    return 0;
}
          
    
