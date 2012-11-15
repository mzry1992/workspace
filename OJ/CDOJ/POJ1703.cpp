#include <stdio.h>

int t,ft,a,b,n,m,i,f[200000];
char ch;

int findf(int x)
{
    if (f[x] != x) f[x] = findf(f[x]);
    return f[x];
}

int main()
{
    scanf("%d",&t);
    for (ft = 1;ft <= t;ft++)
    {
        scanf("%d %d",&n,&m);
        for (i = 1;i <= n*2;i++)
            f[i] = i;
        for (i = 1;i <= m;i++)
        {
            scanf("\n%c %d %d",&ch,&a,&b);
            if (ch == 'D')
            {
                   f[findf(a)] = f[findf(b+n)];
                   f[findf(b)] = f[findf(a+n)];
            }
            if (ch == 'A')
            {
                   if (findf(a) == findf(b)) 
                      printf("In the same gang.\n");
                   else
                   {
                       if (findf(a) == findf(b+n))
                          printf("In different gangs.\n");
                       else
                           printf("Not sure yet.\n");
                   }
            }
        }
    }
    return 0;
}
            

                   
                           
            
            
