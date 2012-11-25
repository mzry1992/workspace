#include<cstdio>
int fac[100];
int L;
void getFactor(int x)
{
    L=0;
    for (int i=2;i*i<=x;i++)
        if (x%i==0)
        {
            fac[L]=1;
            while (x%i==0)
            {
                x/=i;
                fac[L]*=i;
            }
            L++;
        }
    if (x>1)
        fac[L++]=x;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int a,c;
        scanf("%d%d",&a,&c);
        if (c%a)
        {
            puts("NO SOLUTION");
            continue;
        }
        getFactor(c);
        int ans=1;
        for (int i=0;i<L;i++)
            if (a%fac[i])
                ans*=fac[i];
        printf("%d\n",ans);
    }
    return 0;
}
