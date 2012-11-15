#include <cstdio>
#include<cstring>

bool flag[1000000];

int main()
{
    int t;
    scanf("%d",&t);
    while (t--)
    {
        int n;
        scanf("%d",&n);
        memset(flag,0,n);
        int tot2=0,tot5=0;
        for (;n%2 == 0;n/=2)
            tot2++;
        for (;n%5 == 0;n/=5)
            tot5++;
        long long i;
        int tot=1;
        for (i=123456789%n;i && !flag[i];i=(i*1000000000+123456789)%n,tot++)
            flag[i]=1;
        if (i)
            puts("-1");
        else
        {
            for (int i = 0;i < tot;i++)
                printf("123456789");
            if (tot2 < tot5)    tot2 = tot5;
            for (int i = 0;i < tot2;i++)
                printf("0");
            printf("\n");
        }
    }
    return 0;
}
