#include <cstdio>
int f[10001],g[10001];
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%d",&f[i]);
    g[1]=1;
    for (int i=2;i<=n;i++)
    {
        g[i]=-f[i];
        for (int j=2;j*j<=i;j++)
            if (i%j==0)
            {
                g[i]-=f[j]*g[i/j];
                if (j*j<i)
                    g[i]-=f[i/j]*g[j];
            }
        g[i]=(g[i]%2007+2007)%2007;
    }
    putchar('1');
    for (int i=2;i<=n;i++)
        printf(" %d",g[i]);
    puts("");
    return 0;
}
