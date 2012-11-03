#include <stdio.h>

int game[100],i,n,ans;

int main()
{
    while (scanf("%d",&n) == 1)
    {
        for (i = 1;i <= n;i++)
             scanf("%d",&game[i]);
        ans = game[1];
        for (i = 2;i <= n;i++)
            ans = ans^game[i];
        if (ans == 0)
           printf("No\n");
        else
            printf("Yes\n");
    }
    return 0;
}
