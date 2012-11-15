#include <stdio.h>

int main()
{
    int t,ft;
    int n,i,j,l;
    char ch;
    scanf("%d",&t);
    for (ft = 0;ft < t;ft++)
    {
        scanf("%d %c",&n,&ch);
        l = 1;
        for (i = 1;i <= n;i++)
        {
            for (j = n-i;j > 0;j--)          printf(" ");
            for (j = 1;j <= l;j++)   printf("%c",ch);
            printf("\n");
            l += 2;
        }
        l -= 4;
        for (i = 1;i <= n-1;i++)
        {
            for (j = 1;j <= i;j++) printf(" ");
            for (j = 1;j <= l;j++)             printf("%c",ch);
            printf("\n");
            l -= 2;
        }
    }
    return 0;
}
