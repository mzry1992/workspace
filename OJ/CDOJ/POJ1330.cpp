#include <stdio.h>

long n,temp,ans;

int main()
{
    ans = 0;
    scanf("%ld",&n);
    for (int i = 1;i <= 2*n-1;i++)
    {
        scanf("%ld",&temp);
        ans = ans^temp;
    }
    printf("%ld\n",ans);
    //getchar();
    //getchar();
    return 0;
}
