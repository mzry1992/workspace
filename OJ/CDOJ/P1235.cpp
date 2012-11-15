#include <stdio.h>

int gcd(int a,int b)
{
    if (a % b == 0) 
        return b;
    else
        return gcd(b,a % b);
}

int main()
{
    int t,i,a,b,c,d;
    scanf("%d",&t);
    for (i = 0;i < t;i++)
    {
        scanf("%d %d",&a,&b);
        c = gcd(a,b);
        d = a*b/c;
        printf("%d %d\n",c,d);
    }
    return 0;
}
    
