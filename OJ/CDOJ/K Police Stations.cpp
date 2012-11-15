#include <stdio.h>
int main()
{
    int n,m,k;
    int t;
    scanf("%d",&t);
    for (int ii=1;ii<=t;ii++)
    {
        scanf("%d%d%d",&n,&m,&k);
        int num1,num2;
        if (k>=n) num1=0;
        else
        {
            num1=(n-1)/(2*k);
            if ((n-1)%(2*k)!=0) num1++;
        }
        if (k>=m) num2=0;
        else
        {
            num2=(m-1)/(2*k);
            if ((m-1)%(2*k)!=0) num2++;
        }
        printf("Case #%d: %d\n",ii,num1>num2?num1:num2);
    }
    return 0;
}
