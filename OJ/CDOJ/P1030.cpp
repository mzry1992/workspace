#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    int t,i,j,l,sum,flag;
    char now[255];
    scanf("%d\n",&t);
    for (i = 0;i < t;i++)
    {
        gets(now);
        sum = 0;
        flag = 0;
        l = strlen(now);
        for (j = 0;j < l;j++)
        {
            if (isalpha(now[j]) != 0)
            {
               if (flag == 0)   
               {
                        sum += 1;
                        flag = 1;
               }
            }
            else
                if (flag == 1) flag = 0;
        }
        printf("%d\n",sum);
    }
    getchar();
    return 0;
}
        
        
            
