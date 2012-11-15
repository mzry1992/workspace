#include <stdio.h>
#include <string.h>

int main()
{
    int t,ft,l,i,tot1,tot2;
    char num[200];
    scanf("%d",&t);
    for (ft = 0;ft < t;ft++)
    {
        scanf("%s",&num);
        l = strlen(num);
        tot1 = 0;
        tot2 = 0;
        for (i = 0;i < l;i++)   
        if (i % 2 == 0)
            tot1 += (int)num[i]-(int)'0';
        else
            tot2 += (int)num[i]-(int)'0';
        ((tot1+tot2) % 3 == 0) ? printf("yes ") : printf("no ");
        ((tot1-tot2) % 11 == 0) ? printf("yes\n") : printf("no\n");
    }
    getchar();
    getchar();
    return 0; 
}       
