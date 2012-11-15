#include<stdio.h>

float x[205],y[205];
int n,ans,temp,i,j,k;

int main()
{
    while (scanf("%d",&n) != EOF)
    {
        for (i = 1;i <= n;i++) scanf("%f%f",&x[i],&y[i]);
        ans = 0;
        for (i = 1;i < n;i++)
        for (j = i+1;j <= n;j++)
        {
                temp = 2;
                for (k = 1;k <= n;k++)
                if ((k != i) && (k != j) && (y[i]-y[j])*(x[k]-x[j])==(y[k]-y[j])*(x[i]-x[j]))
                        temp++;
                if (ans < temp) ans=temp;
        }
        printf("%d\n",ans);
    }
    return 0;
}
