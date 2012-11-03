#include <stdio.h>

int a[100],top;

int main()
{
    top = 0;
    int tmp;
    while (1)
    {
        scanf("%d",&tmp);
        if (tmp == 0)   break;
        if (tmp == -1)
            printf("%d\n",a[--top]);
        else
            a[top++] = tmp;
        printf("stack = [");
        for (tmp = 0;tmp < top;tmp++)
            printf("%3d",a[tmp]);
        printf("]\n");
    }
    return 0;
}
