#include <stdio.h>

int hasres,a[4];

void calc(int now,int sum,int mult,int last)
{
    int i;
    if (hasres == 1)    return;
    if (now == 4)
    {
        if (sum == mult)
        {
            for (i = 0;i < 4;i++)
                printf("%d ",a[i]);
            printf("\n");
            hasres = 1;
        }
        return;
    }
    for (i = last;i <= 1000;i++)
    {
        a[now] = i;
        calc(now+1,sum+i,mult*i,i);
    }
}

int main()
{
    hasres = 0;
    calc(0,0,1,1);
    return 0;
}
