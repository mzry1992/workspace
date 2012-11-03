#include <stdio.h>

long m,k,i,a[1000000],tot,t1,t2;

long gcd(long a,long b)
{
     long temp;
     while (b != 0)
     {
           temp = a%b;
           a = b;
           b = temp;
     }
     return a;
}

int main()
{
    while (scanf("%ld %ld",&m,&k) == 2)
    {
          tot = 0;
          for (i = 1;i <= m;i++)
          if (gcd(i,m) == 1)
          {
                       tot++;
                       a[tot] = i;
                       if (tot == k)
                       {
                          printf("%ld\n",i);
                          break;
                       }
          }
          if (k > tot)
          {
                t1 = (k-1)/tot;
                t2 = (k-1)%tot;
                printf("%ld\n",t1*m+a[t2+1]);
          }
    }
    return 0;
}
              
              
