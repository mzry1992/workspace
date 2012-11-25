#include<cstdio>
int main()
{
    int t;
    scanf("%d",&t);
    while (t--)
    {
        int n;
        scanf("%d",&n);
        int tot1=0,tot2=0;
        for (int i=0;i<n;i++)
        {
            int x;
            scanf("%d",&x);
            if (x>1)
                tot2++;
            else
                tot1++;
        }
        if (!tot2)
            if (tot1&1)
                puts("poopi");
            else
                puts("piloop");
        else
            puts("poopi");
    }
    return 0;
}
