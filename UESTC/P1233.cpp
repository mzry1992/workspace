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
    long a,b,c,result;
    scanf("%ld %ld %ld",&a,&b,&c);
    while (!((a == 0) && (b == 0) && (c == 0)))
    {
        if (a > b) swap(&a,&b);
        if (b > c) swap(&b,&c);
        if (a > b) swap(&a,&b);
        (a != b)? result = b : result = c ;
        printf("%ld\n",result);
        scanf("%ld %ld %ld",&a,&b,&c);
    }
    return 0;
}
    
