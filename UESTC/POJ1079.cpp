#include <stdio.h>
#include <math.h>

int a,b,p,q,tp,tq;

int main()
{
    while (scanf("%d %d",&a,&b) == 2 )
    {
          tq = 1;
          tp = (int)((double)(tq*a)/(double)b+0.5);
          printf("%d/%d\n",tp,tq);
          for (q = 2;;q++)
          {
              p = (int)((double)(q*a)/(double)b+0.5);
              if (q*fabs(tp*b-a*tq) > tq*fabs(p*b-a*q))
              {
                                   tp = p;
                                   tq = q;
                                   printf("%d/%d\n",tp,tq);
              }
              if (a*q == p*b)                 break;
          }
          printf("\n");
    }
    return 0;
}
