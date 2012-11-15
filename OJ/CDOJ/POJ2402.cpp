// POJ2402   

#include <stdio.h>

int i, j, num ;

int main()
{
    scanf("%d",&num);
    while (num != 0)
    {
        i = 9 ;
        j = 1 ;
        while (num > 2*i)
        {
            num -= 2*i ;
            i   *= 10 ;
            j   *= 10  ;
        }
        printf("%d %d %d\n",num,i,j);
        j += (num%i==0 ? i : num%i)-1;
        printf("%d\n",j);
        if (num-i <= 0)
            j /= 10;
        while (j != 0)
        {
            printf("%d",j%10);
            j /= 10;
        }
        printf("\n") ;
        scanf("%d",&num);
    }
    return 0 ;
}
