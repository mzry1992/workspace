#include <stdio.h>

void swap(long *a,long *b)
{
     long t;
     t = *a;
     *a = *b;
     *b = t;
}

int main()
{
    int t,i;
    long a,b,c,result;
    scanf("%d",&t);
    for (i = 0;i < t;i++)
    {
        scanf("%ld %ld %ld",&a,&b,&c);
        if (a > b) swap(&a,&b);
        if (b > c) swap(&b,&c);
        if (a > b) swap(&a,&b);
        (a != b)? result = b : result = c ;
        printf("%ld\n",result);
    }
    return 0;
}
    
