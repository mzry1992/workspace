#include <stdio.h>
#include <math.h>

int main()
{
    int t,i;
    double s,p,a,b,c;
    scanf("%d",&t);
    for (i = 0;i < t;i++)
    {
        scanf("%lf %lf %lf",&a,&b,&c);
        if ((a <= b+c) && (b <= a+c) && (c <= a+b))
        {
               p = (a+b+c)/2;
               s = sqrt(p*(p-a)*(p-b)*(p-c));
               printf("S(%.0lf,%.0lf,%.0lf)=%.2lf\n",a,b,c,s);
        }
        else
               printf("(%.0lf,%.0lf,%.0lf) can't construct a triangle!\n",a,b,c);
    }
    return 0;
}
    
