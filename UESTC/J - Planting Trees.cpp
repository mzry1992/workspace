#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n,m;

int main()
{
    scanf("%d%d",&n,&m);
    if (n == 2 && m == 2)   printf("-1\n");
    else if (n == 1)
    {
        if (m < 5)  printf("-1\n");
        else
        {
            for (int i = 1;i <= m;i += 2)
                printf("%d\n",i);
            for (int i = 2;i <= m;i += 2)
                printf("%d\n",i);
        }
    }
    else if (m == 1)
    {
        if (n < 5)  printf("-1\n");
        else
        {
            for (int i = 1;i <= n;i += 2)   printf("%d ",i);
            for (int i = 2;i <= n;i += 2)   printf("%d ",i);
            printf("\n");
        }
    }
    else
    {
        for (int i = 1;i <= n;i++)
            if (i%2 == 1)
            {
                for (int j = i;j <= n*m;j += n)
                    printf("%d ",j);
                printf("\n");
            }
            else
            {
                for (int j = i+n;j <= n*m;j += n)
                    printf("%d ",j);
                printf("%d\n",i);
            }
    }
}
