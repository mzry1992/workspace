#include <stdio.h>
#include <math.h>

int main()
{
    int t,i,n,j;
    float now,pre,result;
    scanf("%d",&t);
    for (i = 0;i < t;i++)
    {
        scanf("%d %f",&n,&pre);
        result = 19921005;
        for (j = 1;j < n;j++)
        {
            scanf("%f",&now);
            if (fabs(now-pre) < fabs(result))  result = now-pre;
            pre = now;
        }
        printf("%.2f\n",result);
    }
    return 0;
}
            
            
