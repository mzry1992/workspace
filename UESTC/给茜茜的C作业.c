#include <stdio.h>

int x;

int main()
{
    while (scanf("%d",&x) != EOF)
    {
        printf("%d %d\n",x == 0?0:1,x%2);
    }
}
