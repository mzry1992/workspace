#include <stdio.h>
#define PI 3.1415926535898
        

int main()
{
    double a,result;
    long b;
    while (scanf("%lf %ld",&a,&b) == 2)
    {
          result = 2*PI*a*b;
          printf("%.4lf\n",result);
    }
    return 0;
}
          
